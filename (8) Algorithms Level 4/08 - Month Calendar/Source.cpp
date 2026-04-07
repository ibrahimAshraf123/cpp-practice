#include <iostream>

using namespace std;

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)/ 12)) % 7;
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[DayOfWeekOrder];
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month >12)
		return 0;

	if (Month == 2)
	{
		return isLeapYear ? 29 : 28;
	}

	short arrDaysInMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return arrDaysInMonth[Month];
}

string MonthShortName(short Month)
{

	string NameOfMonths[] = 
	{ 
		"",
		"Jan","Feb","Mar",
		"Apr","May","Jun",
		"Jul","Aug","Sep",
		"Oct","Nov","Dec" 
	};
	return NameOfMonths[Month];
}

void PrintMonthCalendar(short Month, short Year)
{

	int NumberOfDays;

	//Index of the day from 0 to 6
	int current = DayOfWeekOrder(1, Month, Year);

	NumberOfDays = NumberOfDaysInMonth(Month, Year);

	// Print the current month name
	printf("\n _______________%s_______________\n\n",
		MonthShortName(Month).c_str());

	// Print the columns
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	// Print appropriate spaces
	int i;
	for (i = 0; i < current; i++)
		printf("     ");

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}

	printf("\n _________________________________\n");
}

short ReadMonth()
{
	short Month;
	cout << "Please enter a month? ";
	cin >> Month;
	return Month;
}

short ReadYear()
{
	short Year;
	cout << "Please enter a year? ";
	cin >> Year;
	return Year;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	PrintMonthCalendar(Month, Year);

	system("pause>0");
	return 0;
}