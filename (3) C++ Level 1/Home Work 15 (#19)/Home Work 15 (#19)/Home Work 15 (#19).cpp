

#include <iostream>
using namespace std;


int main()
{
    float d;

    cout << "This program finds the Circle Area Through Diameter \n\nPlease enter the Diameter of your Circle = ";
    cin >> d;
    cout << "\n";

    const float PI = 3.14;
    float area = (PI * d * d) / 4;

    cout << "The area is = " << area << "\n";

    return 0;
}


