#pragma once

#include <iostream>

using namespace std;

namespace MyInputLib
{

	int ReadNumber()
	{
		cout << "Please enter a number? ";
		int Number;
		cin >> Number;

		return Number;
	}



}