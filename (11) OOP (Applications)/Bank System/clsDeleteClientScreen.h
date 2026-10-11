#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";
#include <iomanip>

using namespace std;

class clsDeleteClientScreen : protected clsScreen
{

private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << setw(37) << left << "" << "Client Card:\n";
		cout << setw(37) << left << "" << "---------------\n";
		cout << setw(37) << left << "" << "First Name    : " << Client.FirstName << endl;
		cout << setw(37) << left << "" << "Last Name     : " << Client.LastName << endl;
		cout << setw(37) << left << "" << "Full Name     : " << Client.FullName() << endl;
		cout << setw(37) << left << "" << "Email         : " << Client.Email << endl;
		cout << setw(37) << left << "" << "Phone         : " << Client.Phone << endl;
		cout << setw(37) << left << "" << "AccountNumber : " << Client.AccountNumber() << endl;
		cout << setw(37) << left << "" << "PinCode       : " << Client.PinCode << endl;
		cout << setw(37) << left << "" << "AccountBalance: " << Client.AccountBalance << endl;
		cout << setw(37) << left << "" << "---------------\n\n";
	}


public:

	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return; //this will exit the function
		};

		_DrawScreenHeader("\tDelete Client Screen");

		string AccountNumber = "";
		cout << "\nPlease enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);
		
		cout << "\n\nAre you sure you want to delete this client? y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client1.Delete())
			{
				cout << "\nClient deleted successfully :-)\n";
				_PrintClient(Client1);
			}
			else
			{
				cout << "\nError: client was not deleted\n";
			}
		}
	}
};


