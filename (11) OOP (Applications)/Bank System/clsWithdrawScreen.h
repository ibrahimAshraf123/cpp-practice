#pragma once
#include <iostream>
#include "clsBankClient.h";
#include "clsInputValidate.h";
#include "clsScreen.h";
#include <iomanip>

using namespace std;

class clsWithdrawScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << setw(37) << left << "" << "Client Card:\n";
		cout << setw(37) << left << "" << "---------------\n";
		cout << setw(37) << left << "" << "Full Name     : " << Client.FullName() << endl;
		cout << setw(37) << left << "" << "Email         : " << Client.Email << endl;
		cout << setw(37) << left << "" << "Phone         : " << Client.Phone << endl;
		cout << setw(37) << left << "" << "AccountNumber : " << Client.AccountNumber() << endl;
		cout << setw(37) << left << "" << "AccountBalance: " << Client.AccountBalance << endl;
		cout << setw(37) << left << "" << "---------------\n\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		return AccountNumber;
	}

public:

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\tWithdraw Screen");


		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with account number [" << AccountNumber << "] does not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease enter withdraw amount? ";
		Amount = clsInputValidate::ReadDblNumber();

		char Confirm = 'n';
		cout << "\nAre you sure you want to perform this transaction? y/n? ";
		cin >> Confirm;

		if (Confirm == 'Y' || Confirm == 'y')
		{
			if (Client1.Withdraw(Amount))
			{
				cout << "\nWithdraw Done Successfully.\n";
				cout << "\nNew balance is: " << Client1.AccountBalance << "\n";
			}
			else
			{
				cout << "\nCannot Withdraw, Insufficient Balance!\n";
				cout << "\nAmount to Withdraw is  : " << Amount;
				cout << "\nYour current balance is: " << Client1.AccountBalance << "\n";
			}
			
		}
		else
		{
			cout << "\nWithdraw Operation Cancelled.\n";
		}
	}


};

