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
	stDate FinishDate;
};


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

bool PeriodsOverlap(stPeriod Period1, stPeriod Period2)
{
	if (
		CompareDates(Period2.FinishDate, Period1.StartDate) == enDateCompare::Before
		||
		CompareDates(Period2.StartDate, Period1.FinishDate) == enDateCompare::After
		)
		return false;
	else
		return true;
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

stPeriod ReadFullPeriod()
{
	stPeriod Period;

	cout << "Enter Start Date: \n\n";
	Period.StartDate = ReadFullDate();

	cout << "\nEnter End Date: \n\n";
	Period.FinishDate = ReadFullDate();

	return Period;
}

int main()
{
	stPeriod Period1, Period2;

	cout << "Enter Period 1: \n";
	Period1 = ReadFullPeriod();
	cout << "\n";

	cout << "Enter Period 2: \n";
	Period2 = ReadFullPeriod();
	cout << "\n";

	if (PeriodsOverlap(Period1, Period2))
		cout << "Yes, Periods Overlap.";
	else
		cout << "No, Periods DONT Overlap.";



	system("pause>0");
	return 0;
}