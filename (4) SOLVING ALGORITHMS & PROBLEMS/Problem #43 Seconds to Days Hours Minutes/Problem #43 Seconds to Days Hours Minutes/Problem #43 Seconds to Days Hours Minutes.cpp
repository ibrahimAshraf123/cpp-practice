using namespace std;

#include <iostream>

struct stSecondsConversion
{
	const int SecondsPerDay = 24 * 60 * 60;
	const int SecondsPerHour = 60 * 60;
	const int SecondsPerMinute = 60;
};

struct stDurations {
	int Days, Minutes, Hours, Seconds;	
};

int ReadPositiveNumber(string Message)
{
	int Num;

	do
	{
		cout << Message << endl;
		cin >> Num;
	} while (Num < 0);

	return Num;
}

stDurations SecondsToDurations(int TotalSeconds)
{ 
	stDurations Durations;
	stSecondsConversion SecondsConversion;

	int Remainder = 0;
	Durations.Days = floor(TotalSeconds / SecondsConversion.SecondsPerDay);
	Remainder = TotalSeconds % SecondsConversion.SecondsPerDay;

	Durations.Hours = floor(Remainder / SecondsConversion.SecondsPerHour);
	Remainder = Remainder % SecondsConversion.SecondsPerHour;

	Durations.Minutes = floor(Remainder / SecondsConversion.SecondsPerMinute);
	Remainder = Remainder % SecondsConversion.SecondsPerMinute;

	Durations.Seconds = Remainder;

	return Durations;
}

void PrintDurationDetails(stDurations Durations)
{
	cout << endl;
	cout << Durations.Days << ":" 
	 << Durations.Hours << ":"
	 << Durations.Minutes << ":"
	 << Durations.Seconds << endl;
}

int main()
{
	int TotalSeconds = ReadPositiveNumber("Please Enter Number of Seconds: ");

	PrintDurationDetails(SecondsToDurations(TotalSeconds));
	
	return 0;
}
