/*
class RedIO
{
public:
string mGetRedDataTxt();
bool mParseDataTxt();
bool mOutObjData();

private:
shared_ptr<TarObj> objPtr;
string dataTxt;
};
*/

#include "RedParse.h"

RedIO::RedIO() 
{
	objPtr = make_shared<TarObj>();
	dataTxt = "";
}

string RedIO::mGetRedDataTxt() 
{
	return string("");
}

bool RedIO::mParseDataTxt() 
{
	return true;
}

bool RedIO::mOutObjData() 
{
	return true;
}
