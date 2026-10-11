#include <iostream>

using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

bool IsLeapYear(short Year)
{
	return (Year % 400 == 0 && Year % 100 != 0) || (Year % 4 == 0);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	if (Month == 2)
		return IsLeapYear(Year) ? 29 : 28;

	short ArrMonthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return ArrMonthDays[Month];
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

stDate ReadFullDay()
{
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

bool IsLastDayInMonth(short Day, short Month, short Year)
{
	return (Day == NumberOfDaysInAMonth(Month, Year));

}

bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}

int main()
{
	stDate Date = ReadFullDay();
	

	if (IsLastDayInMonth(Date.Day, Date.Month, Date.Year))
		cout << "\nYes Day is last Day in Month.";
	else
		cout << "\nNo Day is NOT last Day in Month.";


	if (IsLastMonthInYear(Date.Month))
		cout << "\nYes Month is last Month in Year.";
	else
		cout << "\nNo Month is NOT last Month in Year.";


	system("pause>0");
	return 0;
}