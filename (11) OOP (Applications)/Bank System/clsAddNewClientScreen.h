#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsBankClient.h";

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\n";
		cout << setw(37) << left << "" << "Enter First Name: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << setw(37) << left << "" << "Enter Last Name: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << setw(37) << left << "" << "Enter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << setw(37) << left << "" << "Enter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << setw(37) << left << "" << "Enter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << setw(37) << left << "" << "Enter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	};

	static void _PrintClient(clsBankClient Client)
	{
		cout << setw(37) << left << "" << "Client Card:\n";
		cout << setw(37) << left << "" << "---------------\n";
		cout << setw(37) << left << "" << "First Name    : " << Client.FirstName		<< endl;
		cout << setw(37) << left << "" << "Last Name     : " << Client.LastName			<< endl;
		cout << setw(37) << left << "" << "Full Name     : " << Client.FullName()		<< endl;
		cout << setw(37) << left << "" << "Email         : " << Client.Email			<< endl;
		cout << setw(37) << left << "" << "Phone         : " << Client.Phone			<< endl;
		cout << setw(37) << left << "" << "AccountNumber : " << Client.AccountNumber()	<< endl;
		cout << setw(37) << left << "" << "PinCode       : " << Client.PinCode			<< endl;
		cout << setw(37) << left << "" << "AccountBalance: " << Client.AccountBalance	<< endl;
		cout << setw(37) << left << "" << "---------------\n\n";
	}

public:

	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return; //this will exit the function
		};

		_DrawScreenHeader("Add New Client Screen");
		string AccountNumber = "";

		cout << setw(37) << left << "" << "Please enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << setw(37) << left << "" << "Account Number is already used, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\n";
			cout << setw(37) << left << "" << "Account Added Successfully :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFailedEmptyObject:
		{
			cout << "\n";
			cout << setw(37) << left << "" << "Error Account was not Added because it's Empty";
			break;
		}
		case clsBankClient::enSaveResults::svFailedAccountNumberExists:
		{
			cout << "\n";
			cout << setw(37) << left << "" << "Error Account was not Added because Account Number is used!\n";
			break;
		}
		};
	}

};

