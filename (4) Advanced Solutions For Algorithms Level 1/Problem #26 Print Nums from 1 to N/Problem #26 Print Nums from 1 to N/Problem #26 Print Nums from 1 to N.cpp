using namespace std;
#include <iostream>

int ReadNumber()
{
    int Num;
    cout << "Enter Number to read To: \n";
    cin >> Num;

    return Num;
}

void PrintUntilNumber_UsingFor(int Num)
{
    cout << "\n";
    for (int i = 1; i <= Num; i++)
    {
        cout << i << endl;
    }
}

void PrintUntilNumber_UsingWhile(int Num)
{
    cout << "\n";
    int i = 1;
    while (i <= Num)
    {
        cout << i << endl;
        i++;
    }
}

void PrintUntilNumber_UsingDoWhile(int Num)
{
    cout << "\n";
    int i = 1;
    do
    {
        cout << i << endl;
        i++;
    } while (i <= Num);
}

int main()
{
    int N = ReadNumber();

    PrintUntilNumber_UsingFor(N);
    cout << "\n";
    PrintUntilNumber_UsingWhile(N);
    cout << "\n";
    PrintUntilNumber_UsingDoWhile(N);
    cout << "\n";

    return 0;
}
