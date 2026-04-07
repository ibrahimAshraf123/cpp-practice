#include <iostream>

using namespace std;

struct sDate
{
	short Day;
	short Month;
	short Year;
};

bool IsLeapYear(short Year)
{
	return (Year % 400 == 0 && Year % 100 != 0) || (Year % 4 == 0);
}

short DaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	if (Month == 2)
		return IsLeapYear(Year) ? 29 : 28;

	short arrDaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return arrDaysInMonth[Month - 1];

}

short DaysFromBeginningOfYear(short Day, short Month, short Year)
{
	short TotalDays = 0;

	for (int i = 1; i <= Month - 1; i++)
	{
		TotalDays += DaysInAMonth(i, Year);
	}

	TotalDays += Day;

	return TotalDays;
}

sDate GetDateFromDayOrderInYear(short DaysOrderInYear, short Year)
{
	sDate Date;
	short RemainingDays = DaysOrderInYear;
	short MonthDays = 0;

	Date.Year = Year;
	Date.Month = 1;


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

int main()
{
	short Day, Month, Year, DaysOrderInYear;

	Day		= ReadDay();
	Month	= ReadMonth();
	Year	= ReadYear();
	DaysOrderInYear = DaysFromBeginningOfYear(Day, Month, Year);

	cout << "\nNumber of Days from the beginning of the year is " << DaysOrderInYear;

	sDate Date;

	cout << "Hello\n";


	system("pause>0");
	return 0;
}