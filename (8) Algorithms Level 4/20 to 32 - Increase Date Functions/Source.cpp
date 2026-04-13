#include <iostream>

using namespace std;

struct stDate
{
	short Day, Month, Year;
};

bool IsLeapYear(short Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short DaysInAMonth(short Month, short Year)
{
	if (Month < 1 || Month >12)
		return 0;

	if(Month ==2)
		return IsLeapYear(Year)? 29 : 28;

	short arrDaysInMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	return arrDaysInMonth[Month];
}

bool IsLastDayInMonth(stDate Date)
{
	return  Date.Day == DaysInAMonth(Date.Month, Date.Year);
}

bool IsLastMonthInYear(short Month)
{
	return Month == 12;
}



// Increase Date Functions
stDate IncreaseDateByOneDay(stDate Date)
{
	//if last day in month, month++, day + 1
	//if last month in year, year++, Month=1, day =1

	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
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

stDate IncreaseDateByXDays(stDate Date, int IncreaseAmount)
{
	//loop for xamount, increment date

	for (int i = 0; i < IncreaseAmount; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date)
{
	Date = IncreaseDateByXDays(Date, 7);

	return Date;
}

stDate IncreaseDateByXWeeks(stDate Date, int IncreaseAmount)
{
	for (int i = 0; i < IncreaseAmount; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}

	return Date;

}

stDate IncreaseDateByOneMonth(stDate Date)
{
	if (IsLastMonthInYear(Date.Month))
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	short MaxDayInMonth = DaysInAMonth(Date.Month, Date.Year);
	if (Date.Day > MaxDayInMonth)
	{
		Date.Day = MaxDayInMonth;
	}

	return Date;
}

stDate IncreaseDateByXMonths(stDate Date, int IncreaseAmount)
{
	for (int i = 0; i < IncreaseAmount; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}

	return Date;
}

stDate IncreaseDateByOneYear(stDate Date)
{
	Date.Year++;

	return Date;
}

stDate IncreaseDateByXYears(stDate Date, int IncreaseAmount)
{
	for (int i = 0; i < IncreaseAmount; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}

	return Date;
}

stDate IncreaseDateByXYearsFaster(stDate Date, int IncreaseAmount)
{
	Date.Year += IncreaseAmount;

	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date)
{
	Date = IncreaseDateByXYearsFaster(Date, 10);

	return Date;
}

stDate IncreaseDateByXDecades(stDate Date, int IncreaseAmount)
{
	for (int i = 0; i < IncreaseAmount; i++)
	{
		Date = IncreaseDateByOneDecade(Date);
	}

	return Date;
}

stDate IncreaseDateByXDecadesFaster(stDate Date, int IncreaseAmount)
{
	Date = IncreaseDateByXYearsFaster(Date, IncreaseAmount * 10);

	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date)
{
	Date.Year += 100;

	return Date;
}

stDate IncreaseDateByOneMillennium(stDate Date)
{
	Date.Year += 1000;

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

	cout << "\nDate After: \n";

	cout << "\n01 - Adding 1 day is: ";
	Date = IncreaseDateByOneDay(Date);
	PrintDate(Date);

	cout << "\n02 - Adding 10 days is: ";
	Date = IncreaseDateByXDays(Date, 10);
	PrintDate(Date);

	cout << "\n03 - Adding 1 week is: ";
	Date = IncreaseDateByOneWeek(Date);
	PrintDate(Date);

	cout << "\n04 - Adding 10 weeks is: ";
	Date = IncreaseDateByXWeeks(Date, 10);
	PrintDate(Date);

	cout << "\n05 - Adding 1 month is: ";
	Date = IncreaseDateByOneMonth(Date);
	PrintDate(Date);

	cout << "\n06 - Adding 5 months is: ";
	Date = IncreaseDateByXMonths(Date, 5);
	PrintDate(Date);

	cout << "\n07 - Adding 1 year is: ";
	Date = IncreaseDateByOneYear(Date);
	PrintDate(Date);

	cout << "\n08 - Adding 10 years is: ";
	Date = IncreaseDateByXYears(Date, 10);
	PrintDate(Date);

	cout << "\n09 - Adding 10 years (faster) is: ";
	Date = IncreaseDateByXYearsFaster(Date, 10);
	PrintDate(Date);

	cout << "\n10 - Adding 1 decade is: ";
	Date = IncreaseDateByOneDecade(Date);
	PrintDate(Date);

	cout << "\n11 - Adding 10 decades is: ";
	Date = IncreaseDateByXDecades(Date,10);
	PrintDate(Date);

	cout << "\n12 - Adding 10 decades (faster) is: ";
	Date = IncreaseDateByXDecadesFaster(Date, 10);
	PrintDate(Date);

	cout << "\n13 - Adding 1 century is: ";
	Date = IncreaseDateByOneCentury(Date);
	PrintDate(Date);

	cout << "\n14 - Adding 1 millennium is: ";
	Date = IncreaseDateByOneMillennium(Date);
	PrintDate(Date);

	system("pause>0");
	return 0;
}