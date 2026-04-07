using namespace std;

#include <iostream>

void ReadPowerVariables(int& Number, int& Exponential)
{
    cout << "Enter Number:\n";
    cin >> Number;

    cout << "Enter Exponential:\n";
    cin >> Exponential;

}

int Power(int N, int M)
{
    int Power = 1;
    for (int i = 1; i <= M; i++)
    {
        Power *= N;
    }
    return Power;
}

void PrintPowerResult(int Number, int Exponential,int Power)
{
    cout << "\n" << Number << " ^ " << Exponential << " = " << Power << endl;
}

int main()
{
    int N, M;
    ReadPowerVariables(N, M);
    PrintPowerResult(N, M,Power(N, M));


    return 0;
}
