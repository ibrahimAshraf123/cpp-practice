#pragma once
#include <iostream>
#include <string>
#include "clsDate.h";
#include "clsString.h";

using namespace std;

class clsInputValidate
{
public:
	
	static bool IsNumberBetween(short Num, short From, short To)
	{
		return  (Num >= From && Num <= To);
	};

	static bool IsNumberBetween(int Num, int From, int To)
	{
		return  (Num >= From && Num <= To);
	};

	static bool IsNumberBetween(float Num, float From, float To)
	{
		return  (Num >= From && Num <= To);
	};

	static bool IsNumberBetween(double Num, double From, double To)
	{
		return  (Num >= From && Num <= To);
	};

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		//Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}
		return false;
	};

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		int Num;
		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		return Num;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again\n")
	{
		int Num = ReadIntNumber();
		
		while (!IsNumberBetween(Num, From, To))
		{
			cout << ErrorMessage;
			Num = ReadIntNumber();
		}

		return Num;
	};

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again:\n")
	{
		double Num;
		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		return Num;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again\n")
	{
		double Num = ReadDblNumber();

		while (!IsNumberBetween(Num, From, To))
		{
			cout << ErrorMessage;
			Num = ReadDblNumber();
		}

		return Num;
	};

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	};

};

