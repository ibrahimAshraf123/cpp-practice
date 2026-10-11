#include <iostream>
#include <ctime>
#pragma warning(disable:4996) // Disable deprecation warning for localtime

using namespace std;

int main()
{
	time_t t = time(0);
	tm* now = localtime(&t);

	cout << "Year: " << now->tm_year + 1900 << endl;
	cout << "Month: " << now->tm_mon + 1 << endl;
	cout << "Day: " << now->tm_mday << endl;
	cout << "Hour: " << now->tm_hour << endl;
	cout << "Minute: " << now->tm_min << endl;
	cout << "Second: " << now->tm_sec << endl;
	cout << "Weekday: " << now->tm_wday << endl;
	cout << "Year day: " << now->tm_yday << endl;
	cout << "Is DST: " << now->tm_isdst << endl;
	cout << "Timestamp: " << t << endl;




	return 0;
}