#include <iostream>

using namespace std;

struct stDate
{
	short Day, Month, Year;
};

bool IsLeapYear(short Year)
{
	return (Year % 400 == 0 && Year % 100 != 0) || (Year % 4 == 0);
}

short ReadDay()
{
	short Day;
	cout << "Please enter a Day? ";
	cin >> Day;
	return Day;
}

short ReadMonth()
{
	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "Please enter a Year? ";
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

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 0 || Month > 12)
		return 0;

	if (Month == 2)
		return (IsLeapYear(Year) ? 29 : 28);

	short arrMonthDays[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	return arrMonthDays[Month];
}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

void IncrementDate(stDate &Date)
{
	
	//if last day in month && month is last month of year, year++,month=1, day=1.

	if (IsLastDayInMonth(Date) && IsLastMonthInYear(Date.Month))
	{
		Date.Year++;
		Date.Day = 1;
		Date.Month = 1;
	}

	//if last day in month && month is NOT last month of year, month++, day=1.

	else if (IsLastDayInMonth(Date) && !IsLastMonthInYear(Date.Month))
	{
		Date.Day = 1;
		Date.Month++;
	}

	//if NOT last day in month, day++.

	else if (!IsLastDayInMonth(Date))
	{
		Date.Day++;
	}


}

int main()
{
	//Program to increment Date by 1 Day...

	stDate Date = ReadFullDate();

	IncrementDate(Date);

	cout << "\nDate after adding one day is: ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;

	system("pause>0");
	return 0;
}