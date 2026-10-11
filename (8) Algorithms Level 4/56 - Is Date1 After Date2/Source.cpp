#include <iostream>

using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};


bool IsDate1BeforeDate2(stDate D1, stDate D2)
{
	return (D1.Year < D2.Year) ? true : ((D1.Year == 
		D2.Year) ? (D1.Month < D2.Month ? true : (D1.Month == D2.Month ?
		D1.Day < D2.Day : false)) : false);
}

bool IsDate1EqualDate2(stDate D1, stDate D2)
{
	return (D1.Year == D2.Year) ? ((D1.Month == D2.Month) ? ((D1.Day == D2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate D1, stDate D2)
{
	return (!IsDate1BeforeDate2(D1, D2) && !IsDate1EqualDate2(D1, D2));
}

//Read Date Funcs
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
	stDate D1, D2;

	cout << "Enter Date1: " << endl;
	D1 = ReadFullDate();
	cout << endl;

	cout << "Enter Date2: " << endl;
	D2 = ReadFullDate();
	cout << endl;

	if (IsDate1AfterDate2(D1, D2))
	{
		cout << "Yes, Date1 is After Date2." << endl;
	}
	else
	{
		cout << "No, Date1 is NOT After Date2." << endl;
	}

	system("pause>0");
	return 0;
}