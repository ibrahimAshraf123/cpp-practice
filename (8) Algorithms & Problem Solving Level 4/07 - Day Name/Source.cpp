#include <iostream>

using namespace std;


short ReadYear()
{
	short Year;
	cout << "Please enter a year? ";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month;
	cout << "Please enter a Month? ";
	cin >> Month;
	return Month;
}

short ReadDay()
{
	short Day;
	cout << "Please enter a Day? ";
	cin >> Day;
	return Day;
}

short DayOfWeekOrder(short Year, short Month, short Day)
{
	short a,  y,  m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	//Gregorian Calendar Day Index
	return (Day + y + y / 4 - y / 100 + y / 400 + (31 * m )/ 12) % 7;

}

string DayShortName(short DayOfWeekOrder)
{
	string arrGregorianCalendar[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
	return arrGregorianCalendar[DayOfWeekOrder];
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();


	cout << "\n";
	cout << "Date      :" << Day << "/" << Month << "/" << Year << endl;
	cout << "Day Order :" << DayOfWeekOrder(Year,Month,Day) << endl;
	cout << "Day Name  :" << DayShortName(DayOfWeekOrder(Year, Month, Day)) << endl;

	system("pause>0");
	return 0;
}