// Home Work 15 (#20).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    float A;

    cout << "This program finds \"Circle Area Inscribed in a Square\"... \nPlease enter the value of (A) \"Side of Square\" = ";
    cin >> A;
    cout << "\n";

    const float PI = 3.14;
    float area = (PI * (A * A)) / 4;
    cout << "The Circle Area Inscribed in a Square = " << area << "\n";



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
