
#include <iostream>

using namespace std;

struct stPIN {
    int PIN;
    bool validPIN;
};

struct stAccount {
    stPIN accountPIN;
    float balance;
};

void readPIN(stAccount &myAcc) {
    cout << "Please enter your PIN: \n";
    cin >> myAcc.accountPIN.PIN;
}

void validatePIN(stAccount& myAcc) {
    if (myAcc.accountPIN.PIN == 1234) {
        myAcc.accountPIN.validPIN = true;
        myAcc.balance = 7500;
        cout << "Balance = " << myAcc.balance << endl;
    }
    else {
        myAcc.accountPIN.validPIN = false;
        cout << "Wrong PIN \n";
    }
}


int main()
{
    stAccount ibrahim123;
    readPIN(ibrahim123);
    validatePIN(ibrahim123);
    
    return 0;
}
