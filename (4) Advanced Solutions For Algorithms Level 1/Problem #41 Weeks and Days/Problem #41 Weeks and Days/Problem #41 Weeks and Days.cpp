using namespace std;
#include <iostream>

float ReadPositiveNumber(string Message)
{
    float Num;
    do
    {
        cout << Message << endl;
        cin >> Num;
    } while (Num < 0);
    
    return Num;
}

float HoursToDays(float Hours)
{
    float Days = Hours / 24;
    return Days;
}

float DaysToWeeks(float Days)
{
    float Weeks = Days / 7;
    return Weeks;
}


int main()
{

    float NumberOfHours = ReadPositiveNumber("Please enter Number Of Hours: ");

   cout << endl;
   cout << HoursToDays(NumberOfHours) << " Days\n";
   cout << DaysToWeeks(HoursToDays(NumberOfHours)) << " Weeks\n";

    return 0;
}
