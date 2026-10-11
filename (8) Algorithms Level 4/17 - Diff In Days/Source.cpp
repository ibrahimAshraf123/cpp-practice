#include <iostream>

using namespace std;

struct stDate
{
	short Day, Month, Year;
};

bool IsLeapYear(short Year)
{
	return (Year % 400 == 0 && Year % 100 != 0) || (Year % 4 == 0);
}

bool IsDate1BeforeDate2(stDate D1, stDate D2)
{
	return	(D1.Year < D2.Year) ? true : ((D1.Year == D2.Year) ?
		D1.Month < D2.Month ? true : (D1.Month == D2.Month ?
			D1.Day < D2.Day : false) : false);
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month >12)
		return 0;

	if (Month == 2)
		return IsLeapYear(Year) ? 29 : 28;

	short arrMonthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return arrMonthDays[Month];
}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

stDate IncrementDate(stDate Date)
{
	//if last day in month, month++, date = 1
	//if last month in year, year++, month = 1, day = 1

	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Year++;
			Date.Day = 1;
			Date.Month = 1;
			return Date;
		}
		Date.Month++;
		Date.Day = 1;
		return Date;
	}
	
	Date.Day++;
	return Date;
}

short DateDiffInDays(stDate D1, stDate D2, bool IncludeLastDay = false)
{
	short DayDiff = 0;

	//while D1 < D2, DayDiff ++, IncerementDate(D1)
	while (IsDate1BeforeDate2(D1, D2))
	{
		DayDiff++;
		D1 = IncrementDate(D1);
	}

	return IncludeLastDay ? ++DayDiff : DayDiff;
}

short ReadDay()
{
	short Day;
	cout << "Please enter a day? ";
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

int main()
{
	stDate D1 = ReadFullDate();
	cout << endl;

	stDate D2 = ReadFullDate();
	cout << endl;

	cout << "\nDiffrence is : ";
	cout << DateDiffInDays(D1, D2) << " Day(s).\n";

	cout << "\nIncluding end day, Diffrence is : ";
	cout << DateDiffInDays(D1, D2, true) << " Day(s).\n";


	system("pause>0");
	return 0;
}