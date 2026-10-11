#include <iostream>

using namespace std;

struct stDate
{
	short Day, Month, Year;
};

bool IsLeapYear(short Year)
{
	return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 0 || Month >12)
		return 0;

	if (Month == 2)
		return IsLeapYear(Year) ? 29 : 28;

	short arrMonthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return arrMonthDays[Month];
}



stDate DecreaseDateByOneDay(stDate Date)
{

	if(Date.Day == 1)
	{

		if (Date.Month == 1)
		{
			Date.Day = NumberOfDaysInMonth(12, Date.Year);
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Day = NumberOfDaysInMonth(Date.Month - 1, Date.Year);
			Date.Month--;
		}
	}
	else
	{
		Date.Day--;
	}

	return Date;
}

stDate DecreaseDateByXDays(int Days, stDate Date)
{
	for (int i = Days; i > 0; i--)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date)
{
	Date = DecreaseDateByXDays(7, Date);
	return Date;
}

stDate DecreaseDateByXWeeks(int Weeks, stDate Date)
{
	for (int i = Weeks; i > 0; i--)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

stDate DecreaseDateByOneMonth(stDate Date)
{
	//if 1st month, month = 12, year--
	//	else month--
	//if day > MaxDayInMonth, day = MaxDayInMonth

	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	short MaxDayInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
	if (Date.Day > MaxDayInMonth)
	{
		Date.Day = MaxDayInMonth;
	}

	return Date;
}

stDate DecreaseDateByXMonths(int Months, stDate Date)
{
	for (int i = Months; i > 0; i--)
	{
		Date = DecreaseDateByOneMonth(Date);
	}

	return Date;
}

stDate DecreaseDateByOneYear(stDate Date)
{
	Date.Year--;
	return Date;
}

stDate DecreaseDateByXYears(int Years, stDate Date)
{
	for(int i = Years; i > 0; i--)
	{
		Date = DecreaseDateByOneYear(Date);
	}

	return Date;
}

stDate DecreaseDateByXYearsFaster(int Years, stDate Date)
{
	Date.Year -= Years;
	return Date;
}

stDate DecreaseDateByOneDecade(stDate Date)
{
	Date.Year -= 10;
	return Date;
}

stDate DecreaseDateByXDecades(int Decades, stDate Date)
{
	for (int i = Decades; i > 0; i--)
	{
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}

stDate DecreaseDateByXDecadesFaster(int Decades, stDate Date)
{
	Date.Year -= (Decades * 10);
	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date)
{
	Date.Year -= 100;
	return Date;
}

stDate DecreaseDateByOneMillennium(stDate Date)
{
	Date.Year -= 1000;
	return Date;
}



void PrintDate(stDate Date)
{
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year;
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
	stDate Date = ReadFullDate();

	cout << "\nDate after:\n";


	Date = DecreaseDateByOneDay(Date);
	cout << "\n01 - Subtracting 1 Day is: ";
	PrintDate(Date);

	Date = DecreaseDateByXDays(10,Date);
	cout << "\n02 - Subtracting 10 Days is: ";
	PrintDate(Date);

	Date = DecreaseDateByOneWeek(Date);
	cout << "\n03 - Subtracting 1 Week is: ";
	PrintDate(Date);

	Date = DecreaseDateByXWeeks(10, Date);
	cout << "\n04 - Subtracting 10 Weeks is: ";
	PrintDate(Date);

	Date = DecreaseDateByOneMonth(Date);
	cout << "\n05 - Subtracting 1 Month is: ";
	PrintDate(Date);

	Date = DecreaseDateByXMonths(5, Date);
	cout << "\n06 - Subtracting 5 Months is: ";
	PrintDate(Date);

	Date = DecreaseDateByOneYear(Date);
	cout << "\n07 - Subtracting 1 Year is: ";
	PrintDate(Date);

	Date = DecreaseDateByXYears(10, Date);
	cout << "\n08 - Subtracting 10 Years is: ";
	PrintDate(Date);

	Date = DecreaseDateByXYearsFaster(10, Date);
	cout << "\n09 - Subtracting 10 Years (Faster) is: ";
	PrintDate(Date);

	Date = DecreaseDateByOneDecade(Date);
	cout << "\n10 - Subtracting 1 Decade is: ";
	PrintDate(Date);

	Date = DecreaseDateByXDecades(10, Date);
	cout << "\n11 - Subtracting 10 Decades is: ";
	PrintDate(Date);

	Date = DecreaseDateByXDecadesFaster(10, Date);
	cout << "\n12 - Subtracting 10 Decades (Faster) is: ";
	PrintDate(Date);

	Date = DecreaseDateByOneCentury(Date);
	cout << "\n13 - Subtracting 1 Century is: ";
	PrintDate(Date);

	Date = DecreaseDateByOneMillennium(Date);
	cout << "\n14 - Subtracting 1 Millennium is: ";
	PrintDate(Date);


	


	system("pause>0");
	return 0;
}