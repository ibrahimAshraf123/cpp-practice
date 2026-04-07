

#include <iostream>
using namespace std;

int main()
{
    int days, hours, minutes, seconds;
    cout << "This program finds \"Task Duration In Seconds\"...\n";
    cout << "Please enter number of days = \n";
    cin >> days;
    cout << "Please enter number of hours = \n";
    cin >> hours;
    cout << "Please enter number of minutes = \n";
    cin >> minutes;
    cout << "Please enter number of seconds = \n";
    cin >> seconds;
    cout << "\n";

    int totalSeconds = (days * 24 * 60 * 60) + (hours * 60 * 60) + (minutes * 60) + seconds;
    cout << "the Task Duration In Seconds = " << totalSeconds << "\n";

    return 0;
}

