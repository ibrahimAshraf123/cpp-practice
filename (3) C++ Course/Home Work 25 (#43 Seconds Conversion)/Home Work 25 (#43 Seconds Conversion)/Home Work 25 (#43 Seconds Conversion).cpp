
#include <iostream>

using namespace std;

void SecondsConversionProcedure(long long totalSeconds) {
	float days = totalSeconds / (24 * 60 * 60);
	totalSeconds %= (24 * 60 * 60);

	float hours = totalSeconds / (60 * 60);
	totalSeconds %= (60 * 60);

	float minutes = totalSeconds / 60;
	float seconds = totalSeconds;
	cout << days << " days\n" << hours << " hours\n" << minutes << " minutes\n" << seconds << " seconds\n";

	return;
}

int main()
{
	long long myTotalSeconds;
	cout << "This program prints \"Seconds to Days Hours Minutes and Seconds\"... \n";
	cout << "Please enter your total seconds: \n";
	cin >> myTotalSeconds;

	cout << "\n*************************************\n";
	cout << "Results: \n";
	SecondsConversionProcedure(myTotalSeconds);

	return 0;
}
