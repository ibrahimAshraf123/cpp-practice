using namespace std;

#include <iostream>

struct stATM_User {
	int PIN_Code;
	int UserBalance;
};

int ReadPIN(stATM_User ATM_User , string Message)
{
	int PIN;
	cout << Message << endl;
	cin >> PIN;
	
	while (PIN != ATM_User.PIN_Code)
	{
		system("color 4F");
		cout << "*** Wrong PIN ***" << endl;
		cout << Message << endl;
		cin >> PIN;
	}

	system("color 2F");
	cout << "*** Access Granted ***" << endl;
	return PIN;
}

void PrintAccountBalance(stATM_User ATM_User , int PIN)
{
	cout << "\nBalance = " << ATM_User.UserBalance << endl;

}


int main()
{
	stATM_User ATM_Ibrahim
	{
		ATM_Ibrahim.PIN_Code = 1234 ,
		ATM_Ibrahim.UserBalance = 7500
	};


	PrintAccountBalance(ATM_Ibrahim, ReadPIN(ATM_Ibrahim, "Please enter PIN code: "));
	

	return 0;
}