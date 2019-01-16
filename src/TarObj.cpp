/*
class TarObj
{
private:

string id;
LeagueType league;
string data;
vector<int> vet;
vector<int> spec;
string year;
int cost;
int cards;
bool prototype;
string nation;
string name;

bool mSetID(string tarID);
bool mSetLeague(LeagueType tarLeague);
bool mSetData(string tarData);
bool mSetVet(vector<int> tarVet);
bool mSetSpec(vector<int> tarSpec);
bool mSetYear(string tarYear);
bool mSetCost(string tarCost);
bool mSetCards(int tarCards);
bool mSetPrototype(int tarPrototype);
bool mSetNation(string tarNation);
bool mSetName(string tarName);

public:
ObjTagFalseOrTrue mParseObj(string tarDataTxt);
TarObj();
};

*/

#include "RedParse.h"

ObjTagFalseOrTrue TarObj::mParseObj(string tarDataTxt)
{
	shared_ptr<string> curStrPtr = make_shared<string>(string(""));
	string::iterator currentIter = tarDataTxt.begin();

	for (; *currentIter != '['; currentIter++);
	// ID
	for(currentIter++; *currentIter != ']';currentIter++)
	{
			curStrPtr->push_back(*currentIter);
	}

	// setID
	this->mSetID(*curStrPtr);
	curStrPtr->clear();

	for (; *currentIter != '['; currentIter++);

	//League
	for (currentIter++; *currentIter != ']'; currentIter++)
	{
		curStrPtr->push_back(*currentIter);
	}

	//SetLeague
	if (*curStrPtr == "0")
	{
		this->league = NATO;
	}
	else
	{
		this->league = PACT;
	}
	curStrPtr->clear();

	//DATA
	for (; *currentIter != '"'; currentIter++);
	for (currentIter++; *currentIter != '"'; currentIter++)
	{
		curStrPtr->push_back(*currentIter);
	}
	//SetDATA
	this->mSetData(*curStrPtr);
	curStrPtr->clear();

	//vet
	for (; *currentIter != '['; currentIter++);
	for (currentIter++; *currentIter != ']'; currentIter++)
	{
		if (*currentIter != ',')
		{
			curStrPtr->push_back(*currentIter);

		}
		else
		{
			//SetVet
			int temp = atoi(curStrPtr->c_str());
			this->vet.push_back(temp);
			curStrPtr->clear();
		}
	}
	//最后一个
	int temp = atoi(curStrPtr->c_str());
	this->vet.push_back(temp);

	curStrPtr->clear();
	//Spec
	
	for (; *currentIter != '"'; currentIter++);
	for (currentIter++; *currentIter != '"'; currentIter++)
	{
		//SetSpec
		curStrPtr->push_back(*currentIter);
		this->spec.push_back(atoi(curStrPtr->c_str()));
		curStrPtr->pop_back();
	}
	curStrPtr->clear();
	//Year
	for (; *currentIter != ','; currentIter++);
	for (currentIter++; *currentIter != ','; currentIter++)
	{
		curStrPtr->push_back(*currentIter);
	}

	//SetYear
	this->mSetYear(*curStrPtr);
	curStrPtr->clear();

	//cost
	for (currentIter++; *currentIter != ','; currentIter++)
	{
		curStrPtr->push_back(*currentIter);
	}

	//SetCost
	this->mSetCost(*curStrPtr);
	curStrPtr->clear();

	//cards
	for (currentIter++; *currentIter != ','; currentIter++)
	{
		curStrPtr->push_back(*currentIter);
	}

	//SetCards
	this->mSetCards(atoi(curStrPtr->c_str()));
	curStrPtr->clear();

	//Prototype
	for (currentIter++; *currentIter != ','; currentIter++)
	{
		curStrPtr->push_back(*currentIter);
	}

	//SetPrototype
	if (*curStrPtr == "0")
	{
		this->mSetPrototype(false);
	}
	else 
	{
		this->mSetPrototype(true);
	}
	curStrPtr->clear();

	//Nation
	for (; *currentIter != '"'; currentIter++);
	for (currentIter++; *currentIter != '"'; currentIter++)
	{
		curStrPtr->push_back(*currentIter);
	}
	//SetNation
	this->mSetNation(*curStrPtr);
	curStrPtr->clear();

	//Name
	currentIter++;
	for (; *currentIter != '"'; currentIter++);
	for (currentIter++; *currentIter != '"'; currentIter++)
	{
		curStrPtr->push_back(*currentIter);
	}

	//SetName
	this->mSetName(*curStrPtr);
	curStrPtr->clear();

	return  PARSETRUE;
}

TarObj::TarObj()
{
	id = string("");
	league = NATO;
	data = string("");
	vet = vector<int>();
	spec = vector<int>();
	year = string("");
	cost = string("");
	cards = 0;
	prototype = true;
	nation = ("");
	name = ("");

}

//private member function
bool TarObj::mSetID(string tarID) 
{
	this->id = tarID;
	return true;
}

bool TarObj::mSetLeague(LeagueType tarLeague) 
{
	this->league = tarLeague;
	return true;
}

bool TarObj::mSetData(string tarData) 
{
	this->data = tarData;
	return true;
}

bool TarObj::mSetVet(vector<int> tarVet) 
{
	this->vet = tarVet;
	return true;
}

bool TarObj::mSetSpec(vector<int> tarSpec) 
{
	this->spec = tarSpec;
	return true;
}

bool TarObj::mSetYear(string tarYear) 
{
	this->year = tarYear;
	return true;
}

bool TarObj::mSetCost(string tarCost)
{
	this->cost = tarCost;
	return true;
}

bool TarObj::mSetCards(int tarCards) 
{
	this->cards = tarCards;
	return true;
}

bool TarObj::mSetPrototype(bool tarPrototype) 
{
	this->prototype = tarPrototype;
	return true;
}

bool TarObj::mSetNation(string tarNation) 
{
	this->nation = tarNation;
	return true;
}

bool TarObj::mSetName(string tarName) 
{
	this->name = tarName;
	return true;
}
