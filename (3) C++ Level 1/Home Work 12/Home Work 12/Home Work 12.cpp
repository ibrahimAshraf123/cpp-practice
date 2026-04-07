
#include <iostream>
using namespace std;


int main()
{
    int num1, num2, num3;
    int sum;

    cout << "Please enter the value of 3 numbers: " << endl;
    cin >> num1 >> num2 >> num3;
    sum = num1 + num2 + num3;
    cout << endl;
    
    cout << num1 << " +" << endl;
    cout << num2 << " +" << endl;
    cout << num3 << endl;
    cout << "______________________" << endl;
    cout << "Total = " << sum << endl;
    
    
    
    return 0;
}


