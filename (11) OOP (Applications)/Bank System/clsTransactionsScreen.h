#pragma once
#include <iostream>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsDepositScreen.h";
#include "clsWithdrawScreen.h";
#include "clsTotalBalancesScreen.h";

using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:
	
	enum enTransactionsMenuOptions {
		enDeposit = 1,
		enWithdraw = 2,
		enTotalBalances = 3,
		enMainMenu = 4
	};

	static short ReadMenuOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do ? [1 to 4] ? ";
		return clsInputValidate::ReadIntNumberBetween(1, 4);
	}

	static void _GoBackToTransactionsMenu()
	{
		cout << "\nPress any key to go back to transactions menu...";
		system("pause > 0");
		return ShowTransactionsMenu();
	}

	static void _DepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _WithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _TotalBalancesScreen()
	{
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}


	static void _PerformTransactionMenuOption(enTransactionsMenuOptions TransactionOption)
	{
		switch (TransactionOption)
		{
		case enTransactionsMenuOptions::enDeposit:
		{
			system("cls");
			_DepositScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::enWithdraw:
		{
			system("cls");
			_WithdrawScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::enTotalBalances:
		{
			system("cls");
			_TotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;
		}
		case enTransactionsMenuOptions::enMainMenu:
		{
		//Main menu will continue here...
		}
		}
	}

public:
	
	static void ShowTransactionsMenu()
	{
		system("cls");
		
		if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return; //this will exit the function
		};

		_DrawScreenHeader("\t   Transactions Screen");

		cout << setw(37) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "\t\t     Transactions Menu\n";
		cout << setw(37) << left << "" << "==================================================\n";
		cout << setw(37) << left << "" << "[1] Deposit.\n";
		cout << setw(37) << left << "" << "[2] Withdraw.\n";
		cout << setw(37) << left << "" << "[3] Total Balances.\n";
		cout << setw(37) << left << "" << "[4] Main Menu.\n";
		cout << setw(37) << left << "" << "==================================================\n";

		_PerformTransactionMenuOption((enTransactionsMenuOptions)ReadMenuOption());
	}


};

