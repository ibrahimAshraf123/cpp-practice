#pragma once
#include <iostream>
#include "clsScreen.h";
using namespace std;


class clsTotalBalancesScreen : protected clsScreen
{

private:
	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(25) << left << "" << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(40) << Client.FullName();
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}


public:

	static void ShowTotalBalancesScreen()
	{
		
		system("cls");

		vector<clsBankClient> vClients = clsBankClient::GetClientsList();
		
		string Title = "\t   Total Balances Screen";
		string Subtitle = "\n\t\t\t\t\t\t Balances List (" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, Subtitle);

		cout << setw(25) << left << "" << "________________________________________________________________________________\n";
		cout << setw(25) << left << "" << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance" << endl;
		cout << setw(25) << left << "" << "________________________________________________________________________________\n\n";
		

		double TotalBalances = clsBankClient::GetTotalBalances();

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In The System!";
		else
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}
		cout << setw(25) << left << "" << "_________________________________________________________________________________\n\n";
		

		cout << "\t\t\t\t\t		Total Balances = " << TotalBalances << endl;
		cout << "\t\t\t\t\t		(" << clsUtil::NumberToText(TotalBalances) << ")\n";
	}
};

