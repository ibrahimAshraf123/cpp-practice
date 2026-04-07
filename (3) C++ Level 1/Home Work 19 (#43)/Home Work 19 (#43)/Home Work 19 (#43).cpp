
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long totalSeconds;
	cout << "This program converts \"Seconds to Days Hours Minutes Seconds\"...\n";
	cout << "Please enter total seconds: ";
	cin >> totalSeconds;
	cout << "\n";

	int days = totalSeconds / (24 * 60 * 60);
	totalSeconds %= (24 * 60 * 60);

	int hours = totalSeconds / (60 * 60);
	totalSeconds %= (60 * 60);

	int minutes = totalSeconds / 60;
	int seconds = totalSeconds % 60;

	cout << "Results: \n";
	cout << round(days) << " days \n";
	cout << round(hours) << " hours \n";
	cout << round(minutes) << " minutes \n";
	cout << round(seconds) << " seconds \n";

	return 0;
}
