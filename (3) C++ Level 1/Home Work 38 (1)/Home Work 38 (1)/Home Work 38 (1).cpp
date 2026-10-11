// Home Work 38 (1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void printTwoAlphabets() {
    for (int i = 65; i <= 90; i++) {

        for (int j = 65; j <= 90; j++) {
            cout << char(i) << char(j) << endl;
        }
    }
}

void printDownRightTriangle() {
    for (int i = 10; i >= 0; i--) {
        cout << "*";
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}

void printDownRightNumericalTriangle() {
    for (int i = 10; i >= 1; i--) {
        cout << 1;
        for (int j = 2; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
}

void printUpRightNumericalTriangle() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= i; j++) {
            cout << j;
        }
        cout << endl;
    }
}

void printUpRightAlphabeticalTriangle() {
    for (int i = 1; i <= 26; i++) {
        for (int j = 1; j <= i; j++) {
            cout << char(64 + j);
        }
        cout << endl;
    }
}

void printDownRightNumericalTriangle2() {
    for (int i = 1; i <= 10; i++) {
        for (int j = i ; j <= 10; j++) {
            cout << j <<" ";
        }
        cout << endl;
    }
}

int main()
{

    //printTwoAlphabets();
    //printDownRightTriangle();
    //printDownRightNumericalTriangle();
    //printUpRightNumericalTriangle();
    //printUpRightAlphabeticalTriangle();
    //printDownRightNumericalTriangle2();

    

    
    
    

    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
