using namespace std;

#include <iostream>

struct stATM_User {
	string Name;
	int PIN;
	float balance;
};

int ReadPinCode(string Message)
{
	int Num;
	
	cout << Message << endl;
	cin >> Num;

	return Num;
}

bool ValidatePinCode(stATM_User User)
{
	int PinCode = ReadPinCode("Please enter PIN Code");

	for (int i = 2; i >= 1; i--)
	{
		if (PinCode == User.PIN)
		{
			system("color 2F");
			cout << "\nPIN Code [" << PinCode << "] is Valid\n";
			return 1;
		}

		else
		{
			system("color 4F");
			cout << "\nPIN Code [" << PinCode << "] is Invalid\n";
			cout << i << " Attempts left\n\n";
			PinCode = ReadPinCode("Please enter PIN Code");
		}

	}
	cout << "**** Card is locked ****" << endl;
	return 0;
}

int main()
{

	stATM_User ATM_User1;
	ATM_User1.Name = "John Doe";
	ATM_User1.PIN = 1234;
	ATM_User1.balance = 7500;

 
	if (ValidatePinCode(ATM_User1))
		cout << "\nBalance = " << ATM_User1.balance << endl;
	else
		cout << "\nYour Card is blocked call the bank for help" << endl;


	return 0;
}