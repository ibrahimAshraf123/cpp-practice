#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <string>
#include "clsString.h";

using namespace std;

class clsDate
{
private:
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:


	//Constructors

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;
		
	};

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	};

	clsDate(string sDate)
	{
		*this = StringToDate(sDate);
	};

	clsDate(short DaysOrderInYear, short Year)
	{
		*this = GetDateFromDayOrderInYear(DaysOrderInYear, Year);
	}

	//Get & Set Properties
	void SetDay(short Day)
	{
		_Day = Day;
	};

	short GetDay()
	{
		return _Day;
	};

	__declspec(property(get = GetDay, put = SetDay))short Day;

	void SetMonth(short Month)
	{
		_Month = Month;
	};

	short GetMonth()
	{
		return _Month;
	};

	__declspec(property(get = GetMonth, put = SetMonth))short Month;

	void SetYear(short Year)
	{
		_Year = Year;
	};

	short GetYear()
	{
		return _Year;
	};

	__declspec(property(get = GetYear, put = SetYear))short Year;

	//Date functions
	static void Print(clsDate Date)
	{
		cout << DateToString(Date) << endl;
		
	};

	void Print()
	{
		cout << DateToString(*this) << endl;
	};

	static clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;
		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		return clsDate(Day, Month, Year);
	};

	static string DateToString(clsDate Date)
	{
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	};

	string  DateToString()
	{
		return DateToString(*this);
	};

	static clsDate StringToDate(string DateString)
	{
		clsDate Date;
		vector <string> vDate;

		vDate = clsString::Split(DateString, "/");
		Date._Day = stoi(vDate[0]);
		Date._Month = stoi(vDate[1]);
		Date._Year = stoi(vDate[2]);

		return Date;
	};

	static bool IsLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	};

	static short NumberOfDaysInMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;

		short NumberOfDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month];
	};

	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Month, _Year);
	};

	static short DayOfWeekOrder(short Year, short Month, short Day)
	{
		short a, y, m;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		//Gregorian Calendar Day Index
		return (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

	}

	static short DayOfWeekOrder(clsDate Date)
	{
		return DayOfWeekOrder(Date._Year, Date._Month, Date._Day);
	};

	short DayOfWeekOrder()
	{
		return DayOfWeekOrder(_Year, _Month, _Day);
	};

	static string DayShortName(short DayOfWeekOrder)
	{
		string arrGregorianCalendar[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
		return arrGregorianCalendar[DayOfWeekOrder];
	};

	string DayShortName()
	{
		return DayShortName(DayOfWeekOrder());
	};

	static string MonthShortName(short Month)
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
	};

	string MonthShortName()
	{
		return MonthShortName(_Month);
	};

	static void PrintMonthCalendar(short Month, short Year)
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

	void PrintMonthCalendar()
	{
		return PrintMonthCalendar(_Month, _Year);
	};

	static void PrintYearCalendar(short Year)
	{

		printf("\n _________________________________\n\n");
		printf("         Calendar - %d         ", Year);
		printf("\n _________________________________\n");

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
	};

	void PrintYearCalendar()
	{
		return PrintYearCalendar(_Year);
	}

	static int DaysFromBeginningOfYear(short Day, short Month, short Year)
	{
		short TotalDaysInYear = 0;

		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDaysInYear += NumberOfDaysInMonth(i, Year);
		}

		TotalDaysInYear += Day;

		return TotalDaysInYear;
	}

	int DaysFromBeginningOfYear()
	{
		return  DaysFromBeginningOfYear(_Day, _Month, _Year);
	}

	static clsDate GetDateFromDayOrderInYear(short DaysOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DaysOrderInYear;
		short MonthDays = 0;

		Date._Year = Year;
		Date._Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Date._Month, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;

	}
	
	void GetDateFromDayOrderInYear(short DaysOrderInYear)
	{
		*this = GetDateFromDayOrderInYear(DaysOrderInYear, _Year);
	}

	static clsDate DateAddDays(short Days, clsDate Date)
	{
		short RemainingDays = Days + DaysFromBeginningOfYear(Date._Day, Date._Month, Date._Year);
		short MonthDays = 0;

		Date._Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Date._Month, Date._Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
				if (Date._Month > 12)
				{
					Date._Month = 1;
					Date._Year++;
				}
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	void DateAddDays(short Days)
	{
		*this = DateAddDays(Days, *this);
	}

	static bool IsDate1LessThanDate2(clsDate Date1, clsDate Date2)
	{
		if (Date1._Year != Date2._Year)
			return Date1._Year < Date2._Year;

		if (Date1._Month != Date2._Month)
			return Date1._Month < Date2._Month;

		return Date1._Day < Date2._Day;

	};

	bool IsDateLessThanDate2(clsDate Date2)
	{
		return IsDate1LessThanDate2(*this, Date2);
	};

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year == Date2._Year) ? (Date1._Month == Date2._Month) ? (Date1._Day == Date2._Day) : false : false;
	};

	bool IsDateEqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	};

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date._Day == NumberOfDaysInMonth(Date._Month, Date._Year));

	};

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return Month == 12;
	};

	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static void IncrementDate(clsDate& Date)
	{

		//if last day in month && month is last month of year, year++,month=1, day=1.

		if (IsLastDayInMonth(Date) && IsLastMonthInYear(Date._Month))
		{
			Date._Year++;
			Date._Day = 1;
			Date._Month = 1;
		}

		//if last day in month && month is NOT last month of year, month++, day=1.

		else if (IsLastDayInMonth(Date) && !IsLastMonthInYear(Date._Month))
		{
			Date._Day = 1;
			Date._Month++;
		}

		//if NOT last day in month, day++.

		else if (!IsLastDayInMonth(Date))
		{
			Date._Day++;
		}
	}

	void IncrementDate()
	{
		IncrementDate(*this);
	};

	static bool IsDate1BeforeDate2(clsDate D1, clsDate D2)
	{
		return	(D1._Year < D2._Year) ? true : ((D1._Year == D2._Year) ?
			D1._Month < D2._Month ? true : (D1._Month == D2._Month ?
				D1._Day < D2._Day : false) : false);
	};

	bool IsDate1BeforeDate2(clsDate D2)
	{
		return IsDate1BeforeDate2(*this, D2);
	}
	
	static short DateDiffInDays(clsDate D1, clsDate D2, bool IncludeLastDay = false)
	{
		short DayDiff = 0;

		//while D1 < D2, DayDiff ++, IncerementDate(D1)
		while (IsDate1BeforeDate2(D1, D2))
		{
			DayDiff++;
			IncrementDate(D1);
		}

		return IncludeLastDay ? ++DayDiff : DayDiff;
	}

	short DateDiffInDays(clsDate D2, bool IncludeLastDay = false)
	{
		return DateDiffInDays(*this, D2, IncludeLastDay);
	};

	static void SwapDates(clsDate& D1, clsDate& D2)
	{
		// tempD = D1, D1 = D2, D2 = tempD

		clsDate TempDate;

		TempDate._Day = D1._Day;
		TempDate._Month = D1._Month;
		TempDate._Year = D1._Year;

		D1._Day = D2._Day;
		D1._Month = D2._Month;
		D1._Year = D2._Year;

		D2._Day = TempDate._Day;
		D2._Month = TempDate._Month;
		D2._Year = TempDate._Year;

	};

	void SwapDates(clsDate& D2)
	{
		return SwapDates(*this, D2);
	};

	static clsDate IncreaseDateByOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Day = 1;
				Date._Month = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}

		return Date;
	};

	void IncreaseDateByOneDay()
	{
		*this = IncreaseDateByOneDay(*this);
	};

	static int GetDifferenceInDays(clsDate D1, clsDate D2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(D1, D2))
		{
			//Swap Dates
			SwapDates(D1, D2);
			SwapFlagValue = -1;
		}


		while (IsDate1BeforeDate2(D1, D2))
		{
			Days++;
			D1 = IncreaseDateByOneDay(D1);
		}

		return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}

	int GetDifferenceInDays(clsDate D2, bool IncludeEndDay = false)
	{
		return  GetDifferenceInDays(*this, D2, IncludeEndDay);
	};

	static short CalculateMyAge(clsDate DateOfBirth)
	{
		clsDate SystemDate = GetSystemDate();

		return DateDiffInDays(DateOfBirth, SystemDate, true);
	};


	// Increase Date Functions
	static clsDate IncreaseDateByXDays(clsDate& Date, int IncreaseAmount)
{
	//loop for xamount, increment date

	for (int i = 0; i < IncreaseAmount; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}

	return Date;
}
	
	void IncreaseDateByXDays(int IncreaseAmount)
	{
		IncreaseDateByXDays(*this, IncreaseAmount);
	};

	static clsDate IncreaseDateByOneWeek(clsDate& Date)
{
	Date = IncreaseDateByXDays(Date, 7);

	return Date;
}
	
	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	};

	static clsDate IncreaseDateByXWeeks(clsDate& Date, int IncreaseAmount)
{
	for (int i = 0; i < IncreaseAmount; i++)
	{
		Date = IncreaseDateByOneWeek(Date);
	}

	return Date;

}
	
	void IncreaseDateByXWeeks(int IncreaseAmount)
	{
		IncreaseDateByXWeeks(*this, IncreaseAmount);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date)
{
	if (IsLastMonthInYear(Date._Month))
	{
		Date._Month = 1;
		Date._Year++;
	}
	else
	{
		Date._Month++;
	}

	short MaxDayInMonth = NumberOfDaysInMonth(Date._Month, Date._Year);
	if (Date._Day > MaxDayInMonth)
	{
		Date._Day = MaxDayInMonth;
	}

	return Date;
}
	
	void IncreaseDateByOneMonth()
	{
		IncreaseDateByOneMonth(*this);
	};

	static clsDate IncreaseDateByXMonths(clsDate& Date, int IncreaseAmount)
{
	for (int i = 0; i < IncreaseAmount; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}

	return Date;
}
	
	void IncreaseDateByXMonths(int IncreaseAmount)
	{
		IncreaseDateByXMonths(*this, IncreaseAmount);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date)
{
	Date._Year++;

	return Date;
}
	
	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	};

	static clsDate IncreaseDateByXYears(clsDate& Date, int IncreaseAmount)
{
	Date._Year += IncreaseAmount;

	return Date;
}
	
	void IncreaseDateByXYears(int IncreaseAmount)
	{
		IncreaseDateByXYears(*this, IncreaseAmount);
	};

	static clsDate IncreaseDateByOneDecade(clsDate& Date)
{
	Date = IncreaseDateByXYears(Date, 10);

	return Date;
}
	
	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	};

	static clsDate IncreaseDateByXDecades(clsDate& Date, int IncreaseAmount)
{
	Date = IncreaseDateByXYears(Date, IncreaseAmount * 10);

	return Date;
}
	
	void IncreaseDateByXDecades(int IncreaseAmount)
	{
		IncreaseDateByXDecades(*this, IncreaseAmount);
	};

	static clsDate IncreaseDateByOneCentury(clsDate& Date)
{
	Date._Year += 100;

	return Date;
}
	
	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	};

	static clsDate IncreaseDateByOneMillennium(clsDate& Date)
{
	Date._Year += 1000;

	return Date;
}
	
	void IncreaseDateByOneMillennium()
	{
		IncreaseDateByOneMillennium(*this);
	};


	// Decrease Date Functions
	static clsDate DecreaseDateByOneDay(clsDate& Date)
	{

		if (Date._Day == 1)
		{

			if (Date._Month == 1)
			{
				Date._Day = NumberOfDaysInMonth(12, Date._Year);
				Date._Month = 12;
				Date._Year--;
			}
			else
			{
				Date._Day = NumberOfDaysInMonth(Date._Month - 1, Date._Year);
				Date._Month--;
			}
		}
		else
		{
			Date._Day--;
		}

		return Date;
	}

	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(int Days, clsDate& Date)
	{
		for (int i = Days; i > 0; i--)
		{
			Date = DecreaseDateByOneDay(Date);
		}

		return Date;
	}

	void DecreaseDateByXDays(int Days)
	{
		DecreaseDateByXDays(Days, *this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date)
	{
		Date = DecreaseDateByXDays(7, Date);
		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(int Weeks, clsDate& Date)
	{
		for (int i = Weeks; i > 0; i--)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void DecreaseDateByXWeeks(int Weeks)
	{
		DecreaseDateByXWeeks(Weeks, *this);
	};

	static clsDate DecreaseDateByOneMonth(clsDate& Date)
	{
		//if 1st month, month = 12, year--
		//	else month--
		//if day > MaxDayInMonth, day = MaxDayInMonth

		if (Date._Month == 1)
		{
			Date._Month = 12;
			Date._Year--;
		}
		else
		{
			Date._Month--;
		}

		short MaxDayInMonth = NumberOfDaysInMonth(Date._Month, Date._Year);
		if (Date._Day > MaxDayInMonth)
		{
			Date._Day = MaxDayInMonth;
		}

		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(int Months, clsDate& Date)
	{
		for (int i = Months; i > 0; i--)
		{
			Date = DecreaseDateByOneMonth(Date);
		}

		return Date;
	}

	void DecreaseDateByXMonths(int Months)
	{
		DecreaseDateByXMonths(Months, *this);
	};

	static clsDate DecreaseDateByOneYear(clsDate& Date)
	{
		Date._Year--;
		return Date;
	}

	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(int Years, clsDate& Date)
	{
		Date._Year -= Years;
		return Date;
	}

	void DecreaseDateByXYears(int Years)
	{
		DecreaseDateByXYears(Years, *this);
	};

	static clsDate DecreaseDateByOneDecade(clsDate& Date)
	{
		Date._Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	};

	static clsDate DecreaseDateByXDecades(int Decades, clsDate& Date)
	{
		Date._Year -= (Decades * 10);
		return Date;
	}

	void DecreaseDateByXDecades(int Decades)
	{
		DecreaseDateByXDecades(Decades, *this);
	};

	static clsDate DecreaseDateByOneCentury(clsDate& Date)
	{
		Date._Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate& Date)
	{
		Date._Year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	};


	// End of week functions
	static short IsEndOfWeek(clsDate Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}

	short IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	};

	static bool IsWeekend(clsDate Date)
	{
		//Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}

	bool IsWeekend()
	{
		return IsWeekend(*this);
	};

	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekend(Date);
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	};
	
	static short DaysUntilEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}

	short DaysUntilEndOfWeek()
	{
		return DaysUntilEndOfWeek(*this);
	};

	static short DaysUntilEndOfMonth(clsDate Date)
	{
		clsDate EndOfMonthDate;
		EndOfMonthDate._Day = NumberOfDaysInMonth(Date._Month, Date._Year);
		EndOfMonthDate._Month = Date._Month;
		EndOfMonthDate._Year = Date._Year;

		return GetDifferenceInDays(Date, EndOfMonthDate, true);
	}

	short DaysUntilEndOfMonth()
	{
		return DaysUntilEndOfMonth(*this);
	};

	static short DaysUntilEndOfYear(clsDate Date)
	{
		clsDate EndOfYearDate;
		EndOfYearDate._Day = 31;
		EndOfYearDate._Month = 12;
		EndOfYearDate._Year = Date._Year;

		return GetDifferenceInDays(Date, EndOfYearDate, true);
	}

	short DaysUntilEndOfYear()
	{
		return DaysUntilEndOfYear(*this);
	}


	// Calculate Vacation days functions
	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
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

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
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
	};

	void CalculateVacationReturnDate(short VacationDays)
	{
		CalculateVacationReturnDate(*this, VacationDays);
	};

	static bool IsDate1AfterDate2(clsDate D1, clsDate D2)
	{
		return (!IsDate1BeforeDate2(D1, D2) && !IsDate1EqualDate2(D1, D2));
	}

	bool IsDateAfterDate2(clsDate D2)
	{
		return IsDate1AfterDate2(*this, D2);
	};

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		// Before = -1, Equal = 0, After = 1

		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	};

	enDateCompare CompareDates(clsDate Date2)
	{
		return CompareDates(*this, Date2);
	};


	// Validate date functions
	static bool IsValidDay(clsDate Date)
	{
		return (Date._Day > 0 && Date._Day <= NumberOfDaysInMonth(Date._Month, Date._Year));
	}

	bool IsValidDay()
	{
		return IsValidDay(*this);
	};

	static bool IsValidMonth(short Month)
	{
		return (Month > 0 && Month <= 12);
	}

	bool IsValidMonth()
	{
		return IsValidMonth(_Month);
	};

	static bool IsValidDate(clsDate Date)
	{
		//validate day, month, year

		if (!IsValidDay(Date))
			return false;

		if (!IsValidMonth(Date._Month))
			return false;

		if (Date._Year <= 0)
			return false;

		return true;
	}

	bool IsValidDate()
	{
		return IsValidDate(*this);
	};


	// Format date
	static string FormatDate(clsDate Date, string DateFormat = "dd/mm/yyyy")
	{
		string FormattedDateString = "";

		FormattedDateString = clsString::ReplaceWord(DateFormat, "dd", to_string(Date._Day));
		FormattedDateString = clsString::ReplaceWord(FormattedDateString, "mm", to_string(Date._Month));
		FormattedDateString = clsString::ReplaceWord(FormattedDateString, "yyyy", to_string(Date._Year));

		return FormattedDateString;
	}

	string FormatDate(string DateFormat = "dd/mm/yyyy")
	{
		return FormatDate(*this, DateFormat);
	};


};

