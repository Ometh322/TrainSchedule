#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Windows.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <random>

using namespace sf;
using namespace std;



#include "ElectPoezd.h" //подключаем файл с описанием классов
//объявляем глобальные переменные
int numbTrains;
int numbStations;
vector<ElPoezd> Trains(20);
vector<Station> Stancii(20);

#include "MainMenu.h"//подключаем файл с описанием главного меню


int main() {
	int  stime;
	long ltime;
	ltime = time(NULL);
	stime = (unsigned int)ltime / 2;
	srand(stime);

	setlocale(LC_ALL, "Russian");
	RenderWindow windowMenu(VideoMode(1368, 738), "Train schedule"); //название окна меню и его разрешение
	Menu(windowMenu); //вызов меню
	RenderWindow windowProcces(VideoMode(1920, 1080), "Train schedule"); //название окна самого процесса и его разрешение
	RenderWindow windowStat(VideoMode(1920, 1080), "Statistic");
	Image NutImage;
	Texture NutTexture;
	Sprite NutSprite;

	Font font;
	font.loadFromFile("shrift/Stiff_Staff.otf");

	Font capture;
	capture.loadFromFile("shrift/capture.ttf");

	Texture trainTextureModelRight;
	trainTextureModelRight.loadFromFile("images/trainModel3Right.png");
	/*Sprite trainSpriteModelRight;
	trainSpriteModelRight.setTexture(trainTextureModelRight);
	trainSpriteModelRight.setPosition(0, 0);
	trainSpriteModelRight.setScale(0.1, 0.1);*/

	Texture trainTextureModelLeft;
	trainTextureModelLeft.loadFromFile("images/trainModelLeft.png");
	/*Sprite trainSpriteModelLeft;
	trainSpriteModelLeft.setTexture(trainTextureModelRLeft);
	trainSpriteModelLeft.setPosition(0, 0);
	trainSpriteModelLeft.setScale(0.1, 0.1);*/

	vector<Sprite> trainSprite(numbTrains);

	


	//trainSprite[0].setPosition(50, 675);
	//trainSprite[0].setScale(0.05, 0.05);

	/*trainSprite[0].setPosition(1765, 475);
	trainSprite[0].setScale(0.05, 0.05);*/
	//описывание фигур для основного окна
	RectangleShape lineOne(Vector2f(1920, 5));
	lineOne.setPosition(0, 500);
	lineOne.setFillColor(Color::Black);

	RectangleShape lineTwo(Vector2f(1920, 5));
	lineTwo.setPosition(0, 700);
	lineTwo.setFillColor(Color::Black);

	RectangleShape timeLineDown(Vector2f(140, 2));
	timeLineDown.setPosition(1600, 140);
	timeLineDown.setFillColor(Color::Black);

	RectangleShape timeLineUp(Vector2f(140, 2));
	timeLineUp.setPosition(1600, 90);
	timeLineUp.setFillColor(Color::Black);

	RectangleShape timeLineLeft(Vector2f(52, 2));
	timeLineLeft.rotate(90);
	timeLineLeft.setPosition(1600, 90);
	timeLineLeft.setFillColor(Color::Black);

	RectangleShape timeLineRight(Vector2f(52, 2));
	timeLineRight.rotate(90);
	timeLineRight.setPosition(1740, 90);
	timeLineRight.setFillColor(Color::Black);

	CircleShape circleStations[20];
	for (int i = 0; i < 20; i++)
	{
		circleStations[i].setRadius(10);
		circleStations[i].setPosition(50 + 90 * i, 600);
		circleStations[i].setFillColor(Color::Black);
	}


	//описание фигур для окна статистики
	RectangleShape  linesStaticHorizon[22];
	for (int i = 0; i < 22; i++)
	{
		linesStaticHorizon[i] = RectangleShape(Vector2f(1520, 2));
		linesStaticHorizon[i].setPosition(200, 100 + i * 38);
		linesStaticHorizon[i].setFillColor(Color::Black);
	}

	RectangleShape linesStaticVert[6];
	for (int i = 0; i < 6; i++)
	{
		linesStaticVert[i] = RectangleShape(Vector2f(800, 2));
		linesStaticVert[i].setFillColor(Color::Black);
		linesStaticVert[i].rotate(90);
		linesStaticVert[i].setPosition(200 + 304 * i, 100);
	}
	Text labelStat = Text(L"СТАТИСТИКА", capture, 28);
	labelStat.setPosition(760, 72);
	labelStat.setFillColor(Color::Red);

	

	//описываем время
	Clock clock;
	Clock clockTimer;
	
	//Сlock clockStops[2];

	vector<Clock> clockStops(numbTrains);

	//описание вывода станций
	Text NameStation[20];
	NameStation[0] = Text(L"Марьино", capture, 14);
	NameStation[1] = Text(L"Блиново", capture, 14);
	NameStation[2] = Text(L"Иваново", capture, 14);
	NameStation[3] = Text(L"Владимирская", capture, 14);
	NameStation[4] = Text(L"Студзянки", capture, 14);
	NameStation[5] = Text(L"Ижгород", capture, 14);
	NameStation[6] = Text(L"Кривая", capture, 14);
	NameStation[7] = Text(L"Широкая", capture, 14);
	NameStation[8] = Text(L"Катериновск", capture, 14);
	NameStation[9] = Text(L"Купчино", capture, 14);
	NameStation[10] = Text(L"Васькино", capture, 14);
	NameStation[11] = Text(L"Акчуринск", capture, 14);
	NameStation[12] = Text(L"Козельск", capture, 14);
	NameStation[13] = Text(L"Шорохово", capture, 14);
	NameStation[14] = Text(L"Новиград", capture, 14);
	NameStation[15] = Text(L"Сабуровка", capture, 14);
	NameStation[16] = Text(L"Меминова", capture, 14);
	NameStation[17] = Text(L"Кековская", capture, 14);
	NameStation[18] = Text(L"Починки", capture, 14);
	NameStation[19] = Text(L"1337 км", capture, 14);

	int koefHeight = 1; //коэфициент, отвечающий за расположение названия станции по вертикали
	//int koefWidth = 5; //коэфициент, отвечающий за расположение названия станции по горизонтали

	for (int i = 0; i < 20; i++)
	{
		NameStation[i].setFillColor(Color::Red);
		NameStation[i].setPosition(50 + 90 * i, 600 + 50 * koefHeight);
		koefHeight = koefHeight * -1;

	}
	vector<int> indexSt(numbTrains);
	vector<int> hourEndPrognose(numbTrains);
	vector<int> minEndPrognose(numbTrains);

	vector<Text> labelNumbTrains(numbTrains);
	vector<Text> labelStartHour(numbTrains);
	vector<Text> labelStartMin(numbTrains);
	vector<Text> labelDvoetStart(numbTrains);
	vector<Text> labelEndHour(numbTrains);
	vector<Text> labelEndMin(numbTrains);
	vector<Text> labelDvoetEnd(numbTrains);
	vector<Text> labelEndHourReal(numbTrains);
	vector<Text> labelEndMinReal(numbTrains);
	vector<Text> labelDvoetEndReal(numbTrains);
	vector<Text> labelDeltaHourEnd(numbTrains);
	vector<Text> labelDeltaMinEnd(numbTrains);
	vector<Text> labelDvoetDelta(numbTrains);

	for (int i = 0; i < numbTrains; i++)
	{
		labelNumbTrains[i] = Text("", capture, 28);
		labelStartHour[i] = Text("", capture, 28);
		labelStartMin[i] = Text("", capture, 28);
		labelDvoetStart[i] = Text(":", capture, 28);
		labelEndHour[i] = Text("", capture, 28);
		labelEndMin[i] = Text("", capture, 28);
		labelDvoetEnd[i] = Text(":", capture, 28);
		labelEndHourReal[i] = Text("", capture, 28);
		labelEndMinReal[i] = Text("", capture, 28);
		labelDvoetEndReal[i] = Text(":", capture, 28);
		labelDeltaHourEnd[i] = Text("", capture, 28);
		labelDeltaMinEnd[i] = Text("", capture, 28);
		labelDvoetDelta[i] = Text(":", capture, 28);
	}
	for (int i = 0; i < trainSprite.size(); i++)
	{
		if (Trains[i].getNumbStartSt() > Trains[i].getNumbEndSt())
		{
			//trainSprite[i].setPosition(1765, 475);
			
			trainSprite[i].setPosition(NameStation[Trains[i].getNumbStartSt()].getPosition().x , 475);
		}
		else
		{
			//trainSprite[i].setPosition(50, 675);
			trainSprite[i].setPosition(NameStation[Trains[i].getNumbStartSt()].getPosition().x - 50, 675);
		}
		trainSprite[i].setScale(0.05, 0.05);
		indexSt[i] = Trains[i].getNumbStartSt();
		//для статистики
		if (Trains[i].getHourStart() >= 10)
			labelStartHour[i].setString(to_string(Trains[i].getHourStart()));
		else
			labelStartHour[i].setString("0" + to_string(Trains[i].getHourStart()));
		if (Trains[i].getMinStart() >= 10)
			labelStartMin[i].setString(to_string(Trains[i].getMinStart()));
		else
			labelStartMin[i].setString("0" + to_string(Trains[i].getMinStart()));
		if (Trains[i].getHourEnd() >= 10)
			labelEndHour[i].setString(to_string(Trains[i].getHourEnd()));
		else
			labelEndHour[i].setString("0" + to_string(Trains[i].getHourEnd()));
		if (Trains[i].getMinEnd() >= 10)
			labelEndMin[i].setString(to_string(Trains[i].getMinEnd()));
		else
			labelEndMin[i].setString("0" + to_string(Trains[i].getMinEnd()));
		labelNumbTrains[i].setString(to_string(i + 1));
		hourEndPrognose[i] = Trains[i].getHourEnd();
		minEndPrognose[i] = Trains[i].getMinEnd();
	}
	//для статистики
	Text labelNumbOfTrain = Text(L"Номер поезда", capture, 14);
	labelNumbOfTrain.setFillColor(Color::Black);
	labelNumbOfTrain.setPosition(250, 112);

	Text labelStartTime = Text(L"Время начала движения", capture, 14);
	labelStartTime.setFillColor(Color::Black);
	labelStartTime.setPosition(550, 112);

	Text labelEndTime = Text(L"Примерное время проезда", capture, 14);
	labelEndTime.setFillColor(Color::Black);
	labelEndTime.setPosition(850, 112);

	Text labelEndRealTime = Text(L"Реальное время проезда", capture, 14);
	labelEndRealTime.setFillColor(Color::Black);
	labelEndRealTime.setPosition(1150, 112);

	Text labelDeltaTime = Text(L"Отставание от графика", capture, 14);
	labelDeltaTime.setFillColor(Color::Black);
	labelDeltaTime.setPosition(1450, 112);




	//вывод времени на экран
	Text labelTimeMin = Text("", capture, 28);
	labelTimeMin.setPosition(1700, 100);
	labelTimeMin.setFillColor(Color::Red);

	Text labelTimeColon = Text(":", font, 28);
	labelTimeColon.setPosition(1670, 100);
	labelTimeColon.setFillColor(Color::Black);

	Text labelTimeHour = Text("", capture, 28);
	labelTimeHour.setPosition(1610, 100);
	labelTimeHour.setFillColor(Color::Red);

	
	float timeOutFloat = 0;
	int timeOutInt = 0, timeOutHour = 0;

	//описание вероятностых переменных
	//int timeBetweenAccident; //время между авариями поезда 
	//int timeRepairLower = 30; //нижняя граница времени для починки (в минутах)
	//int timeRepairUpper = 120; //верхняя граница времени для починки (в минутах)
	//int chanceToBroke = 10; //шанс сломаться - 10 процентов


	int chanceToDelay = 20; //шанс задержаться на станции - 20 процентов
	int timeDelayLower = 2; //время задержки на станции минимальное в минутах
	int timeDelayUpper = 5; //время задержки на станции максимальное в минутах

	
	int timePlusDelay = 0;
	//описание переменной скорости
	float speedRight = 0.008175, speedLeft = -0.008175;
	//float speedRight = 0, speedLeft = 0;







	while (windowProcces.isOpen())
	{
		Event event;

		while (windowProcces.pollEvent(event))
		{
			if (event.type == Event::Closed)
				windowProcces.close();
		}

		Event event2;
		while (windowStat.pollEvent(event2))
		{
			if (event.type = Event::Closed)
				windowStat.close();
		}

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 500;
		timeOutFloat += (time / 1000);
		timeOutInt = (int)timeOutFloat;
		if (timeOutInt == 60)
		{
			timeOutFloat = 0;
			timeOutInt -= 60;
			timeOutHour++;
		}

		if (timeOutHour >= 24)
			timeOutHour -= 24;

		if (timeOutInt < 10)
			labelTimeMin.setString("0" + to_string(timeOutInt));
		if (timeOutInt >= 10)
			labelTimeMin.setString(to_string(timeOutInt));
		if (timeOutHour < 10)
			labelTimeHour.setString("0" + to_string(timeOutHour));
		if (timeOutHour >= 10)
			labelTimeHour.setString(to_string(timeOutHour));

		

		for (int i = 0; i < trainSprite.size(); i++)
		{
			if ((Trains[i].getHourStart() * 60 + Trains[i].getMinStart()) <= (timeOutHour * 60 + timeOutInt))
			{
				if (Trains[i].getNumbStartSt() > Trains[i].getNumbEndSt())
				{
					if ((Trains[i].getHourEnd() * 60 + Trains[i].getMinEnd()) >= (timeOutHour * 60 + timeOutInt))
					{
						if ((int(trainSprite[i].getPosition().x) == int(NameStation[indexSt[i]].getPosition().x)) && indexSt[i] >= Trains[i].getNumbEndSt() && (Trains[i].getSomeTimeStop(indexSt[i])> 0))
						{
							if (Trains[i].clockTrain.getElapsedTime().asMilliseconds() >= 499)
							{
								Trains[i].setSomeTimeStops(Trains[i].getSomeTimeStop(indexSt[i]) - 1, indexSt[i]);
								Trains[i].clockTrain.restart();
							}
							speedLeft = 0;
						}
						else if (Trains[i].getSomeTimeStop(indexSt[i]) <= 0)
						{
							indexSt[i]--;
							int isDelayNow = rand() % (100 / chanceToDelay);
							if (isDelayNow == 1 && indexSt[i] > Trains[i].getNumbEndSt())
							{
								timePlusDelay = rand() % (timeDelayUpper - timeDelayLower) + timeDelayLower;
								int newHourEnd = Trains[i].getHourEnd();
								int newMinEnd = Trains[i].getMinEnd() + newHourEnd * 60 + timePlusDelay;
								newHourEnd = newMinEnd / 60;
								newMinEnd = newMinEnd - newHourEnd * 60;
								Trains[i].setHourEnd(newHourEnd);
								Trains[i].setMinEnd(newMinEnd);
								Trains[i].setSomeTimeStops(Trains[i].getSomeTimeStop(indexSt[i]) + timePlusDelay, indexSt[i]);
								timePlusDelay = 0;
							}
							speedLeft = -0.008175;
						}

						trainSprite[i].setTexture(trainTextureModelLeft);
						trainSprite[i].move(speedLeft * time, 0);
						windowProcces.draw(trainSprite[i]);
					}

					else
					{
						trainSprite[i].setPosition(1920, 1080);
					}
				}
				else
				{
					if ((Trains[i].getHourEnd() * 60 + Trains[i].getMinEnd()) >= (timeOutHour * 60 + timeOutInt))
					{
						if (((int(trainSprite[i].getPosition().x) + 50) == int(NameStation[indexSt[i]].getPosition().x)) && indexSt[i] <= Trains[i].getNumbEndSt() && Trains[i].getSomeTimeStop(indexSt[i]) > 0)
						{
							if (Trains[i].clockTrain.getElapsedTime().asMilliseconds() >= 499)
							{
								Trains[i].setSomeTimeStops(Trains[i].getSomeTimeStop(indexSt[i]) - 1, indexSt[i]);
								Trains[i].clockTrain.restart();
							}
							speedRight = 0;
						}
						else if (Trains[i].getSomeTimeStop(indexSt[i]) <= 0)
						{
							speedRight = 0.008175;
							indexSt[i]++;
							int isDelayNow = rand() % (100 / chanceToDelay);
							if (isDelayNow == 1 && indexSt[i] < Trains[i].getNumbEndSt())
							{
								timePlusDelay = rand() % (timeDelayUpper - timeDelayLower) + timeDelayLower;
								int newHourEnd = Trains[i].getHourEnd();
								int newMinEnd = Trains[i].getMinEnd() + newHourEnd * 60 + timePlusDelay;
								newHourEnd = newMinEnd / 60;
								newMinEnd = newMinEnd - newHourEnd * 60;
								Trains[i].setHourEnd(newHourEnd);
								Trains[i].setMinEnd(newMinEnd);
								Trains[i].setSomeTimeStops(Trains[i].getSomeTimeStop(indexSt[i]) + timePlusDelay, indexSt[i]);
								timePlusDelay = 0;
							}
						}
						trainSprite[i].move(speedRight * time, 0);
						trainSprite[i].setTexture(trainTextureModelRight);
						windowProcces.draw(trainSprite[i]);
					}
					else
					{
						trainSprite[i].setPosition(1920, 1080);
					}
				}
			}
			

		}

		//описание вывода дисплея статистики
		windowStat.clear(Color(163, 198, 192));
		for (int i = 0; i < 22; i++)
			windowStat.draw(linesStaticHorizon[i]);

		for (int i = 0; i < 6; i++)
			windowStat.draw(linesStaticVert[i]);
		windowStat.draw(labelStat);
		windowStat.draw(labelNumbOfTrain);
		windowStat.draw(labelStartTime);
		windowStat.draw(labelEndTime);
		windowStat.draw(labelEndRealTime);
		windowStat.draw(labelDeltaTime);

		for (int i = 0; i < numbTrains; i++)
		{
			labelNumbTrains[i].setFillColor(Color::Red);
			labelNumbTrains[i].setPosition(250, 145 + 40 * i);
			windowStat.draw(labelNumbTrains[i]);

			labelStartHour[i].setFillColor(Color::Red);
			labelStartHour[i].setPosition(550, 145 + 40 * i);
			windowStat.draw(labelStartHour[i]);

			labelDvoetStart[i].setFillColor(Color::Black);
			labelDvoetStart[i].setPosition(592, 145 + 40 * i);
			windowStat.draw(labelDvoetStart[i]);

			labelStartMin[i].setFillColor(Color::Red);
			labelStartMin[i].setPosition(606, 145 + 40 * i);
			windowStat.draw(labelStartMin[i]);

			labelEndHour[i].setFillColor(Color::Red);
			labelEndHour[i].setPosition(850, 145 + 40 * i);
			windowStat.draw(labelEndHour[i]);

			labelDvoetEnd[i].setFillColor(Color::Black);
			labelDvoetEnd[i].setPosition(892, 145 + 40 * i);
			windowStat.draw(labelDvoetEnd[i]);

			labelEndMin[i].setFillColor(Color::Red);
			labelEndMin[i].setPosition(906, 145 + 40 * i);
			windowStat.draw(labelEndMin[i]);


			if (Trains[i].getHourEnd() >= 10)
				labelEndHourReal[i].setString(to_string(Trains[i].getHourEnd()));
			else
				labelEndHourReal[i].setString("0" + to_string(Trains[i].getHourEnd()));
			if (Trains[i].getMinEnd() >= 10)
				labelEndMinReal[i].setString(to_string(Trains[i].getMinEnd()));
			else
				labelEndMinReal[i].setString("0" + to_string(Trains[i].getMinEnd()));
			labelEndHourReal[i].setFillColor(Color::Red);
			labelEndHourReal[i].setPosition(1150, 145 + 40 * i);
			windowStat.draw(labelEndHourReal[i]);

			labelDvoetEndReal[i].setFillColor(Color::Black);
			labelDvoetEndReal[i].setPosition(1192, 145 + 40 * i);
			windowStat.draw(labelDvoetEndReal[i]);

			labelEndMinReal[i].setFillColor(Color::Red);
			labelEndMinReal[i].setPosition(1206, 145 + 40 * i);
			windowStat.draw(labelEndMinReal[i]);

			int hourDelta = Trains[i].getHourEnd() - hourEndPrognose[i];
			int minDelta = Trains[i].getMinEnd() - minEndPrognose[i];

			if (hourDelta >= 10)
				labelDeltaHourEnd[i].setString(to_string(hourDelta));
			else
				labelDeltaHourEnd[i].setString("0" + to_string(hourDelta));
			if (minDelta >= 10)
				labelDeltaMinEnd[i].setString(to_string(minDelta));
			else
				labelDeltaMinEnd[i].setString("0" + to_string(minDelta));
			labelDeltaHourEnd[i].setFillColor(Color::Red);
			labelDeltaHourEnd[i].setPosition(1450, 145 + 40 * i);
			windowStat.draw(labelDeltaHourEnd[i]);

			labelDvoetDelta[i].setFillColor(Color::Black);
			labelDvoetDelta[i].setPosition(1492, 145 + 40 * i);
			windowStat.draw(labelDvoetDelta[i]);

			labelDeltaMinEnd[i].setFillColor(Color::Red);
			labelDeltaMinEnd[i].setPosition(1506, 145 + 40 * i);
			windowStat.draw(labelDeltaMinEnd[i]);

		}

		windowStat.display();


		//описание вывода основного дисплея
		windowProcces.clear(Color(163, 198, 192));
		windowProcces.draw(NutSprite);

		windowProcces.draw(lineOne);
		windowProcces.draw(lineTwo);
		windowProcces.draw(timeLineDown);
		windowProcces.draw(timeLineUp);
		windowProcces.draw(timeLineLeft);
		windowProcces.draw(timeLineRight);

		for (int i = 0; i < 20; i++)
			if (Stancii[i].getIsIncluded())
				windowProcces.draw(NameStation[i]);

		for (int i = 0; i < 20; i++)
			windowProcces.draw(circleStations[i]);

		for (int i = 0; i < trainSprite.size(); i ++)
			windowProcces.draw(trainSprite[i]);

		windowProcces.draw(labelTimeMin);
		windowProcces.draw(labelTimeColon);
		windowProcces.draw(labelTimeHour);
		windowProcces.display();
	}
	return 0;
}