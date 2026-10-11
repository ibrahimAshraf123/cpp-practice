
#include <iostream>

using namespace std;

int main()
{

    double x[3];

    cout << "Enter 1st value: \n";
    cin >> x[0];
    cout << "Enter 2nd value: \n";
    cin >> x[1];
    cout << "Enter 3rd value: \n";
    cin >> x[2];
    cout << "\n******************************\n";
    cout << "The average of values: " << double((x[0] + x[1] + x[2]) / 3) << endl;

    return 0;
}
