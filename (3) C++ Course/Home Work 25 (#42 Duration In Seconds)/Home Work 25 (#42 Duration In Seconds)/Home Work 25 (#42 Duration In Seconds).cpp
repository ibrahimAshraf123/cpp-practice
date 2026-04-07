
#include <iostream>

using namespace std;

long long DurationInSecondsFunction(double days, double hours, double minutes, double seconds) {
	double totalSeconds = (days * 24 * 60 * 60) + (hours * 60 * 60) + (minutes * 60) + seconds;
	return totalSeconds;
}

int main()
{
	double d, h, m, s;
	cout << "This program calculates \"Task Duration In Seconds\"...\n";
	cout << "Please enter days, hours, minutes, seconds: \n";
	cin >> d >> h >> m >> s;
	cout << "\n";
	cout << "Result: \n" << DurationInSecondsFunction(55, 44, 66, 22) << " Seconds \n";
	return 0;
}
