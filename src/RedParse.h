#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;
class TarObj;

enum LeagueType { NATO = 0, PACT = 1};

enum ObjTagFalseOrTrue { 
	IDFALSE = 0, LEAGUEFALSE = 1, DATAFALSE = 2, VETFALSE = 3, SPECFALSE =4, YEARFALSE = 5, 
	COSTFALSE = 6, CARDSFALSE = 7, PROTOTYPEFALSE = 8, NATIONFALSE = 9, NAMEFALSE = 10, PARSETRUE = 11
};

class RedIO
{
	public:
		RedIO();
		string mGetRedDataTxt();
		bool mParseDataTxt();
		bool mOutObjData();
	private:
		shared_ptr<TarObj> objPtr;
		string dataTxt;
};

class TarObj
{
private:
	string id;
	LeagueType league;
	string data;
	vector<int> vet;
	vector<int> spec;
	string year;
	string cost;
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
	bool mSetPrototype(bool tarPrototype);
	bool mSetNation(string tarNation);
	bool mSetName(string tarName);
public:
	ObjTagFalseOrTrue mParseObj(string tarDataTxt);
	TarObj();
};

class TarTransport 
{
private:

public:
};
