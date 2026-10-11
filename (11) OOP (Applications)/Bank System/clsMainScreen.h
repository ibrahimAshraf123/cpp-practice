#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsUtil.h";
#include "clsBankClient.h";
#include "clsInputValidate.h";
#include "clsClientListScreen.h";
#include "clsAddNewClientScreen.h";
#include "clsDeleteClientScreen.h";
#include "clsUpdateClientScreen.h";
#include "clsFindClientScreen.h";
#include "clsTransactionsScreen.h";
#include "clsManageUsersScreen.h";
#include "Global.h";

using namespace std;

class clsMainScreen : protected clsScreen
{

private:
	
	enum enMainMenuOptions {
		enShowClientList = 1,
		enAddNewClient = 2,
		enDeleteClient = 3,
		enUpdateClient = 4,
		enFindClient = 5,
		enTransactions = 6,
		enManageUsers = 7,
		enExit = 8
	};

	static short ReadMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 8] ? ";
		return clsInputValidate::ReadIntNumberBetween(1, 8);
	}

	static void _GoBackToMainMenu()
	{
		cout << "\nPress any key to go back to main menu...";
		system("pause > 0");
		return ShowMainMenu();
	}

	static void _ShowClientsScreen()
	{
		clsClientListScreen::ShowClientsList();
	}

	static void _AddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void _DeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _UpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _FindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _TransactionsScreen()
	{
		clsTransactionsScreen::ShowTransactionsMenu();
	}

	static void _ManageUsersScreen()
	{
		clsManageUsersScreen::ShowManageUsersScreen();
	}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");

		//then main menu will continue...
	}

	static void _PerformMainMenuOption(enMainMenuOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enMainMenuOptions::enShowClientList:
		{
			system("cls");
			_ShowClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::enAddNewClient:
		{
			system("cls");
			_AddNewClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::enDeleteClient:
		{
			system("cls");
			_DeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::enUpdateClient:
		{
			system("cls");
			_UpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::enFindClient:
		{
			system("cls");
			_FindClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::enTransactions:
		{
			system("cls");
			_TransactionsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::enManageUsers:
		{
			system("cls");
			_ManageUsersScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::enExit:
		{
			system("cls");
			_Logout();
			break;
		}
		}
	}


public:
	
	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t	Main Screen");
		
		cout << setw(37) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "\t\t\tBank Menu\n";
		cout << setw(37) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "[1] Show Client List.\n";
		cout << setw(37) << left << "" << "[2] Add New Client.\n";
		cout << setw(37) << left << "" << "[3] Delete Client.\n";
		cout << setw(37) << left << "" << "[4] Update Client.\n";
		cout << setw(37) << left << "" << "[5] Find Client.\n";
		cout << setw(37) << left << "" << "[6] Transactions.\n";
		cout << setw(37) << left << "" << "[7] Manage Users.\n";
		cout << setw(37) << left << "" << "[8] Logout.\n";
		cout << setw(37) << left << "" << "==================================================\n";

		_PerformMainMenuOption((enMainMenuOptions)ReadMenuOption());

	}

};

