

#include <iostream>
using namespace std;

int main()
{
    string  name = "Ibrahim Ashraf Ibrahim";
    int     age = 26;
    string  city = "Al Ain";
    string  country = "UAE";
    int     monthlySalary = 30000;
    int     yearlySalary = monthlySalary * 12;
    char    gender = 'M';
    bool    married = true;

    cout << "*****************************" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "City: " << city << endl;
    cout << "Country: " << country << endl;
    cout << "Monthly Salary: " << monthlySalary << endl;
    cout << "Yearly Salary: " << yearlySalary << endl;
    cout << "Gender: " << gender << endl;
    cout << "Married: " << married << endl;
    cout << "*****************************" << endl;

    return 0;
}

