#include <iostream>

using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

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

bool IsDate1LessThanDate2(stDate Date1, stDate Date2)
{
	if (Date1.Year != Date2.Year)
		return Date1.Year < Date2.Year;

	if (Date1.Month != Date2.Month)
		return Date1.Month < Date2.Month;

	return Date1.Day < Date2.Day;

}

int main()
{
	stDate Date1 = ReadFullDate();
	cout << endl;

	stDate Date2 = ReadFullDate();
	cout << endl;

	string Result = IsDate1LessThanDate2(Date1, Date2) ? "Yes, Date1 is Less Than Date2" : "No, Date1 is NOT Less Than Date2";

	cout << Result;


	system("pause>0");
	return 0;
}