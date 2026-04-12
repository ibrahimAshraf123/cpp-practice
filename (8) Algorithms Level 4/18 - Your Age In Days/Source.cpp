#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

struct stDate
{
	short Day, Month, Year;
};

bool IsLeapYear(short Year)
{
	return (Year % 400 == 0 ) || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	if (Month == 2)
		return  IsLeapYear(Year) ? 29 : 28;

	short arrMonthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return arrMonthDays[Month];
}

bool IsLastDayInMonth(stDate Date)
{
	return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
}

bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}

bool IsDate1BeforeDate2(stDate D1, stDate D2)
{
	return	(D1.Year < D2.Year ? true : (D1.Year == D2.Year ?
		D1.Month < D2.Month ? true : (D1.Month == D2.Month ?
			D1.Day < D2.Day : false) : false));
}

stDate IncreaseDateByOneDate(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

int DiffInDays(stDate D1, stDate D2, bool IncludeEndDay = false)
{
	int Days = 0;

	while (IsDate1BeforeDate2(D1, D2))
	{
		Days++;
		D1 = IncreaseDateByOneDate(D1);
	}

	return IncludeEndDay ? ++Days : Days;
}


short ReadDay()
{
	short Day;
	cout << "please enter a Day? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month;
	cout << "please enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "please enter a Year? ";
	cin >> Year;
	return Year;
}

stDate ReadFullDate()
{
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

stDate GetSystemDate()
{
	stDate Date;

	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
}

int main()
{
	cout << "Please enter your Date Of Birth: \n\n";

	stDate DateOfBirth = ReadFullDate();
	stDate SystemDate = GetSystemDate();


	cout << "\nYour Age is: ";
	cout << DiffInDays(DateOfBirth, SystemDate, true) << " Day(s).\n";





	system("pause>0");
	return 0;
}