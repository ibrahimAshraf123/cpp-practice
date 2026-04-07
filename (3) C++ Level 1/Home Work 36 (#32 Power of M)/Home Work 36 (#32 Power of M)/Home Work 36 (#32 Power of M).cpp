// Home Work 36 (#32 Power of M).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int readN() {
    //read n
    int n;
    cout << "Enter value of N: \n";
    cin >> n;
    return n;
}

int readM() {
    //read n
    cout << "Enter value of M: \n";
    int  m;
    cin >> m;
    return m;
}

void printPower(int n, int m) {
    //n ^ m = n * n (m times)
    int p = 1;
    for (int i = 1; i <= m; i++) {

        p = p * n;
    }

    cout << p;
}

int main()
{
    cout << "This program calculates N ^ M: \n";
    int n = readN();
    int m = readM();
    printPower(n, m);
    



    return 0;
}
