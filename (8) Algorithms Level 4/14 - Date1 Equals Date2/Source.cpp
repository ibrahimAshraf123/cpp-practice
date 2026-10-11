#include <iostream>

using namespace std;


struct stDate
{
	short Day;
	short Month;
	short Year;
};

bool IsDate1EqualDate2(stDate D1, stDate D2)
{
	return (D1.Year == D2.Year) ? (D1.Month == D2.Month)? (D1.Day == D2.Day) : false : false;
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
	stDate D1 = ReadFullDate();
	cout << endl;

	stDate D2 = ReadFullDate();
	cout << endl;


	if (IsDate1EqualDate2(D1, D2))
		cout << "\nYes, Date 1 is equal to Date 2.";
	else
		cout << "\nNo, Date 1 is NOT equal to Date 2.";


	system("pause>0");
	return 0;
}