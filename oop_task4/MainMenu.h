#pragma once
void Menu(RenderWindow & window)//������� ������ ����
{
	//�����
	//SoundBuffer menuSound;
	//menuSound.loadFromFile("sounds/gta.ogg");
	//Sound sound;
	//sound.setBuffer(menuSound);

	//��� ������ ���������� 400 * 39, ����� = stiff_staff
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground, labelSt, labelTr, btnPlusSt, btnMinusSt, btnPlusTR, btnMinusTr, labelChooseTr, labelChooseSt;
	Texture textureMenuTrain, textureMenuStation, textureMenuStationBack, labelMainMenu, labelStInfo, labelTrInfo, textrureMenuExit;

	menuTexture1.loadFromFile("images/StBttn.png");
	menuBackground.loadFromFile("images/TrainFon.jpg");
	labelSt.loadFromFile("images/LabelSt.png");
	labelTr.loadFromFile("images/LabelTr.png");
	btnPlusSt.loadFromFile("images/BttnPlus.png");
	btnMinusSt.loadFromFile("images/BttnMinus.png");
	btnPlusTR.loadFromFile("images/BttnPlus.png");
	btnMinusTr.loadFromFile("images/BttnMinus.png");
	labelChooseSt.loadFromFile("images/LabelChooseSt.png");
	labelChooseTr.loadFromFile("images/LabelChooseTr.png");
	textureMenuStation.loadFromFile("images/StationMenu.jpg");
	textureMenuStationBack.loadFromFile("images/st_backToMenu.png");
	textureMenuTrain.loadFromFile("images/TrainMenu.jpg");
	labelMainMenu.loadFromFile("images/mainMenu.png");
	labelTrInfo.loadFromFile("images/tr_Info.png");
	textrureMenuExit.loadFromFile("images/MenuExit.png");

	Sprite menu1(menuTexture1), menuBG(menuBackground), labelMenu1(labelSt), labelMenu2(labelTr), menuPlusSt(btnPlusTR), menuMinusSt(btnMinusTr), menuPlusTr(btnPlusTR), menuMinusTr(btnMinusTr);
	Sprite spriteChooseSt(labelChooseSt), spriteChooseTr(labelChooseTr), spriteMenuStation(textureMenuStation), spriteMenuStationBack(textureMenuStationBack), spriteMenuTrain(textureMenuTrain);
	Sprite spriteMainMenu(labelMainMenu), spriteTrInfo(labelTrInfo), spriteMenuExit(textrureMenuExit);

	bool saveInf = false;
	bool isMenu = true;
	int menuNum = 0;


	spriteMainMenu.setPosition(484, 15);
	labelMenu1.setPosition(0, 50);
	labelMenu2.setPosition(0, 90);
	spriteChooseSt.setPosition(0, 130);
	spriteChooseTr.setPosition(0, 170);
	menuBG.setPosition(0, 0);
	spriteMenuStation.setPosition(0, 0);
	spriteMenuTrain.setPosition(0, 0);
	spriteMenuStationBack.setPosition(484, 680);
	spriteTrInfo.setPosition(484, 10);
	spriteMenuExit.setPosition(484, 680);

	//////�������� ������ ���������� ������� � ������� � ����////
	Font font;
	font.loadFromFile("shrift/Stiff_Staff.otf");

	Font capture;
	capture.loadFromFile("shrift/capture.ttf");

	Text menuSaveAll = Text(L"��������� ����������", font, 24);
	menuSaveAll.setFillColor(Color::Green);
	menuSaveAll.setPosition(700, 350);

	Text outputNumbStations("", font, 27);
	Text outputNumbTrains("", font, 27);
	Text coutNumbStations("", font, 24);
	outputNumbStations.setStyle(Text::Bold);
	outputNumbTrains.setStyle(Text::Bold);
	outputNumbStations.setPosition(401, 50);
	outputNumbTrains.setPosition(401, 90);

	menuPlusSt.setPosition(440, 50);
	menuMinusSt.setPosition(480, 50);
	menuPlusTr.setPosition(440, 90);
	menuMinusTr.setPosition(480, 90);

	numbTrains = 5;
	numbStations = 7;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//�������� ���� �������//

	Text NameStation[20];

	NameStation[0] = Text(L"�������", capture, 24);
	NameStation[1] = Text(L"�������", capture, 24);
	NameStation[2] = Text(L"�������", capture, 24);
	NameStation[3] = Text(L"������������", capture, 24);
	NameStation[4] = Text(L"���������", capture, 24);
	NameStation[5] = Text(L"�������", capture, 24);
	NameStation[6] = Text(L"������", capture, 24);
	NameStation[7] = Text(L"�������", capture, 24);
	NameStation[8] = Text(L"�����������", capture, 24);
	NameStation[9] = Text(L"�������", capture, 24);
	NameStation[10] = Text(L"��������", capture, 24);
	NameStation[11] = Text(L"���������", capture, 24);
	NameStation[12] = Text(L"��������", capture, 24);
	NameStation[13] = Text(L"��������", capture, 24);
	NameStation[14] = Text(L"��������", capture, 24);
	NameStation[15] = Text(L"���������", capture, 24);
	NameStation[16] = Text(L"��������", capture, 24);
	NameStation[17] = Text(L"���������", capture, 24);
	NameStation[18] = Text(L"�������", capture, 24);
	NameStation[19] = Text(L"1337 ��", capture, 24);



	for (int i = 0; i < 10; i++)
	{
		NameStation[i].setPosition(420, 60 * (i + 1));
	}

	for (int i = 0; i < 10; i++)
	{
		NameStation[i + 10].setPosition(820, 60 * (i + 1));
	}
	Text stationInfBefore = Text(L"�������� ��� ", font, 24);
	Text stationInfAfter = Text(L" �������(�)", font, 24);
	Text stationInfSave = Text(L"��������� ����������", font, 28);

	stationInfBefore.setPosition(484, 15);
	coutNumbStations.setPosition(750, 15);
	stationInfAfter.setPosition(800, 15);

	stationInfSave.setPosition(510, 680);//������ ���������� ���������� � ��������

	coutNumbStations.setFillColor(Color::Red);
	bool f[20] = { false }; //������ ������ ��� ������� � �������� �������
	Text Otmetka[20]; //������ ������� � �������� � ������ �������
	for (int i = 0; i < 10; i++)
	{
		Otmetka[i] = Text("+", font, 24);
		Otmetka[i].setFillColor(Color::Cyan);
		Otmetka[i].setPosition(650, 60 * (i + 1));
	}

	for (int i = 0; i < 10; i++)
	{
		Otmetka[i + 10] = Text("+", font, 24);
		Otmetka[i + 10].setFillColor(Color::Cyan);
		Otmetka[i + 10].setPosition(1050, 60 * (i + 1));
	}
	int countOfClick[20] = { 0 }; //������, ������� ���������� ���������� ������ �� �����-���� �������

	///////////////////////////////////////////////////////////////////////////////////////////////////

	//��������������� �������� ����� ������������ ��� ���� �������

	int numbTr = 0;

	bool isNeedToChooseStartSt = true; //���� �� ��������� ������ ������ ����� ��������� �������

	Text trainInfBefore = Text(L"������� ���������� � ", capture, 28);
	trainInfBefore.setPosition(400, 15);
	trainInfBefore.setFillColor(Color(49, 0, 98));

	Text numberTrain = Text("", capture, 28);
	numberTrain.setFillColor(Color::Red);
	numberTrain.setPosition(780, 15);

	Text trainInfAfter = Text(L" ������", capture, 28);
	trainInfAfter.setPosition(800, 15);
	trainInfAfter.setFillColor(Color(49, 0, 98));

	Text trainChooseFirstSt = Text(L"�������� ��������� �������", capture, 24);
	trainChooseFirstSt.setPosition(10, 100);
	trainChooseFirstSt.setFillColor(Color::Black);

	Text trainChooseLastSt = Text(L"�������� �������� �������", capture, 24);
	trainChooseLastSt.setPosition(10, 200);
	trainChooseLastSt.setFillColor(Color::Black);

	Text trainChooseStations = Text(L"�������� ������� ���������", capture, 24);
	trainChooseStations.setPosition(10, 300);
	trainChooseStations.setFillColor(Color::Black);

	Text trainChooseStopsTime = Text(L"��� ������ ������� ������� ����� ��������� � �������", capture, 24);
	trainChooseStopsTime.setPosition(10, 400);
	trainChooseStopsTime.setFillColor(Color::Black);

	Text trainLabelNearFirstSt = Text(L"��������� ��������� �������", capture, 24);
	trainLabelNearFirstSt.setFillColor(Color::Yellow);
	trainLabelNearFirstSt.setPosition(530, 680);

	Text trainLabelNearEndSt = Text(L"��������� �������� �������", capture, 24);
	trainLabelNearEndSt.setFillColor(Color::Yellow);
	trainLabelNearEndSt.setPosition(530, 680);

	Text trainLabelNearSt = Text(L"��������� ������������� �������", capture, 24);
	trainLabelNearSt.setFillColor(Color::Yellow);
	trainLabelNearSt.setPosition(530, 680);

	Text trainLabelNearTime = Text(L"��������� ����� ���������", capture, 24);
	trainLabelNearTime.setFillColor(Color::Yellow);
	trainLabelNearTime.setPosition(530, 680);

	Text trainChooseStartTime = Text(L"����� �����������", capture, 24);
	trainChooseStartTime.setFillColor(Color::Black);
	trainChooseStartTime.setPosition(1000, 100);

	Text trainLastTime = Text(L"��������� ����� ��������", capture, 24);
	trainLastTime.setFillColor(Color::Red);
	trainLastTime.setPosition(1000, 400);

	Text trainSwitchTrain = Text(L"������� � ����. ������", capture, 24);
	trainSwitchTrain.setFillColor(Color::Red);
	trainSwitchTrain.setPosition(900, 600);

	Text trainHourStart = Text(L"", capture, 28);
	trainHourStart.setFillColor(Color::Red);
	trainHourStart.setPosition(1100, 200);

	Text trainDvoetochie = Text(":", capture, 28);
	trainDvoetochie.setFillColor(Color::Black);
	trainDvoetochie.setPosition(1150, 200);

	Text trainMinStart = Text(L"", capture, 28);
	trainMinStart.setFillColor(Color::Red);
	trainMinStart.setPosition(1178, 200);

	Text trainHourEnd = Text("", capture, 28);
	trainHourEnd.setFillColor(Color::Red);
	trainHourEnd.setPosition(1100, 500);

	Text trainDvoetochieEnd = Text(":", capture, 28);
	trainDvoetochieEnd.setFillColor(Color::Black);
	trainDvoetochieEnd.setPosition(1150, 500);

	Text trainMinEnd = Text("", capture, 28);
	trainMinEnd.setFillColor(Color::Red);
	trainMinEnd.setPosition(1178, 500);

	Text trainHourPlus = Text(L"+", font, 28);
	trainHourPlus.setFillColor(Color::Black);
	trainHourPlus.setPosition(1110, 170);

	Text trainHourMinus = Text(L"-", font, 28);
	trainHourMinus.setFillColor(Color::Black);
	trainHourMinus.setPosition(1110, 230);

	Text trainMinPlus = Text(L"+", font, 28);
	trainMinPlus.setFillColor(Color::Black);
	trainMinPlus.setPosition(1187, 170);

	Text trainMinMinus = Text(L"-", font, 28);
	trainMinMinus.setFillColor(Color::Black);
	trainMinMinus.setPosition(1187, 230);



	Text labelTimeStops[20];//����������� ����� ���������
	for (int i = 0; i < 10; i++)
	{
		labelTimeStops[i] = Text("", capture, 24);
		labelTimeStops[i].setFillColor(Color::Red);
		labelTimeStops[i].setPosition(650, 60 * (i + 1));
	}
	for (int i = 0; i < 10; i++)
	{
		labelTimeStops[i + 10] = Text("", capture, 24);
		labelTimeStops[i + 10].setFillColor(Color::Red);
		labelTimeStops[i + 10].setPosition(1050, 60 * (i + 1));
	}
	//����������� ������ + � - ��� ��������� ������� ���������
	Text labelTrainPlus[20];
	Text labelTrainMinus[20];

	for (int i = 0; i < 10; i++)
	{
		labelTrainPlus[i] = Text("+", font, 24);
		labelTrainPlus[i].setFillColor(Color::Yellow);
		labelTrainPlus[i].setPosition(680, 60 * (i + 1));

		labelTrainMinus[i] = Text("-", font, 24);
		labelTrainMinus[i].setFillColor(Color::Yellow);
		labelTrainMinus[i].setPosition(714, 60 * (i + 1));
	}

	for (int i = 0; i < 10; i++)
	{
		labelTrainPlus[i + 10] = Text("+", font, 24);
		labelTrainPlus[i + 10].setFillColor(Color::Yellow);
		labelTrainPlus[i + 10].setPosition(1080, 60 * (i + 1));

		labelTrainMinus[i + 10] = Text("-", font, 24);
		labelTrainMinus[i + 10].setFillColor(Color::Yellow);
		labelTrainMinus[i + 10].setPosition(1114, 60 * (i + 1));
	}

	//��������� ������� ���������
	for (int i = 0; i < 20; i++)
	{
		Trains[i].setHourStart(0);
		Trains[i].setMinStart(0);
		for (int j = 0; j < 20; j++)
		{
			Trains[i].setSomeTimeStops(0, j);
		}
	}

	bool trainIsPressedMouse = false;
	bool isMenuStartSt = false;
	bool isMenuEndSt = false;
	bool isMenuSt = false;
	bool isMenuTimeStop = false;
	bool isAcceptedToSetStartTime = false; //���� �� ���������� ����� ������� �����������
	bool trainFirtsStFlag[20] = { false };
	bool trainEndStFlag[20] = { false };
	bool trainStFlag[20] = { false };
	bool trainIsNeedToSwitchTrain = false;


	int Hour = 0;
	int Min = 0;

	int numbStartSt = 0;
	int numbEndSt = 0;
	///////////////////////////////////////////////////////////////////////////////////////////////////

	///////�������� ����/////
	bool flagStationMenu = false; // ���� �������� �� ���� �������
	bool flagTrainMenu = false; //���� �������� �� ���� �������
	bool isChoosedAnySt = false; //���� ������ ���� �� �����-�� �������
	bool isNeedToSaveStations = false; //���� ���������� �������

	int CoutStation;//���������� ����������� ���������� �������

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//�������� ������ ����

	while (isMenu)
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			//�������������� ��������
			menuPlusSt.setColor(Color::White);
			menuMinusSt.setColor(Color::White);
			menuPlusTr.setColor(Color::White);
			menuMinusTr.setColor(Color::White);
			spriteChooseSt.setColor(Color::White);
			spriteChooseTr.setColor(Color::White);
			spriteMenuStationBack.setColor(Color::White);
			spriteMenuExit.setColor(Color::White);
			stationInfSave.setFillColor(Color::Green);
			menuSaveAll.setFillColor(Color::Green);

			menuNum = 0;//����������, ������� ���������� ����� ������� ����� ������� ��� ���������

			//������� ���������� ������� � ������ ��� ������ �� �����
			outputNumbStations.setString(to_string(numbStations));
			outputNumbTrains.setString(to_string(numbTrains));
			//�������� �������� ��� ��������� ������� �� �����-������ ������
			if (!flagStationMenu && !flagTrainMenu) { //���� ��������� � ������� ����
				if (IntRect(450, 50, 25, 35).contains(Mouse::getPosition(window))) { menuPlusSt.setColor(Color::Blue); menuNum = 1; }
				if (IntRect(490, 50, 25, 35).contains(Mouse::getPosition(window))) { menuMinusSt.setColor(Color::Red); menuNum = 2; }

				if (IntRect(450, 90, 25, 35).contains(Mouse::getPosition(window))) { menuPlusTr.setColor(Color::Blue); menuNum = 3; }
				if (IntRect(490, 90, 25, 35).contains(Mouse::getPosition(window))) { menuMinusTr.setColor(Color::Red); menuNum = 4; }

				if (IntRect(50, 130, 300, 35).contains(Mouse::getPosition(window))) { spriteChooseSt.setColor(Color::Blue); menuNum = 5; }
				if (IntRect(0, 170, 380, 35).contains(Mouse::getPosition(window))) { spriteChooseTr.setColor(Color::Blue); menuNum = 6; }
			}
			if (flagStationMenu && !isNeedToSaveStations) {
				if (IntRect(530, 680, 335, 45).contains(Mouse::getPosition(window))) { spriteMenuStationBack.setColor(Color::Blue); menuNum = 8; }
			}

			if (flagTrainMenu && !isMenuStartSt && !isMenuEndSt && !isMenuTimeStop && !isMenuSt)
			{
				if (IntRect(530, 680, 335, 45).contains(Mouse::getPosition(window))) { spriteMenuStationBack.setColor(Color::Blue); menuNum = 9; }
			}

			if (!flagStationMenu && !flagTrainMenu) {
				if (IntRect(540, 680, 270, 45).contains(Mouse::getPosition(window))) { spriteMenuExit.setColor(Color::Blue); menuNum = 10; }
			}

			if (flagStationMenu && isNeedToSaveStations) //������� ���������� �������
			{
				if (IntRect(510, 680, 400, 45).contains(Mouse::getPosition(window))) {
					stationInfSave.setFillColor(Color::Yellow);
					menuNum = 7;
				};
			}

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1)
				{
					if (numbStations < 20)
						numbStations++;
				}
				if (menuNum == 2)
				{
					if (numbStations > 7)
						numbStations--;
				}
				if (menuNum == 3)
				{
					if (numbTrains < 20)
						numbTrains++;
				}
				if (menuNum == 4)
				{
					if (numbTrains > 5)
						numbTrains--;
				}
				if (menuNum == 5)
				{
					flagStationMenu = true;
				}
				if (menuNum == 6 && numbTr < numbTrains)
				{
					flagTrainMenu = true;
				}
				if (menuNum == 7)
				{
					flagStationMenu = false;
					for (int i = 0; i < 20; i++) {
						f[i] = false;
						countOfClick[i] = 0;
					}
				}
				if (menuNum == 8)
				{
					flagStationMenu = false;
				}
				if (menuNum == 9)
				{
					flagTrainMenu = false;
				}
				if (menuNum == 10)
				{
					isMenu = false;
					window.close();
				}
			}
			if (!flagStationMenu && !flagTrainMenu) { //���� �� ��������� � ������� ����
				if (saveInf)
				{
					if (IntRect(700, 350, 200, 24).contains(Mouse::getPosition(window)))
					{
						menuSaveAll.setFillColor(Color::Blue);
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							isMenu = false;
						}
					}
					window.draw(menuSaveAll);
				}

				window.draw(menuBG);
				window.draw(spriteMainMenu);
				window.draw(outputNumbStations);
				window.draw(outputNumbTrains);
				window.draw(labelMenu1);
				window.draw(labelMenu2);
				window.draw(menuPlusSt);
				window.draw(menuMinusSt);
				window.draw(menuPlusTr);
				window.draw(menuMinusTr);
				window.draw(spriteChooseSt);
				window.draw(spriteChooseTr);
				window.draw(spriteMenuExit);
			}
			else if (flagStationMenu) //���� �� ��������� � ���� ����� �������
			{
				//�������� ���������� �� ��������� �������
				
				for (int i = 0; i < 20; i++)
				{
					Stancii[i].setDistToNextStation(9);
				}
				/////////
				isNeedToSaveStations = false; //�������� ���� ����������
				isChoosedAnySt = false;
				for (int i = 0; i < 20; i++)
					if (f[i] == true)
						isChoosedAnySt = true;
				if (!isChoosedAnySt)
					CoutStation = numbStations;
				coutNumbStations.setString(to_string(CoutStation));
				window.draw(spriteMenuStation);
				if (CoutStation > 0)
					window.draw(spriteMenuStationBack);
				window.draw(stationInfBefore);
				window.draw(stationInfAfter);
				window.draw(coutNumbStations);
				for (int i = 0; i < 20; i++)
				{
					window.draw(NameStation[i]);
				}
				int j = 1, k = 1; //����������, ���������� �� ������� � ������� ��� ������ ������
				for (int i = 0; i < 20; i++)
				{
					NameStation[i].setFillColor(Color(31, 174, 233)); //����������� ������������ �����
					if (j == 11)
					{
						j = 1;
						k = 2;
					}
					if (IntRect(420 * k, 60 * j, 200, 33).contains(Mouse::getPosition(window))) {  //���� ������ �������� �� �������
						NameStation[i].setFillColor(Color::Red);
						if (Mouse::isButtonPressed(Mouse::Left)) { //���� ������ ���
							if (CoutStation > 0) //����������� ���������� ������� ������, ���� ��� ���� ����������� �������
								countOfClick[i] ++;
							//��������� ������, ����� ��� ������� ��� �������, �� ����� �������� �����-���� �������
							if (CoutStation == 0 && countOfClick[i] % 2 != 0)
							{
								countOfClick[i]++;
								f[i] = false;
								CoutStation++;
							}
							else if (countOfClick[i] % 2 == 0 && CoutStation > 0) //���� ������ ������ ���-�� ���
							{
								f[i] = false;
								CoutStation++;
							}
							if (countOfClick[i] % 2 != 0 && countOfClick > 0)//���� ������ �������� ���-�� ���
							{
								f[i] = true;
								CoutStation--;
							}
						}
					}
					j++;
				}

				for (int i = 0; i < 20; i++) //����������� ������� �� ������
				{
					if (f[i])
						window.draw(Otmetka[i]);
				}

				if (CoutStation == 0) //����� ������ "���������"
				{
					isNeedToSaveStations = true; //�������� ���� ����������
					window.draw(stationInfSave);
					//������� ������ �������
					for (int i = 0; i < Stancii.size(); i++)
						Stancii[i].setIsIncluded(false);
					for (int i = 0; i < 20; i++) {
						Stancii[i].setIsIncluded(f[i]);
					}
				}

			}
			else if (flagTrainMenu) //���� �� ��������� � ���� ����� �������
			{
				if (numbTr < numbTrains) //�������� � ����� ���� ��� ���� ������ ��� ��������
				{

					Trains[numbTr].setStatus(OK);
					window.draw(spriteMenuTrain);
					window.draw(trainInfBefore);
					window.draw(trainInfAfter);
					window.draw(numberTrain);
					numberTrain.setString(to_string(numbTr + 1));

					//���� �������������� ������
					trainChooseFirstSt.setFillColor(Color::Black);
					trainChooseLastSt.setFillColor(Color::Black);
					trainChooseStations.setFillColor(Color::Black);
					trainChooseStopsTime.setFillColor(Color::Black);
					//
					//����� ������� � ����
					//������� �������� �� ����� ��������� �������
					if (IntRect(0, 100, 405, 24).contains(Mouse::getPosition(window)) && (isMenuEndSt + isMenuSt + isMenuSt + isMenuTimeStop == 0))
					{
						trainChooseFirstSt.setFillColor(Color(0, 191, 255));
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							isMenuStartSt = true;
						}
					}
					//������� �������� �� ����� �������� �������
					if (IntRect(10, 200, 380, 24).contains(Mouse::getPosition(window)) && (isMenuEndSt + isMenuSt + isMenuSt + isMenuTimeStop == 0))
					{
						trainChooseLastSt.setFillColor(Color(0, 191, 255));
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							isMenuEndSt = true;
						}
					}
					//������� �������� �� ����� ������������� �������
					if (IntRect(10, 300, 395, 24).contains(Mouse::getPosition(window)) && (isMenuEndSt + isMenuSt + isMenuSt + isMenuTimeStop == 0))
					{
						trainChooseStations.setFillColor(Color(0, 191, 255));
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							isMenuSt = true;
						}
					}
					//������� �������� �� ����� ������� ���������
					if (IntRect(10, 400, 750, 24).contains(Mouse::getPosition(window)) && (isMenuEndSt + isMenuSt + isMenuSt + isMenuTimeStop == 0))
					{
						trainChooseStopsTime.setFillColor(Color(0, 191, 255));
						if (Mouse::isButtonPressed(Mouse::Left))
						{
							isMenuTimeStop = true;
						}
					}

					//�������� ������� ������� ��������� �������
					if (isMenuStartSt) //���� �� �������� ��������� �������
					{
						for (int i = 0; i < 20; i++)
							if (Stancii[i].getIsIncluded())
								window.draw(NameStation[i]);
						int j = 1, k = 1; //����������, ���������� �� ������� � ������� ��� ������ ������
						for (int i = 0; i < 20; i++)
						{
							NameStation[i].setFillColor(Color(31, 174, 233)); //����������� ������������ �����
							if (j == 11)
							{
								j = 1;
								k = 2;
							}
							if (IntRect(420 * k, 60 * j, 200, 33).contains(Mouse::getPosition(window)) && (Stancii[i].getIsIncluded())) {  //���� ������ �������� �� �������
								NameStation[i].setFillColor(Color::Green);
								if (Mouse::isButtonPressed(Mouse::Left)) { //���� ������ ���
									{
										if (trainFirtsStFlag[i]) //�������� ������ �������
											for (int index = 0; index < 20; index++)
												trainFirtsStFlag[index] = false;
										else
										{
											for (int index = 0; index < 20; index++)
												trainFirtsStFlag[index] = false;
											trainFirtsStFlag[i] = true;
										}
									}
								}
							}
							j++;
						}
						for (int i = 0; i < 20; i++) //������������ ��������� �������
						{
							trainLabelNearFirstSt.setFillColor(Color::Yellow); //�������������
							if (trainFirtsStFlag[i])
							{
								NameStation[i].setFillColor(Color::Green);
								if (IntRect(530, 680, 400, 24).contains(Mouse::getPosition(window)))
								{
									trainLabelNearFirstSt.setFillColor(Color::Green);
									if (Mouse::isButtonPressed(Mouse::Left))
									{
										isMenuStartSt = false;
										Trains[numbTr].setStartStation(Stancii[i].getName());//�������� � ����� ������ �������� ��������� �������
										Trains[numbTr].setSomeSt(Stancii[i].getName(), i);
										Trains[numbTr].setSomeTimeStops(2, i);//������������� ������������ ������� ���������
										numbStartSt = i;
										Trains[numbTr].setNumbStartSt(numbStartSt);
									}
								}
								window.draw(trainLabelNearFirstSt);
							}
						}
					}

					//�������� ������ �������� �������
					if (isMenuEndSt)
					{
						for (int i = 0; i < 20; i++)
							if (Stancii[i].getIsIncluded() && !trainFirtsStFlag[i])
								window.draw(NameStation[i]);
						int j = 1, k = 1; //����������, ���������� �� ������� � ������� ��� ������ ������
						for (int i = 0; i < 20; i++)
						{
							if (!trainFirtsStFlag[i])
							{
								NameStation[i].setFillColor(Color(31, 174, 233)); //����������� ������������ �����
								if (j == 11)
								{
									j = 1;
									k = 2;
								}
								if (IntRect(420 * k, 60 * j, 200, 33).contains(Mouse::getPosition(window)) && (Stancii[i].getIsIncluded())) {  //���� ������ �������� �� �������
									NameStation[i].setFillColor(Color::Red);
									if (Mouse::isButtonPressed(Mouse::Left)) { //���� ������ ���
										{
											if (trainEndStFlag[i]) //�������� ������ �������
												for (int index = 0; index < 20; index++)
													trainEndStFlag[index] = false;
											else
											{
												for (int index = 0; index < 20; index++)
													trainEndStFlag[index] = false;
												trainEndStFlag[i] = true;
											}
										}
									}
								}
							}
							j++;
						}

						for (int i = 0; i < 20; i++) //������������ ��������� �������
						{
							trainLabelNearEndSt.setFillColor(Color::Yellow); //�������������
							if (!trainFirtsStFlag[i] && trainEndStFlag[i])
							{
								NameStation[i].setFillColor(Color::Red);
								if (IntRect(530, 680, 400, 24).contains(Mouse::getPosition(window)))
								{
									trainLabelNearEndSt.setFillColor(Color::Green);
									if (Mouse::isButtonPressed(Mouse::Left))
									{
										isMenuEndSt = false;
										Trains[numbTr].setEndStation(Stancii[i].getName());//�������� � ����� ������ �������� ��������� �������
										Trains[numbTr].setSomeSt(Stancii[i].getName(), i);
										Trains[numbTr].setSomeTimeStops(2, i);//������������� ������������ ������� ���������
										numbEndSt = i;
										Trains[numbTr].setNumbEndSt(numbEndSt);
									}
								}
								window.draw(trainLabelNearEndSt);
							}
						}
					}

					//�������� ������ ������������� �������
					if (isMenuSt)
					{
						for (int i = min(numbStartSt, numbEndSt); i <= max(numbStartSt, numbEndSt); i++)
							if (Stancii[i].getIsIncluded())
							{
								window.draw(NameStation[i]);
							}


						int j = 1, k = 1; //����������, ���������� �� ������� � ������� ��� ������ ������

						for (int i = 0; i < 20; i++)
						{
							if (j == 11)
							{
								j = 1;
								k = 2;
							}

							if (i > min(numbStartSt, numbEndSt) && i < max(numbStartSt, numbEndSt))
							{
								NameStation[i].setFillColor(Color(31, 174, 233)); //����������� ������������ �����

								if (IntRect(420 * k, 60 * j, 200, 33).contains(Mouse::getPosition(window)) && (Stancii[i].getIsIncluded()))
								{  //���� ������ �������� �� �������
									NameStation[i].setFillColor(Color::Blue);
									if (Mouse::isButtonPressed(Mouse::Left)) { //���� ������ ���
										{
											if (trainStFlag[i]) //�������� ������ �������
												trainStFlag[i] = false;
											else
												trainStFlag[i] = true;
										}
									}
								}
							}
							j++;
						}

						for (int i = min(numbStartSt, numbEndSt) + 1; i < max(numbStartSt, numbEndSt); i++) //������������ ��������� �������
						{
							if (trainStFlag[i])
							{
								NameStation[i].setFillColor(Color::Blue);
							}
						}

						trainLabelNearSt.setFillColor(Color::Yellow);

						if (IntRect(530, 680, 460, 24).contains(Mouse::getPosition(window)))
						{
							trainLabelNearSt.setFillColor(Color::Green);
							if (Mouse::isButtonPressed(Mouse::Left))
							{
								for (int i = min(numbStartSt, numbEndSt) + 1; i < max(numbStartSt, numbEndSt); i++)
								{
									if (trainStFlag[i])
									{
										Trains[numbTr].setSomeSt(Stancii[i].getName(), i);
										Trains[numbTr].setSomeTimeStops(2, i);//������������� ������������ ������� ���������
									}
								}
								isMenuSt = false;
							}
						}
						window.draw(trainLabelNearSt);

					}

					//�������� ������ ������� ���������
					if (isMenuTimeStop)
					{
						//��������� ������� ���������  � ��������������
						for (int i = 0; i < 20; i++)
						{
							labelTimeStops[i].setString(to_string(Trains[numbTr].getSomeTimeStop(i)));
							labelTrainPlus[i].setFillColor(Color::Yellow);
							labelTrainMinus[i].setFillColor(Color::Yellow);
						}
						trainChooseStopsTime.setPosition(300, 700);
						//����������� ��������
						int k = 0, j = 1;
						for (int i = 0; i < 20; i++)
						{
							if (j == 11)
							{
								k = 1;
								j = 1;
							}
							if (trainStFlag[i] || trainFirtsStFlag[i] || trainEndStFlag[i])
							{
								if (IntRect(680 + 400 * k, 60 * j, 24, 24).contains(Mouse::getPosition(window))) //���� ������� �� ������
								{
									labelTrainPlus[i].setFillColor(Color::Blue);
									if (Mouse::isButtonPressed(Mouse::Left)) //���� �������� �� ������
									{
										if (Trains[numbTr].getSomeTimeStop(i) < 5) //���� < 5 ��� ����� ���������
											Trains[numbTr].setSomeTimeStops(Trains[numbTr].getSomeTimeStop(i) + 1, i); //����������� ����� ��������� �� 1 ������ 
									}
								}

								else if (IntRect(714 + 400 * k, 60 * j, 24, 24).contains(Mouse::getPosition(window))) //���� ������� �� �����
								{
									labelTrainMinus[i].setFillColor(Color::Red);
									if (Mouse::isButtonPressed(Mouse::Left)) //���� �������� �� �����
									{
										if (Trains[numbTr].getSomeTimeStop(i) > 2) //���� ����� ������� ������ 2 �����
											Trains[numbTr].setSomeTimeStops(Trains[numbTr].getSomeTimeStop(i) - 1, i); //��������� ����� ������� �� 1 ������
									}
								}
								window.draw(NameStation[i]);
								window.draw(labelTimeStops[i]);
								window.draw(labelTrainPlus[i]);
								window.draw(labelTrainMinus[i]);
							}
							j++;
						}
						trainLabelNearTime.setFillColor(Color::Yellow);
						if (IntRect(530, 680, 380, 24).contains(Mouse::getPosition(window)))
						{
							trainLabelNearTime.setFillColor(Color::Green);
							if (Mouse::isButtonPressed(Mouse::Left)) //���� �������� �� ������ ���������
							{
								isMenuTimeStop = false;
								isAcceptedToSetStartTime = true;
								trainChooseStopsTime.setPosition(10, 400);
								Hour = 0;
								Min = 0;
							}
						}
						window.draw(trainLabelNearTime);
					}

					if (isMenuStartSt)
						window.draw(trainChooseFirstSt);
					if (isMenuEndSt)
						window.draw(trainChooseLastSt);
					if (isMenuSt)
						window.draw(trainChooseStations);
					if (isMenuTimeStop)
						window.draw(trainChooseStopsTime);
					if (isAcceptedToSetStartTime) //���� ������� ������
					{


						//��������������
						trainHourMinus.setFillColor(Color::Black);
						trainHourPlus.setFillColor(Color::Black);
						trainMinMinus.setFillColor(Color::Black);
						trainMinPlus.setFillColor(Color::Black);
						trainLastTime.setFillColor(Color::Red);
						
						if (Hour < 10)
							trainHourStart.setString("0" + to_string(Hour));
						else if (Hour >= 10)
							trainHourStart.setString(to_string(Hour));
						if (Min < 10)
							trainMinStart.setString("0" + to_string(Min));
						if (Min >= 10)
							trainMinStart.setString(to_string(Min));

						if (IntRect(1110, 170, 28, 28).contains(Mouse::getPosition(window)))//���� ������� �� ������ ����� �����
						{
							trainHourPlus.setFillColor(Color::Blue);
							if (Mouse::isButtonPressed(Mouse::Left))
							{
								if (Hour < 23)
									Hour++;
								Trains[numbTr].setHourStart(Hour);
							}
						}

						if (IntRect(1110, 230, 28, 28).contains(Mouse::getPosition(window)))//���� ������� �� ����� ����� �����
						{
							trainHourMinus.setFillColor(Color::Red);
							if (Mouse::isButtonPressed(Mouse::Left))
							{
								if (Hour > 0)
									Hour--;
								Trains[numbTr].setHourStart(Hour);
							}
						}

						if (IntRect(1187, 170, 28, 28).contains(Mouse::getPosition(window)))//���� ������� �� ������ ����� �����
						{
							trainMinPlus.setFillColor(Color::Blue);
							if (Mouse::isButtonPressed(Mouse::Left))
							{
								if (Min < 59)
									Min++;
								if (Min == 59)
								{
									Hour++;
									Min = 0;
									if (Hour >= 24)
										Hour = 0;
								}
								Trains[numbTr].setHourStart(Hour);
								Trains[numbTr].setMinStart(Min);
							}
						}

						if (IntRect(1187, 230, 28, 28).contains(Mouse::getPosition(window)))//���� ������� �� ������ ����� �����
						{
							trainMinMinus.setFillColor(Color::Red);
							if (Mouse::isButtonPressed(Mouse::Left))
							{
								if (Min == 0)
								{
									if (Hour != 0)
									{
										Hour--;
										Min = 59;
									}
								}
								else if (Min != 0)
								{
									Min--;
								}
								Trains[numbTr].setHourStart(Hour);
								Trains[numbTr].setMinStart(Min);
							}
							Trains[numbTr].setHourStart(Hour);
							Trains[numbTr].setMinStart(Min);
						}
						
						//������������ ���������������� ������� ��������
						if (IntRect(1000, 400, 350, 28).contains(Mouse::getPosition(window))) //���� ������� �� ������ ��������� ����� ��������
						{
							trainLastTime.setFillColor(Color::Blue);
							if (Mouse::isButtonPressed(Mouse::Left))
							{
								int HourEnd = Trains[numbTr].getHourStart(), MinEnd = Trains[numbTr].getMinStart();
								for (int i = min(numbEndSt, numbStartSt); i <= max(numbEndSt, numbStartSt); i++)
								{
									int time = Stancii[i].getDistToNextStation();
									MinEnd += time;
									if (trainStFlag[i] || trainEndStFlag[i] || trainFirtsStFlag[i])
										MinEnd += Trains[numbTr].getSomeTimeStop(i);
									if (MinEnd >= 60)
									{
										HourEnd++;
										MinEnd -= 60;
									}
								}

								if (MinEnd >= 60)
								{
									HourEnd++;
									MinEnd -= 60;
								}

								if (HourEnd >= 24)
								{
									HourEnd -= 24;
								}

								if (HourEnd >= 10)
									trainHourEnd.setString(to_string(HourEnd));
								else if (HourEnd < 10)
									trainHourEnd.setString("0" + to_string(HourEnd));
								if (MinEnd >= 10)
									trainMinEnd.setString(to_string(MinEnd));
								else if (MinEnd < 10)
									trainMinEnd.setString("0" + to_string(MinEnd));
								Trains[numbTr].setHourEnd(HourEnd);
								Trains[numbTr].setMinEnd(MinEnd);
								//��������� ����������
								HourEnd = 0;
								MinEnd = 0;
								trainIsNeedToSwitchTrain = true; //���� ��� ��������� ������ "���� �����"	
							}
						}

						window.draw(trainChooseStartTime);
						window.draw(trainHourStart);
						window.draw(trainMinStart);
						window.draw(trainDvoetochie);
						window.draw(trainLastTime);
						window.draw(trainMinMinus);
						window.draw(trainMinPlus);
						window.draw(trainHourMinus);
						window.draw(trainHourPlus);
						window.draw(trainHourEnd);
						window.draw(trainDvoetochieEnd);
						window.draw(trainMinEnd);
					}
					if (trainIsNeedToSwitchTrain)//�������� ������ �������� � ��������� ������
					{
						trainSwitchTrain.setFillColor(Color::Red);
						if (IntRect(900, 600, 300, 24).contains(Mouse::getPosition(window)))
						{
							trainSwitchTrain.setFillColor(Color::Blue);
							if (Mouse::isButtonPressed(Mouse::Left))
							{
								numbTr++;
								trainIsNeedToSwitchTrain = false;
								isAcceptedToSetStartTime = false;

								trainMinEnd.setString("00");
								trainHourEnd.setString("00");
								//��������� ���� ������
								for (int i = 0; i < 20; i++)
								{
									trainFirtsStFlag[i] = false;
									trainEndStFlag[i] = false;
									trainStFlag[i] = false;
								}

								if (numbTr == numbTrains) //���� �� ������� ��������� ����������� �����
								{
									flagTrainMenu = false;
									saveInf = true;
								}
							}
						}
						window.draw(trainSwitchTrain);
					}
					if (!isMenuStartSt && !isMenuEndSt && !isMenuSt && !isMenuTimeStop)
					{
						window.draw(trainChooseFirstSt);
						window.draw(trainChooseLastSt);
						window.draw(trainChooseStations);
						window.draw(trainChooseStopsTime);
						window.draw(spriteMenuStationBack);
					}
				}
			}
			window.display();
		}
	}
}