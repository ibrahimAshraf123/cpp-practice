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
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool IsDate1BeforeDate2(stDate D1, stDate D2)
{
	return (D1.Year < D2.Year ? true : (D1.Year == D2.Year ? D1.Month < D2.Month ? true : (D1.Month == D2.Month ? D1.Day < D2.Day : false) : false));
}

short NumberOfDaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
		return 0;

	if (Month == 2)
		return (IsLeapYear(Year) ? 29 : 28);

	short arrDaysInAMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return arrDaysInAMonth[Month];
}

bool IsLastDayInMonth(stDate Date)
{
	return Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year);
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
			Date.Year++;
			Date.Month = 1;
			Date.Day = 1;
		}
		else
		{
			Date.Month++;
			Date.Day = 1;
		}
	}
	else
	{
		Date.Day++;
	}

	return Date;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	short a, y, m;

	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;

	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string DayShortName(short DayOfWeekOrder)
{
	string arrDayNames[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	return arrDayNames[DayOfWeekOrder];
}

bool IsWeekend(stDate Date)
{
	short DayIndex = DayOfWeekOrder(Date);

	return (DayIndex == 5 || DayIndex == 6);
}

bool IsBusinessDay(stDate Date)
{
	return !(IsWeekend(Date));
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
	stDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();

	return Date;
}

short ReadVacationDays()
{
	short VacationDays = 0;
	cout << "Please enter Vacation Days? ";
	cin >> VacationDays;
	return VacationDays;
}



//Calculate Vacation
short CalculateVacationDays(stDate DateFrom, stDate DateTo)
{
	short DaysCount = 0;

	while (IsDate1BeforeDate2(DateFrom, DateTo))
	{
		if (IsBusinessDay(DateFrom))
		{
			DaysCount++;
		}
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	return DaysCount;
}

stDate CalculateVacationReturnDate(stDate DateFrom, short VacationDays)
{
	stDate ReturnDate = DateFrom;

	while (VacationDays > 0)
	{
		if(IsBusinessDay(ReturnDate))
		{
			VacationDays--;
		}
		
		ReturnDate = IncreaseDateByOneDay(ReturnDate);
	}

	return ReturnDate;
}

stDate CalculateVacationReturnDate_func2(stDate DateFrom, short VacationDays)
{
	short WeekEndCounter = 0;

	//in case data is weekend keep incrementing until you reach business day
	//we get rid of all weekends before the 1st business day
	while (IsWeekend(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	//increase the vacation dates to add all weekends to it

	for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
	{
		if (IsWeekend(DateFrom))
		{
			WeekEndCounter++;
		}

		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	//in case return date is weekend, keep incrementing until you reach business day
	while (IsWeekend(DateFrom))
	{
		DateFrom = IncreaseDateByOneDay(DateFrom);
	}

	return DateFrom;
}

int main()
{
	cout << "Vacation starts: " << endl;
	stDate DateFrom = ReadFullDate();

	cout << endl;
	short VacationDays = ReadVacationDays();

	stDate ReturnDate = CalculateVacationReturnDate_func2(DateFrom, VacationDays);


	cout << "\nReturn Date: " << DayShortName(DayOfWeekOrder(ReturnDate)) << ", " << ReturnDate.Day << "/" << ReturnDate.Month << "/" << ReturnDate.Year;

	system("pause>0");
	return 0;
}