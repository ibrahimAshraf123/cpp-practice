using namespace std;

#include <iostream>

enum enMonthsOfYear { Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 };

int ReadNumberInRange(string Message, int From, int To)
{
    int Number;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number < From || Number > To);

    return Number;
}

enMonthsOfYear ReadMonthOfYear()
{
    return (enMonthsOfYear)ReadNumberInRange("Please Enter Month Number: \n[ Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6, Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12 ]", 1, 12);
}

string GetMonthOfYear(enMonthsOfYear Month)
{
    switch (Month)
    {
    case Jan: return "January";
    case Feb: return "February";
    case Mar: return "March";
    case Apr: return "April";
    case May: return "May";
    case Jun: return "June";
    case Jul: return "July";
    case Aug: return "August";
    case Sep: return "September";
    case Oct: return "October";
    case Nov: return "November";
    case Dec: return "December";
    default : return "Not a valid Month";
    }
}

int main()
{
    cout << GetMonthOfYear(ReadMonthOfYear()) << endl;

    return 0;
}

