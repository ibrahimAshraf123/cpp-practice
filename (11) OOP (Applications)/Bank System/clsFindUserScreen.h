#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsUser.h";
#include <iomanip>

using namespace std;

class clsFindUserScreen : protected clsScreen
{
private:
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
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\t   Find User Screen");

		string UserName = "";
		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUserName is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);

		if (!User1.IsEmpty())
		{
			cout << "\nUser Found :-)\n";
		}
		else
		{
			cout << "\nUser was not found :-(\n";
		}

		_PrintUser(User1);

	}

};

