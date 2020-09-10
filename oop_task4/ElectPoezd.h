#pragma once
enum StatusEr {//ñïåöèàëüíûé òèï äàííûõ äëÿ òîãî, ÷òîáû óçíàòü - ïðàâèëüíî ëè çàäàí îáúåêò
	OK, Err
};

class ElPoezd {//îïèñàíèå êëàññà ýëåêòðîïîåçäà
public:

	ElPoezd() { Status = OK; }
	~ElPoezd();
	

	int getSpeed();
	string getName();
	string getEndStation();
	string getStartStation();
	bool getStatus();
	string getSomeSt(int index);
	int getSomeTimeStop(int index);
	int getHourStart();
	int getMinStart();
	int getHourEnd();
	int getMinEnd();
	int getNumbStartSt();
	int getNumbEndSt();

	

	Clock clockTrain;

	//Vremya vrem[20];
	bool setSpeed(int s);
	bool setName(string n);
	bool setEndStation(string st);
	bool setStartStation(string st);
	bool setSomeSt(string newSt, int index);
	bool setSomeTimeStops(int newTime, int index);
	bool setStatus(int newStatus);
	bool setHourStart(int newHour);
	bool setMinStart(int newMin);
	bool setHourEnd(int newHour);
	bool setMinEnd(int newMin);
	bool setNumbStartSt(int newNumb);
	bool setNumbEndSt(int newNumb);
private:
	int speed = 60;
	bool ChangeSpeed(int s);

	string name;
	bool ChangeName(string n);

	string StartStation;
	bool ChangeStartStation(string st);

	string EndStation;
	bool ChangeEndStation(string st);

	string Stations[20];
	bool ChangeSomeSt(string newSt, int index);

	int TimeStops[20];
	bool ChangeSomeTimeStops(int newTime, int index);

	int Status;
	bool ChangeStatus(int newStatus);

	int hourStart;
	bool ChangeHourStart(int newHour);

	int minStart;
	bool ChangeMinStart(int newMin);

	int hourEnd;
	bool ChangeHourEnd(int newHour);

	int minEnd;
	bool ChangeMinEnd(int newMin);

	int numbStartSt;
	bool ChangeNumbStartSt(int newNumb);

	int numbEndSt;
	bool ChangeNumbEndSt(int newNumb);
};

class Station {//îïèñàíèå êëàññà ñòàíöèé
public:
	Station();
	~Station();
	
	bool getIsIncluded();
	bool getStatus();
	int getDistToNextStation();
	string getName();
	
	bool setIsIncluded(bool f);
	bool setName(string n);
	bool setDistToNextStation(int d);
private:
	string name;
	bool ChangeName(string n);
	
	bool isIncluded;
	bool ChangeIsIncluded(bool f);

	int DistToNextStation;
	bool ChangeDistToNextStation(int d);
	int Status;
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ÎÏÈÑÀÍÈÅ ÄÅÉÑÒÂÈÉ Ñ ÏÎÅÇÄÀÌÈ


ElPoezd::~ElPoezd()
{
}

bool ElPoezd::getStatus()
{
	return Status;
}

int ElPoezd::getSpeed()
{
	return speed;
}

string ElPoezd::getEndStation()
{
	return EndStation;
}

string ElPoezd::getStartStation()
{
	return StartStation;
}

string ElPoezd::getName()
{
	return name;
}

string ElPoezd::getSomeSt(int index)
{
	return Stations[index];
}

int ElPoezd::getSomeTimeStop(int index)
{
	return TimeStops[index];
}

int ElPoezd::getHourStart()
{
	return hourStart;
}

int ElPoezd::getMinStart()
{
	return minStart;
}

int ElPoezd::getHourEnd()
{
	return hourEnd;
}

int ElPoezd::getMinEnd()
{
	return minEnd;
}

int ElPoezd::getNumbStartSt()
{
	return numbStartSt;
}

int ElPoezd::getNumbEndSt()
{
	return numbEndSt;
}

bool ElPoezd::ChangeNumbStartSt(int newNumb)
{
	numbStartSt = newNumb;
	return true;
}

bool ElPoezd::ChangeNumbEndSt(int newNumb)
{
	numbEndSt = newNumb;
	return true;
}

bool ElPoezd::ChangeStatus(int newStatus)
{
	Status = newStatus;
	return true;
}

bool ElPoezd::ChangeName(string n)
{
	bool result = true;
	if (result)
	{
		name = n;
	}
	return result;
}

bool ElPoezd::ChangeStartStation(string st)
{
	bool result = true;
	if (result)
	{
		StartStation = st;
	}
	return result;
}

bool ElPoezd::ChangeEndStation(string st)
{
	bool result = true;
	if (result)
	{
		EndStation = st;
	}
	return result;
}

bool ElPoezd::ChangeSpeed(int s)
{
	bool result = true;
	if (result)
	{
		speed = s;
	}
	return result;
}

bool ElPoezd::ChangeSomeSt(string newSt, int index)
{
	bool result = true;
	if (result)
	{
		Stations[index] = newSt;
	}
	return result;
}

bool ElPoezd::ChangeSomeTimeStops(int newTime, int index)
{
	bool result = (newTime >= -1);
	if (result)
	{
		TimeStops[index] = newTime;
	}
	return result;
}

bool ElPoezd::ChangeHourStart(int newHour)
{
	hourStart = newHour;
	return true;
}

bool ElPoezd::ChangeMinStart(int newMin)
{
	minStart = newMin;
	return true;
}

bool ElPoezd::ChangeHourEnd(int newHour)
{
	hourEnd = newHour;
	return true;
}

bool ElPoezd::ChangeMinEnd(int newMin)
{
	minEnd = newMin;
	return true;
}

bool ElPoezd::setStatus(int newStatus)
{
	return ChangeStatus(OK);
}

bool ElPoezd::setName(string n)
{
	if (getStatus() == OK)
		return ChangeName(n);
}

bool ElPoezd::setSpeed(int s)
{
	if (getStatus() == OK)
		return ChangeSpeed(s);
}

bool ElPoezd::setStartStation(string st)
{
	if (getStatus() == OK)
		return ChangeStartStation(st);
}

bool ElPoezd::setSomeSt(string newSt, int index)
{
	if (getStatus() == OK)
		return ChangeSomeSt(newSt, index);
}

bool ElPoezd::setEndStation(string st)
{
	if (getStatus() == OK)
		return ChangeEndStation(st);
}

bool ElPoezd::setSomeTimeStops(int newTime, int index)
{
	if (getStatus() == OK)
		return ChangeSomeTimeStops(newTime, index);
}

bool ElPoezd::setHourStart(int newHour)
{
	return ChangeHourStart(newHour);
}

bool ElPoezd::setMinStart(int newMin)
{
	return ChangeMinStart(newMin);
}

bool ElPoezd::setHourEnd(int newHour)
{
	return ChangeHourEnd(newHour);
}

bool ElPoezd::setMinEnd(int newMin)
{
	return ChangeMinEnd(newMin);
}

bool ElPoezd::setNumbEndSt(int newNumb)
{
	return ChangeNumbEndSt(newNumb);
}

bool ElPoezd::setNumbStartSt(int newNumb)
{
	return ChangeNumbStartSt(newNumb);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





//ÎÏÈÑÀÍÈÅ ÄÅÉÑÒÂÈÉ ÑÎ ÑÒÀÍÖÈÅÉ
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Station::Station()
{
	
	Status = OK;
}

Station::~Station()
{
}

int Station::getDistToNextStation()
{
	return DistToNextStation;
}

string Station::getName()
{
	return name;
}

bool Station::getStatus()
{
	return Status;
}


bool Station::ChangeDistToNextStation(int d)
{
	bool result = (d > 0);
	if (result)
	{
		DistToNextStation = d;
	}
	return result;
}

bool Station::ChangeName(string st)
{
	bool result = (st > "");
	if (result)
	{
		name = st;
	}
	return result;
}


bool Station::setDistToNextStation(int d)
{
	if (getStatus() == OK)
		return ChangeDistToNextStation(d);
}

bool Station::setName(string st)
{
	if (getStatus() == OK)
		return ChangeName(st);
}

bool Station::getIsIncluded()
{
	return isIncluded;
}

bool Station::ChangeIsIncluded(bool f)
{
	bool result = true;
	if (result)
	{
		isIncluded = f;
	}
	return result;
}

bool Station::setIsIncluded(bool f)
{
	if (getStatus() == OK)
		return ChangeIsIncluded(f);
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////