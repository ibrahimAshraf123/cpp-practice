#include <iostream>

using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

struct stPeriod
{
	stDate StartDate;
	stDate EndDate;
};

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 0 || Month >12)
		return 0;

	if (Month == 2)
		return IsLeapYear(Year) ? 29 : 28;

	short arrMonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return arrMonthDays[Month - 1];
}

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return	Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year ?
		(Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ?
			Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? Date1.Day == Date2.Day : false) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2);
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;
}

bool IsLastDayInMonth(stDate Date)
{
	return Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year);
}

bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Year++;
			Date.Month = 1;
			Date.Day = 1;
		}
		else
		{
			Date.Month++;
			Date.Day = 1;
		}
	}
	else
	{
		Date.Day++;
	}

	return Date;
}

bool SearchDateWithinPeriod(stPeriod Period, stDate DateToCheck)
{

	while (!IsDate1EqualDate2(Period.StartDate, Period.EndDate))
	{
		if (IsDate1EqualDate2(Period.StartDate, DateToCheck))
			return true;
		Period.StartDate = IncreaseDateByOneDay(Period.StartDate);
	}

	return false;
}

bool IsDateInPeriod(stDate Date, stPeriod Period)
{
	return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before)
		||
		(CompareDates(Date, Period.EndDate) == enDateCompare::After);
}


//read period funcs
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

stPeriod ReadPeriod()
{
	stPeriod Period;

	cout << "\nEnter Start Date: \n";
	Period.StartDate = ReadFullDate();

	cout << "\nEnter End Date: \n";
	Period.EndDate = ReadFullDate();

	return Period;
}

int main()
{
	cout << "\nEnter Period: \n";
	stPeriod Period = ReadPeriod();

	cout << "\nEnter Date to check: \n";
	stDate DateToCheck = ReadFullDate();


	//two ways to solve (search or comparison)

	if (SearchDateWithinPeriod(Period, DateToCheck))
		cout << "\nYes, Date is within period.";
	else
		cout << "\nNo, Date is NOT within period.";

	if (IsDateInPeriod(DateToCheck, Period))
		cout << "\nYes, Date is within period.";
	else
		cout << "\nNo, Date is NOT within period.";


	system("pause>0");
	return 0;
}