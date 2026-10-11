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
	if (Month < 1 || Month > 12)
		return 0;

	if (Month == 2)
		return IsLeapYear(Year) ? 29 : 28;

	short arrDaysInMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return arrDaysInMonths[Month - 1];
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
	return Date1.Year < Date2.Year ? true : (Date1.Year == Date2.Year ?
		(Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ?
			Date1.Day < Date2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? Date1.Day == Date2.Day : false) : false);
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
	return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludeEndDay ? ++Days : Days;
}

enum enDateCompare {Before = -1, Equal = 0, After = 1};

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
	if (IsDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;

	if (IsDate1EqualDate2(Date1, Date2))
		return enDateCompare::Equal;

	return enDateCompare::After;
}

int PeriodLengthInDays(stPeriod Period, bool IncludeEndDay = false)
{
	return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}

bool IsPeriodsOverLap(stPeriod Period1, stPeriod Period2)
{
	if (CompareDates(Period2.EndDate, Period1.StartDate) ==
		enDateCompare::Before
		||
		CompareDates(Period2.StartDate, Period1.EndDate) ==
		enDateCompare::After)
		return false;
	else
		return true;

}

bool IsDateInPeriod(stDate Date, stPeriod Period)
{
	return !(CompareDates(Date, Period.StartDate) ==
		enDateCompare::Before || CompareDates(Date, Period.EndDate) ==
		enDateCompare::After);
}

short CountOverLapDays(stPeriod Period1, stPeriod Period2)
{
	
	int Period1Length = PeriodLengthInDays(Period1, true);
	int Period2Length = PeriodLengthInDays(Period2, true);
	int OverlapDays = 0;

	if (!IsPeriodsOverLap(Period1, Period2))
		return 0;

	if (Period1Length < Period2Length)
	{
		while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
		{
			if (IsDateInPeriod(Period1.StartDate, Period2))
				OverlapDays++;

			Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
		}
	}
	else
	{
		while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
		{
			if (IsDateInPeriod(Period2.StartDate, Period1))
				OverlapDays++;

			Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);
		}
	}

	return OverlapDays;
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

	cout << "\nEnter Start Date:\n";
	Period.StartDate = ReadFullDate();

	cout << "\nEnter End Date:\n";
	Period.EndDate = ReadFullDate();

	return Period;
}

int main()
{
	cout << "\nEnter Period 1: \n";
	stPeriod Period1 = ReadPeriod();

	cout << "\nEnter Period 2: \n";
	stPeriod Period2 = ReadPeriod();

	cout << "\nOverlap Days Count Is: " << CountOverLapDays(Period1, Period2) << endl;


	system("pause>0");
	return 0;
}