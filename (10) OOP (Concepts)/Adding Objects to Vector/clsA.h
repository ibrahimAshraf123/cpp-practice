#pragma once
#include <iostream>

using namespace std;

class clsA
{
public:
	//Parametarized Constructor
	clsA(int value)
	{
		x = value;
	}

	int x;

	void Print()
	{
		cout << "The value of x=" << x << endl;
	}

};

