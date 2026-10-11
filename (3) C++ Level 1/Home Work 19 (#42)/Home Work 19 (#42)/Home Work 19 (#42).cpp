
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int days, hours, minutes, seconds;
	cout << "This program gives \"Task Duration In Seconds\"... \n";
	cout << "please enter days, hours , minutes and seconds: \n";
	cout << "days? \n";
	cin >> days;
	cout << "hours? \n";
	cin >> hours;
	cout << "minutes? \n";
	cin >> minutes;
	cout << "seconds? \n";
	cin >> seconds;

	int totalSeconds = (days * 24 * 60 * 60) + (hours * 60 * 60) + (minutes * 60) + seconds;

	cout << "Result: \n";
	cout << round(totalSeconds) << " Seconds \n";

	return 0;
}
