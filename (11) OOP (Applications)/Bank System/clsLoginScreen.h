#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsUser.h";
#include "clsMainScreen.h";
#include "Global.h";

using namespace std;

class clsLoginScreen : protected clsScreen
{
private:
	static void _Login()
	{
		bool LoginFailed = false;

		string Username, Password;
		do
		{
			if (LoginFailed)
			{
				cout << "\n Invalid Username/Password!\n\n";
			}

			cout << "Enter Username? ";
			cin >> Username;

			cout << "Enter Password? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);
			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);
		clsMainScreen::ShowMainMenu();
	}

public:

	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		_Login();
	}
};

