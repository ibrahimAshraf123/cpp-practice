#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";

using namespace std;


class clsFindClientScreen : protected clsScreen
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
	
	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return; //this will exit the function
		};

		_DrawScreenHeader("\t   Find Client Screen");

		string AccountNumber = "";
		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		if (!Client1.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient was not found :-(\n";
		}

		_PrintClient(Client1);
	}
};

