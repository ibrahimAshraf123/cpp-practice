#pragma once

#include <iostream>

using namespace std;

namespace MyInputLib
{

	string ReadName()
	{
		string Name;
		cout << "Please enter your name? ";
		cin >> Name;
		return Name;
	}

	int ReadNumber()
	{
		int Number;
		cout << "Please enter Number? ";
		cin >> Number;
		return Number;
	}



}