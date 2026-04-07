using namespace std;

#include <iostream>

int ReadAge()
{
    int Age;
    cout << "Enter Age: ";
    cin >> Age;

    return Age;
}

bool ValidateNumberInRange(int Age, int From,int To)
{
    return (Age >= From && Age <= To);
}

void PrintResult(int Age)
{
    if (ValidateNumberInRange(Age,18,45))
        cout << Age << " is a Valid Age\n";
    else
        cout << Age << " is an Invalid Age\n";
}

int main()
{
    PrintResult(ReadAge());

    return 0;
}
