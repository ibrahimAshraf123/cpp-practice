#include <iostream>

using namespace std;

bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	if (Month == 2)
		return isLeapYear(Year) ? 29 : 28;

	short arrDaysOfMonths[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return arrDaysOfMonths[Month];
}

int NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
{
	short TotalDaysInYear = 0;

	for (int i = 1; i <= Month - 1; i++)
	{
		TotalDaysInYear += NumberOfDaysInAMonth(i, Year);
	}

	TotalDaysInYear += Day;

	return TotalDaysInYear;
}

short ReadValue(string Message)
{
	short Value;
	cout << Message;
	cin >> Value;
	return Value;
}

int main()
{
	short Day   = ReadValue("Please enter a Day? ");
	short Month = ReadValue("Please enter a Month? ");
	short Year  = ReadValue("Please enter a Year? ");

	cout << "\nNumber Of Days From The Beginning Of The Year is "
		<< NumberOfDaysFromTheBeginningOfTheYear(Day, Month, Year);


	system("pause>0");
	return 0;
}