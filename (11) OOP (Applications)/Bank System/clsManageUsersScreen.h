#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include <iomanip>
#include "clsListUsersScreen.h";
#include <vector>
#include "clsAddNewUserScreen.h";
#include "clsDeleteUserScreen.h";
#include "clsUpdateUserScreen.h";
#include "clsFindUserScreen.h";

using namespace std;

class clsManageUsersScreen : protected clsScreen
{
private:
	
	enum enManageUsersMenuOptions 
	{
		enListUsers = 1,
		enAddNewUser = 2,
		enDeleteUser = 3,
		enUpdateUser = 4,
		enFindUser = 5,
		enUsersMainMenu = 6
	};

	static short ReadMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 6] ? ";
		return clsInputValidate::ReadIntNumberBetween(1, 6);
	}

	static void _GoBackToManageUsersMenu()
	{
		cout << "\n\nPress any key to go back to Manage Users Menu...";
		system("pause>0");
		ShowManageUsersScreen();
	}

	static void _ListUsersScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}

	static void _AddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _DeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _UpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _FindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUsersMenuOption(enManageUsersMenuOptions ManageUsersOption)
	{
			switch (ManageUsersOption)
			{
			case enManageUsersMenuOptions::enListUsers:
			{
				system("cls");
				_ListUsersScreen();
				_GoBackToManageUsersMenu();
				break;
			}
			case enManageUsersMenuOptions::enAddNewUser:
			{
				system("cls");
				_AddNewUserScreen();
				_GoBackToManageUsersMenu();
				break;
			}
			case enManageUsersMenuOptions::enDeleteUser:
			{
				system("cls");
				_DeleteUserScreen();
				_GoBackToManageUsersMenu();
				break;
			}
			case enManageUsersMenuOptions::enUpdateUser:
			{
				system("cls");
				_UpdateUserScreen();
				_GoBackToManageUsersMenu();
				break;
			}
			case enManageUsersMenuOptions::enFindUser:
			{
				system("cls");
				_FindUserScreen();
				_GoBackToManageUsersMenu();
				break;
			}
			case enManageUsersMenuOptions::enUsersMainMenu:
			{
				//Main menu will continue here...
			}
			}
	}

public:

	static void ShowManageUsersScreen()
	{
		system("cls");

		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return; //this will exit the function
		};

		_DrawScreenHeader("\t   Manage Users Screen");

		cout << setw(37) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "\t\t     Manage Users Menu\n";
		cout << setw(37) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "[1] List Users.\n";
		cout << setw(37) << left << "" << "[2] Add New User.\n";
		cout << setw(37) << left << "" << "[3] Delete User.\n";
		cout << setw(37) << left << "" << "[4] Update User.\n";
		cout << setw(37) << left << "" << "[5] Find User.\n";
		cout << setw(37) << left << "" << "[6] Main Menu.\n";
		cout << setw(37) << left << "" << "==================================================\n";

		_PerformManageUsersMenuOption((enManageUsersMenuOptions)ReadMenuOption());
	}

};

