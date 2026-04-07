#include <iostream>
#include "MyInputLib.h"

using namespace std;

bool CheckPositiveNumber(int Number)
{
	bool Result;
	(Number >= 0)? Result = true : Result = false;
	

	return Result;
}

string IsNum_ZeroPositiveNegative(int Number)
{
	return (Number >= 0) ?
			(Number == 0) ? "Zero" : "Positive"		//true
			:
			"Negative";								//false
}


int main()
{
	int Number = MyInputLib::ReadNumber();

	//
	// (CheckPositiveNumber(Number) == true)? cout << "Positive\n" : cout << "Negative\n";
	cout << IsNum_ZeroPositiveNegative(Number);
	



	return 0;
}