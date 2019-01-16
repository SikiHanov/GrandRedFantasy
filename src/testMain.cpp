#include "RedParse.h"

int main()
{
	TarObj testObj;
	string testSTR = "CardsDB[2][0]=newDatacard(2,\"000000010000000000100000000000\",[0,20,16,0,0],\"1011110\",1975,10,3,0,\"CAN\",\"Can.Rifles\");";
	testObj.mParseObj(testSTR);
	return 0;
}