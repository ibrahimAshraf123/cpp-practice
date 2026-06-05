#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct stClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

stClient CurrentClient;

string ClientsFileName = "Clients.txt";
string MyDelim = "#//#";

enum enMainMenuOptions 
{
	enQuickWithdraw = 1,
	enNormalWithdraw = 2,
	enDeposit = 3,
	enCheckBalance = 4,
	enLogout = 5
};

enum enQuickWithdrawOptions
{
	en20$ = 1, en50$ = 2, en100$ = 3, en200$ = 4, en400$ = 5, en600$ = 6, en800$ = 7, en1000$ = 8, enExit = 9
};



void ShowMainMenu();
void Login();


//Client-File Manip
vector<string> SplitString(string S1, string Seperator = MyDelim)
{
	vector<string> vString;
	int pos = 0;
	string sWord;

	while ((pos = S1.find(Seperator)) != string::npos)
	{
		sWord = S1.substr(0, pos); //store the word

		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Seperator.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1);
	}

	return vString;
}

stClient ConvertLineToRecord(string Line)
{
	stClient Client;
	vector<string> vDataLine = SplitString(Line);

	Client.AccountNumber = vDataLine[0];
	Client.PinCode = vDataLine[1];
	Client.Name = vDataLine[2];
	Client.Phone = vDataLine[3];
	Client.AccountBalance = stod(vDataLine[4]);

	return Client;
}

string ConvertRecordToLine(stClient Client, string Seperator = MyDelim)
{
	string DataLine = "";

	DataLine += Client.AccountNumber + Seperator;
	DataLine += Client.PinCode + Seperator;
	DataLine += Client.Name + Seperator;
	DataLine += Client.Phone + Seperator;
	DataLine += to_string(Client.AccountBalance);

	return DataLine;
}

vector<stClient> LoadClientsFromFile(string FileName = ClientsFileName)
{
	vector<stClient> vClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in);//read mode

	if (MyFile.is_open())
	{
		string Line;
		stClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;
}

bool FindClientByAccountNumberAndPinCode(string AccountNumber, string PinCode, stClient& Client)
{
	vector<stClient> vClients = LoadClientsFromFile(ClientsFileName);

	for (stClient C : vClients)
	{
		if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

void SaveClientsDataToFile(string FileName, vector<stClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); //overwrite mode

	string DataLine;

	if (MyFile.is_open())
	{
		for (stClient& C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
}

void DepositByAccountNumber(vector<stClient> &vClients)
{
	double DepositAmount = 0;
	char Confirm = 'n';

	cout << "\nPlease enter deposit amount? ";
	cin >> DepositAmount;

	cout << "\nAre you sure you want to perform this transaction? y/n? ";
	cin >> Confirm;

	if (Confirm == 'y' || Confirm == 'Y')
	{
		for (stClient& C : vClients)
		{
			if (C.AccountNumber == CurrentClient.AccountNumber)
			{
				C.AccountBalance += DepositAmount;
				break;
			}
		}
		SaveClientsDataToFile(ClientsFileName, vClients);
		FindClientByAccountNumberAndPinCode(CurrentClient.AccountNumber, CurrentClient.PinCode,CurrentClient); //refresh Current Client info
		cout << "\nYour balance is " << CurrentClient.AccountBalance << " Deposit Done Successfully.";
	}
	else
	{
		cout << "\nDeposit Operation Cancelled.";
	}
}

bool CheckEnoughWithdrawFunds(int WithdrawAmount)
{
	if (WithdrawAmount > CurrentClient.AccountBalance)
	{
		cout << "\nThe amount exceeds your balance of " << CurrentClient.AccountBalance << ", make another choice.";
		return false;
	}
	else
		return true;
}

void WithdrawByAccountNumber(vector<stClient>& vClients)
{
	double WithdrawAmount = 0;
	char Confirm = 'n';

	do
	{
		cout << "\nPlease enter withdraw amount? ";
		cin >> WithdrawAmount;

	} while (!CheckEnoughWithdrawFunds(WithdrawAmount));
	

	cout << "\nAre you sure you want to perform this transaction? y/n? ";
	cin >> Confirm;

	if (Confirm == 'y' || Confirm == 'Y')
	{
		for (stClient& C : vClients)
		{
			if (C.AccountNumber == CurrentClient.AccountNumber)
			{
				C.AccountBalance -= WithdrawAmount;
				break;
			}
		}
		SaveClientsDataToFile(ClientsFileName, vClients);
		FindClientByAccountNumberAndPinCode(CurrentClient.AccountNumber, CurrentClient.PinCode, CurrentClient); //refresh Current Client info
		cout << "\nYour balance is " << CurrentClient.AccountBalance << " Withdraw Done Successfully.";
	}
	else
	{
		cout << "\nWithdraw Operation Cancelled.";
	}
}

void QuickWithdraw(short Amount, vector<stClient>& vClients)
{
	double WithdrawAmount = Amount;
	char Confirm = 'n';

	if (!CheckEnoughWithdrawFunds(WithdrawAmount))
	{
		return;
	}

	cout << "\nAre you sure you want to perform this transaction? y/n? ";
	cin >> Confirm;

	if (Confirm == 'y' || Confirm == 'Y')
	{
		for (stClient& C : vClients)
		{
			if (C.AccountNumber == CurrentClient.AccountNumber)
			{
				C.AccountBalance -= WithdrawAmount;
				break;
			}
		}
		SaveClientsDataToFile(ClientsFileName, vClients);
		FindClientByAccountNumberAndPinCode(CurrentClient.AccountNumber, CurrentClient.PinCode, CurrentClient); //refresh Current Client info
		cout << "\nYour balance is " << CurrentClient.AccountBalance << " Withdraw Done Successfully.";
	}
	else
	{
		cout << "\nWithdraw Operation Cancelled.";
	}
}


//Menus
short ReadMenuOptions(string Message)
{
	cout << Message;
	short Result;
	cin >> Result;

	return Result;
}

void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to Main Menu...";
	system("pause>0");
	ShowMainMenu();
}

void PerformQuickWithdrawOption(enQuickWithdrawOptions Option)
{
	vector<stClient> vClients = LoadClientsFromFile();

	switch (Option)
	{
	case enQuickWithdrawOptions::en20$:
	{
		QuickWithdraw(20, vClients);
		break;
	}
	case enQuickWithdrawOptions::en50$:
	{
		QuickWithdraw(50, vClients);
		break;
	}
	case enQuickWithdrawOptions::en100$:
	{
		QuickWithdraw(100, vClients);
		break;
	}
	case enQuickWithdrawOptions::en200$:
	{
		QuickWithdraw(200, vClients);
		break;
	}
	case enQuickWithdrawOptions::en400$:
	{
		QuickWithdraw(400, vClients);
		break;
	}
	case enQuickWithdrawOptions::en600$:
	{
		QuickWithdraw(600, vClients);
		break;
	}
	case enQuickWithdrawOptions::en800$:
	{
		QuickWithdraw(800, vClients);
		break;
	}
	case enQuickWithdrawOptions::en1000$:
	{
		QuickWithdraw(1000, vClients);
		break;
	}
	case enQuickWithdrawOptions::enExit:
	{
		cout << "\nWithdraw Operation Cancelled.";
		break;
	}
	}
}

void ShowQuickWithdrawScreen()
{
	cout << "\n----------------------------------------------------";
	cout << "\n\t\t Quick Withdraw";
	cout << "\n----------------------------------------------------";
	cout << "\n [1] $20 \t [2] $50";
	cout << "\n [3] $100 \t [4] $200";
	cout << "\n [5] $400 \t [6] $600";
	cout << "\n [7] $800 \t [8] $1000";
	cout << "\n [9] Exit ";
	cout << "\n----------------------------------------------------";
	cout << "\nYour Balance is " << CurrentClient.AccountBalance;
	

	PerformQuickWithdrawOption((enQuickWithdrawOptions)ReadMenuOptions("\nChoose what to withdraw from [1] to [8]? "));
}

void ShowNormalWithdrawScreen()
{
	cout << "\n----------------------------------------------------";
	cout << "\n\t\t Normal Withdraw";
	cout << "\n----------------------------------------------------";

	vector<stClient> vClients = LoadClientsFromFile();
	WithdrawByAccountNumber(vClients);
}

void ShowDepositScreen()
{
	cout << "\n----------------------------------------------------";
	cout << "\n\t\t Deposit";
	cout << "\n----------------------------------------------------";

	vector<stClient> vClients = LoadClientsFromFile();

	DepositByAccountNumber(vClients);
}

void ShowCheckBalanceScreen()
{
	cout << "\n----------------------------------------------------";
	cout << "\n\t\t Check Balance";
	cout << "\n----------------------------------------------------";
	cout << "\nYour Balance is " << CurrentClient.AccountBalance;
}

void PerformMainMenuOption(enMainMenuOptions enOption)
{
	switch(enOption)
	{
		case enMainMenuOptions::enQuickWithdraw:
		{
			system("cls");
			ShowQuickWithdrawScreen();
			GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::enNormalWithdraw:
		{
			system("cls");
			ShowNormalWithdrawScreen();
			GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::enDeposit:
		{
			system("cls");
			ShowDepositScreen();
			GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::enCheckBalance:
		{
			system("cls");
			ShowCheckBalanceScreen();
			GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::enLogout:
		{
			system("cls");
			Login();
			break;
		}
	}
}

void ShowMainMenu()
{
	system("cls");
	cout << "\n----------------------------------------------------";
	cout << "\n\t\t ATM Main Menu";
	cout << "\n\t\t Welcome "<< CurrentClient .Name;
	cout << "\n----------------------------------------------------";
	cout << "\n [1] Quick Withdraw.";
	cout << "\n [2] Normal Withdraw.";
	cout << "\n [3] Deposit.";
	cout << "\n [4] Check Balance.";
	cout << "\n [5] Logout.";
	cout << "\n----------------------------------------------------";

	PerformMainMenuOption((enMainMenuOptions)ReadMenuOptions("\nChoose what do you want to do ? [1 to 5] ? "));
}

bool LoadClientInfo(string AccountNumber, string PinCode)
{
	if (FindClientByAccountNumberAndPinCode(AccountNumber, PinCode, CurrentClient))
		return true;
	else
		return false;
}

void Login()
{
	bool LoginFailed = false;
	string AccountNumber, PinCode;

	do
	{
		system("cls");
		cout << "\n----------------------------------------------------";
		cout << "\n\t\t ATM Login Screen";
		cout << "\n----------------------------------------------------";

		if (LoginFailed)
		{
			cout << "\nInvalid AccountNumber/PinCode!";
		}

		cout << "\nEnter Account Number? ";
		cin >> AccountNumber;
		cout << "Enter PinCode? ";
		cin >> PinCode;

		LoginFailed = !LoadClientInfo(AccountNumber,PinCode);

	} while (LoginFailed);


	ShowMainMenu();
}

int main()
{
	Login();


	system("pause>0");
	return 0;
}