#include <iostream>

using namespace std;

short ReadYear()
{
	short Year;
	cout << "Please enter a year to check? ";
	cin >> Year;
	return Year;
}

bool IsLeapYear(short Year)
{
	return(Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInAYear(short Year)
{
	return IsLeapYear(Year) ? 366 : 365;
}

short NumberOfHoursInAYear(short Year)
{
	return (NumberOfDaysInAYear(Year) * 24);
}

int NumberOfMinutesInAYear(short Year)
{
	return (NumberOfHoursInAYear(Year) * 60);
}

int NumberOfSecondsInAYear(short Year)
{
	return (NumberOfMinutesInAYear(Year) * 60);
}

void PrintNumberOfDaysHoursMinutesSeconds(short Year)
{
	
	cout << "\nNumber Of Days    in year [" << Year << "] is " << NumberOfDaysInAYear(Year) << endl;
	cout << "Number Of Hours   in year [" << Year << "] is " << NumberOfHoursInAYear(Year) << endl;
	cout << "Number Of Minutes in year [" << Year << "] is " << NumberOfMinutesInAYear(Year) << endl;
	cout << "Number Of Seconds in year [" << Year << "] is " << NumberOfSecondsInAYear(Year) << endl;

}

int main()
{
	int Year = ReadYear();
	PrintNumberOfDaysHoursMinutesSeconds(Year);


	system("pause>0");
	return 0;
}