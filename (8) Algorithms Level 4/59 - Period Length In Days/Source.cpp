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

	if(Month == 2)
		return IsLeapYear(Year)? 29 : 28;

	short arrMonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return arrMonthDays[Month - 1];
}

bool IsLastDayInMonth(stDate Date)
{
	return Date.Day == NumberOfDaysInMonth(Date.Month,Date.Year);
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
			Date.Day = 1;
			Date.Month = 1;
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

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
	return (Date1.Year == Date2.Year ? (Date1.Month == Date2.Month ? Date1.Day == Date2.Day : false) : false);
}

int GetDifferenceInDays(stDate Date1, stDate Date2, bool IncludeEndDate = false)
{
	short DaysCounter = 0;

	while (!IsDate1EqualDate2(Date1, Date2))
	{
		Date1 = IncreaseDateByOneDay(Date1);
		DaysCounter++;
	}

	return IncludeEndDate ? ++DaysCounter : DaysCounter;
}

short PeriodLengthInDays(stPeriod Period, bool IncludeEndDate = false)
{
	return GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
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

	cout << "Enter Period 1: \n";
	stPeriod Period1 = ReadPeriod();

	cout << "\nPeriod Length is : " << PeriodLengthInDays(Period1);
	cout << "\nPeriod Length (Including End Date) is : " << PeriodLengthInDays(Period1, true);


	system("pause>0");
	return 0;
}