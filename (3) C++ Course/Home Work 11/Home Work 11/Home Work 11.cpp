

#include <iostream>
using namespace std;

int main()
{
    string Name;
    int Age;
    string City;
    string Country;
    int MonthlySalary;
    char Gender;
    bool Married;

    cout << "Please enter your name: " << endl;
    cin >> Name;
    cout << "Please enter your age: " << endl;
    cin >> Age;
    cout << "Please enter your city: " << endl;
    cin >> City;
    cout << "Please enter your country: " << endl;
    cin >> Country;
    cout << "Please enter your monthly salary: " << endl;
    cin >> MonthlySalary;
    cout << "Please enter your gender: " << endl;
    cin >> Gender;
    cout << "Please enter your marriage status: " << endl;
    cin >> Married;
    cout << endl;

    cout << "*************************" << endl;
    cout << "Name: " << Name << endl;
    cout << "Age: " << Age << endl;
    cout << "City: " << City << endl;
    cout << "Country: " << Country << endl;
    cout << "Monthly salary: " << MonthlySalary << endl;
    cout << "Yearly salary: " << MonthlySalary * 12 << endl;
    cout << "Gender: " << Gender << endl;
    cout << "Married: " << Married << endl;
    cout << "*************************" << endl;

    return 0;
}


