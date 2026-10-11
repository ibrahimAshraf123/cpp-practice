#pragma warning(disable : 4996)
#pragma once
#include <iostream>
#include <string>
#include "clsString.h";
#include "clsDate.h";

using namespace std;

class clsPeriod
{
public:
	clsDate StartDate;
	clsDate FinishDate;
	
	//constructor
	clsPeriod(clsDate StartDate, clsDate FinishDate)
	{
		this->StartDate = StartDate;
		this->FinishDate = FinishDate;
	};


	//get & set properties
	void SetStartDate(clsDate Date)
	{
		StartDate = Date;
	};

	clsDate GetStartDate()
	{
		return StartDate;
	};

	__declspec(property(get = GetStartDate, put = SetStartDate)) clsDate Date;

	void SetFinishDate(clsDate Date)
	{
		FinishDate = Date;
	};

	clsDate GetFinishDate()
	{
		return FinishDate;
	};

	__declspec(property(get = GetFinishDate, put = SetFinishDate)) clsDate Date;


	//period functions
	void Print()
	{
		cout << "Period Start: ";
		StartDate.Print();


		cout << "Period End: ";
		FinishDate.Print();
	}

	static bool IsPeriodsOverlap(clsPeriod Period1, clsPeriod Period2)
	{
		if (
			clsDate::CompareDates(Period2.FinishDate, Period1.StartDate) == clsDate::enDateCompare::Before
			||
			clsDate::CompareDates(Period2.StartDate, Period1.FinishDate) == clsDate::enDateCompare::After
			)
			return false;
		else
			return true;
	};

	bool IsPeriodsOverlap(clsPeriod Period2)
	{
		return IsPeriodsOverlap(*this, Period2);
	};

	static short PeriodLengthInDays(clsPeriod Period, bool IncludeEndDate = false)
	{
		return clsDate::GetDifferenceInDays(Period.StartDate, Period.FinishDate, IncludeEndDate);
	};

	short PeriodLengthInDays()
	{
		return PeriodLengthInDays(*this);
	};

	static bool SearchDateWithinPeriod(clsPeriod Period, clsDate DateToCheck)
	{

		while (!clsDate::IsDate1EqualDate2(Period.StartDate, Period.FinishDate))
		{
			if (clsDate::IsDate1EqualDate2(Period.StartDate, DateToCheck))
				return true;
			Period.StartDate = clsDate::IncreaseDateByOneDay(Period.StartDate);
		}

		return false;
	};

	bool SearchDateWithinPeriod(clsDate DateToCheck)
	{
		return SearchDateWithinPeriod(*this, DateToCheck);
	};

	static bool IsDateInPeriod(clsDate Date, clsPeriod Period)
	{
		return !(clsDate::CompareDates(Date, Period.StartDate) == clsDate::enDateCompare::Before)
			||
			(clsDate::CompareDates(Date, Period.FinishDate) == clsDate::enDateCompare::After);
	};

	bool IsDateInPeriod(clsDate Date)
	{
		return IsDateInPeriod(Date, *this);
	};

	static short CountOverLapDays(clsPeriod Period1, clsPeriod Period2)
	{

		int Period1Length = PeriodLengthInDays(Period1, true);
		int Period2Length = PeriodLengthInDays(Period2, true);
		int OverlapDays = 0;

		if (!IsPeriodsOverlap(Period1, Period2))
			return 0;

		if (Period1Length < Period2Length)
		{
			while (clsDate::IsDate1BeforeDate2(Period1.StartDate, Period1.FinishDate))
			{
				if (IsDateInPeriod(Period1.StartDate, Period2))
					OverlapDays++;

				Period1.StartDate = clsDate::IncreaseDateByOneDay(Period1.StartDate);
			}
		}
		else
		{
			while (clsDate::IsDate1BeforeDate2(Period2.StartDate, Period2.FinishDate))
			{
				if (IsDateInPeriod(Period2.StartDate, Period1))
					OverlapDays++;

				Period2.StartDate = clsDate::IncreaseDateByOneDay(Period2.StartDate);
			}
		}

		return OverlapDays;
	};

	short CountOverLapDays(clsPeriod Period2)
	{
		return CountOverLapDays(*this, Period2);
	};


};

