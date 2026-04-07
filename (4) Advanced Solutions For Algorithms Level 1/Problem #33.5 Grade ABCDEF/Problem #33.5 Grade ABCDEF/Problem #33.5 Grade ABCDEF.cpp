using namespace std;

#include <iostream>



int EnterNumberInRange(int From, int To)
{
    int N;
    do {
        cout << "Enter Number from " << From << " To " << To <<endl;
        cin >> N;
    } while (N <= From || N >= To);
    return N;
}

char GetGradeLetter(int Grade)
{
    if (Grade >= 90)
        return 'A';

    else if (Grade >= 80)
        return 'B';

    else if (Grade >= 70)
        return 'C';

    else if (Grade >= 60)
        return 'D';

    else if (Grade >= 50)
        return 'E';

    else 
        return 'F';
}

int main()
{

    cout << endl << "Result = " << GetGradeLetter(EnterNumberInRange(0,100)) << endl;
    
    return 0;
}
