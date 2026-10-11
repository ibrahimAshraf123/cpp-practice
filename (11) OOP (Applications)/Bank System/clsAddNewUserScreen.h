#pragma once
#include "clsScreen.h";
#include <iostream>
#include "clsInputValidate.h";
#include "clsUser.h";
#include <iomanip>

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{
private:
	
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter First Name: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter Last Name: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permissions: ";
		User.Permissions = _ReadPermissionsToSet();
	}

	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'n';

		cout << "\nDo you want to give full access? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to: \n";

		cout << "\nShow Client Lists? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClient;
		}

		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		return Permissions;
	}

	static void _PrintUser(clsUser User)
	{
		cout << setw(37) << left << "" << "User Card:\n";
		cout << setw(37) << left << "" << "---------------\n";
		cout << setw(37) << left << "" << "First Name : " << User.FirstName << endl;
		cout << setw(37) << left << "" << "Last Name  : " << User.LastName << endl;
		cout << setw(37) << left << "" << "Full Name  : " << User.FullName() << endl;
		cout << setw(37) << left << "" << "Email      : " << User.Email << endl;
		cout << setw(37) << left << "" << "Phone      : " << User.Phone << endl;
		cout << setw(37) << left << "" << "User Name  : " << User.UserName << endl;
		cout << setw(37) << left << "" << "Password   : " << User.Password << endl;
		cout << setw(37) << left << "" << "Permissions: " << User.Permissions << endl;
		cout << setw(37) << left << "" << "---------------\n\n";
	}

public:

	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t  Add New User Screen");

		string UserName = "";

		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUserName is already used, Choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;
		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\nUser Added Successfully :-)\n";
			_PrintUser(NewUser);
			break;
		}
		case clsUser::enSaveResults::svFailedEmptyObject:
		{
			cout << "\nError User was not saved because it's Empty!\n";
			break;
		}
		case clsUser::enSaveResults::svFailedUserNameExists:
		{
			cout << "\nError User was not saved because UserName is used!\n";
			break;
		};
		}


	}
};

