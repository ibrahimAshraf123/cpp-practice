// Home Work 15 (#43).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    long long totalSeconds;
    cout << "This program converts seconds to \"Days Hours Minutes & Seconds\"... \n";
    cout << "Please enter the number of seconds = \n";
    cin >> totalSeconds;
    cout << "\n";

    int days = totalSeconds / (24 * 3600);
    totalSeconds %= (24 * 3600);
    
    int hours = totalSeconds / 3600;
    totalSeconds %= 3600;
    
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;

    cout << "Result: \n";
    cout << days << " Days \n";
    cout << hours << " Hours \n";
    cout << minutes << " Minutes \n";
    cout << seconds << " Seconds \n";


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
