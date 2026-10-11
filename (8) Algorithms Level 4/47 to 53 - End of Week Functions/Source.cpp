#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

struct stDate
{
	short Day;
	short Month;
	int Year;
	string DayOfWeek;
};

bool IsLeapYear(int Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsDate1BeforeDate2(stDate D1, stDate D2)
{
	return (D1.Year < D2.Year ? true : 
		(D1.Year == D2.Year ? 
			(D1.Month < D2.Month ? true : 
				(D1.Month == D2.Month ? D1.Day < D2.Day : false)) : false));
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month >12)
	{
		return 0;
	}

	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}

	short DaysPerMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return DaysPerMonth[Month-1];
}

bool IsLastDayInMonth(stDate Date)
{
	return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(short Month)
{
	return (Month == 12);
}

stDate IncreaseDateByOneDay(stDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
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

int GetDifferenceInDays(stDate D1, stDate D2, bool IncludeEndDay = false)
{
	int Days = 0;

	while (IsDate1BeforeDate2(D1, D2))
	{
		Days++;
		D1 = IncreaseDateByOneDay(D1);
	}

	return IncludeEndDay ? ++Days : Days;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayName[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return arrDayName[DayOfWeekOrder];
}

short IsEndOfWeek(stDate Date)
{
	return DayOfWeekOrder(Date) == 6;
}

bool IsWeekend(stDate Date)
{
	//Weekends are Fri and Sat
	short DayIndex = DayOfWeekOrder(Date);
	return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
	return !IsWeekend(Date);
}

short DaysUntilEndOfWeek(stDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

short DaysUntilEndOfMonth(stDate Date)
{
	stDate EndOfMonthDate;
	EndOfMonthDate.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
	EndOfMonthDate.Month = Date.Month;
	EndOfMonthDate.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfMonthDate, true);
}

short DaysUntilEndOfYear(stDate Date)
{
	stDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfYearDate, true);
}



//Read Date Functions
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
	stDate MyDate;

	MyDate.Day = ReadDay();
	MyDate.Month = ReadMonth();
	MyDate.Year = ReadYear();

	return MyDate;
}

stDate GetSystemDate()
{
	stDate Date;
	time_t t = time(0);
	tm* now = localtime(&t);

	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;

	return Date;
}


int main()
{

	stDate Date1 = GetSystemDate();



	cout << "\nToday is " << DayShortName(DayOfWeekOrder(Date1)) << ", "
			<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year << "\n";

	//---------------------------------
	cout << "\nIs it End of Week? ";
	if (IsEndOfWeek(Date1))
		cout << "Yes, it is End of Week.";
	else
		cout << "No, it is NOT End of Week.";
	
	//---------------------------------
	cout << "\nIs it a Weekend? ";
	if (IsWeekend(Date1))
		cout << "Yes, it is a Weekend.";
	else
		cout << "No, it is NOT a Weekend.";

	//---------------------------------
	cout << "\nIs it a Business Day? ";
	if(IsBusinessDay(Date1))
		cout << "Yes, it is a Business Day.";
	else
		cout << "No, it is NOT a Business Day.";


	//---------------------------------
	cout << endl;
	cout << "\nDays until end of week: " << DaysUntilEndOfWeek(Date1) << " Day(s).";
	cout << "\nDays until end of month: " << DaysUntilEndOfMonth(Date1) << " Day(s).";
	cout << "\nDays until end of year: " << DaysUntilEndOfYear(Date1) << " Day(s).";
	


	


	system("pause>0");
	return 0;
}