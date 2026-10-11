#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

string ClientsFileName = "Clients.txt";
string MyDelim = "#//#";

void ShowMainMenu();


//Client-File Manip
struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

vector<string> SplitString(string S1, string Seperator = MyDelim)
{
	vector<string> vString;
	int pos = 0;
	string sWord;

	while ((pos = S1.find(Seperator)) != string::npos)
	{
		sWord = S1.substr(0, pos); //store the word;
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

sClient ConvertLineToRecord(string Line)
{
	sClient Client;
	vector<string> vDataLine = SplitString(Line);

	Client.AccountNumber = vDataLine[0];
	Client.PinCode = vDataLine[1];
	Client.Name= vDataLine[2];
	Client.Phone= vDataLine[3];
	Client.AccountBalance= stod(vDataLine[4]);

	return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = MyDelim)
{
	string DataLine = "";

	DataLine += Client.AccountNumber + Seperator;
	DataLine += Client.PinCode + Seperator;
	DataLine += Client.Name+ Seperator;
	DataLine += Client.Phone+ Seperator;
	DataLine += to_string(Client.AccountBalance);

	return DataLine;
}

vector<sClient> LoadClientsFromFile(string FileName = ClientsFileName)
{
	vector<sClient> vClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in);//read mode

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}

void PrintClientRecord(sClient Client)
{
	cout << "| " << left << setw(15) << Client.AccountNumber;
	cout << "| " << left << setw(15) << Client.PinCode;
	cout << "| " << left << setw(40) << Client.Name;
	cout << "| " << left << setw(12) << Client.Phone;
	cout << "| " << left << setw(12) << Client.AccountBalance;
}

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "--------------------------------------";
	cout << "\nAccount Number : " << Client.AccountNumber;
	cout << "\nPinCode        : " << Client.PinCode;
	cout << "\nName           : " << Client.Name;
	cout << "\nPhone          : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "\n--------------------------------------\n";
}

bool ClientExistsByAccountNumber(string AccountNumber,string FileName)
{
	vector<sClient> vClients = LoadClientsFromFile(FileName);

	fstream MyFile;
	MyFile.open(FileName, ios::in); //read mode

	if (MyFile.is_open())
	{
		string Line;
		sClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			if (Client.AccountNumber == AccountNumber)
			{
				MyFile.close();
				return true;
			}
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return false;
}

sClient ReadNewClient()
{
	sClient Client;
	cout << "Enter Account Number? ";

	getline(cin >> ws, Client.AccountNumber);

	while(ClientExistsByAccountNumber(Client.AccountNumber,ClientsFileName))
		{
		cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number... ";
		getline(cin >> ws, Client.AccountNumber);
		}

	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);
	cout << "Enter Name? ";
	getline(cin, Client.Name);
	cout << "Enter Phone? ";
	getline(cin, Client.Phone);
	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;

	return Client;
}

void AddDataLineToFile(string FileName, string DataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app); //write or append mode

	if (MyFile.is_open())
	{
		MyFile << DataLine << endl;
		MyFile.close();
	}
}

void AddNewClient()
{
	sClient Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddNewClients()
{
	char AddMore = 'Y';

	do
	{
		cout << "Adding New Client:\n\n";

		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}

string ReadAccountNumber()
{
	cout << "\nPlease enter Account Number: ";
	string AccountNumber = "";
	cin >> AccountNumber;
	return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient>& vClients, sClient &Client)
{
	for (sClient &C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

void SaveClientDataToFile(string FileName, vector<sClient> vClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); //overwrite mode

	string DataLine;

	if (MyFile.is_open())
	{
		for (sClient& C : vClients)
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

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient> &vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre You sure you want to delete this client? Y/N? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveClientDataToFile(ClientsFileName, vClients);

			//Refresh Clients
			vClients = LoadClientsFromFile();

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}
}

sClient ChangeClientRecord(string AccountNumber)
{
	sClient Client;

	Client.AccountNumber = AccountNumber;

	cout << "\n\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter Account Balance? ";
	cin >> Client.AccountBalance;

	return Client;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
		cout << "\nAre you sure you want to update this client? y/n? ";

		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}
			SaveClientDataToFile(ClientsFileName, vClients);

			cout << "\n\nClient Updated Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber <<") is Not Found!";
		return false;
	}
}


//Different Screens
enum enumMainMenuOptions
{
	enShowClientList = 1,
	enAddNewClient = 2,
	enDeleteClient = 3,
	enUpdateClient = 4,
	enFindClient = 5,
	enExit = 6
};

void ShowClientsScreen()
{
	system("cls");

	vector<sClient> vClients = LoadClientsFromFile(ClientsFileName);

	cout << "\n\t\t\t\t\tCLient List (" << vClients.size() << ") Client(s).";
	cout << "\n====================================================================================================\n";
	cout << "====================================================================================================\n";
	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(15) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n====================================================================================================\n";
	cout << "====================================================================================================\n" << endl;

	if (vClients.size() == 0)
		cout << "\t\t\t\tNo Clients Available In The System!";
	else
		for (sClient Client : vClients)
		{
			PrintClientRecord(Client);
			cout << endl;
		}
	cout << "\n====================================================================================================\n";
	cout << "====================================================================================================\n" << endl;

}

void AddNewClientScreen()
{
	system("cls");
	cout << "==================================================\n";
	cout << "\t\tAdd New Client Screen\n";
	cout << "==================================================\n";

	AddNewClients();
}

void DeleteClientScreen()
{
	system("cls");
	cout << "==================================================\n";
	cout << "\t\tDelete Client Screen\n";
	cout << "==================================================\n";

	vector<sClient> vClients = LoadClientsFromFile();
	string AccountNumber = ReadAccountNumber();
	DeleteClientByAccountNumber(AccountNumber, vClients);

}

void UpdateClientScreen()
{
	system("cls");
	cout << "==================================================\n";
	cout << "\t\tUpdate Client Screen\n";
	cout << "==================================================\n";

	vector<sClient> vClients = LoadClientsFromFile();
	string AccountNumber = ReadAccountNumber();
	UpdateClientByAccountNumber(AccountNumber, vClients);
}

void FindClientScreen()
{
	system("cls");
	cout << "==================================================\n";
	cout << "\t\tFind Client Screen\n";
	cout << "==================================================\n";

	vector<sClient> vClients = LoadClientsFromFile();
	string AccountNumber = ReadAccountNumber();
	sClient Client;

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
	}
	
}

void ExitScreen()
{
	system("cls");
	cout << "==================================================\n";
	cout << "\t\tExit Screen\n";
	cout << "==================================================\n";
	cout << "\n\nThe program ended :-)\n";
}


//Main Menu
short ReadMainMenuOption()
{
	cout << "Choose what do you want to do? [1 to 6]? ";
	short Choice = 0;
	cin >> Choice;
	return Choice;
}

void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to Main Menu...";
	system("pause>0");
	ShowMainMenu();
}

void PerformMainMenuOption(enumMainMenuOptions MainMenuOption)
{
	switch (MainMenuOption)
	{
		case enumMainMenuOptions::enShowClientList:
		{
			system("cls");
			ShowClientsScreen();
			GoBackToMainMenu();
			break;
		}
		case enumMainMenuOptions::enAddNewClient:
		{
			system("cls");
			AddNewClientScreen();
			GoBackToMainMenu();
			break;
		}
		case enumMainMenuOptions::enDeleteClient:
		{
			system("cls");
			DeleteClientScreen();
			GoBackToMainMenu();
			break;
		}
		case enumMainMenuOptions::enUpdateClient:
		{
			system("cls");
			UpdateClientScreen();
			GoBackToMainMenu();
			break;
		}
		case enumMainMenuOptions::enFindClient:
		{
			system("cls");
			FindClientScreen();
			GoBackToMainMenu();
			break;
		}
		case enumMainMenuOptions::enExit:
		{
			system("cls");
			ExitScreen();
			break;
		}
	}
}

void ShowMainMenu()
{
	system("cls");
	cout << "==================================================\n";
	cout << "\t\tBank Menu\n";
	cout << "==================================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Exit.\n";
	cout << "==================================================\n";

	PerformMainMenuOption((enumMainMenuOptions)ReadMainMenuOption());

}

int main()
{

	ShowMainMenu();


	system("pause>0");
	return 0;
}