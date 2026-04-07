#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";
const string MyDelim = "#//#";

enum enMenu
{
	enShowClientsList = 1,
	enAddNewClient = 2,
	enDeleteClient = 3,
	enUpdateClientInfo = 4,
	enFindClient = 5,
	enExit = 6
};

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

//string manip

vector<string> SplitString(string Line, string Seperator = MyDelim)
{
	vector<string> vLine;
	int pos = 0;

	while ((pos = Line.find(Seperator)) != string::npos)
	{
		vLine.push_back(Line.substr(0, pos));
		Line.erase(0, pos + Seperator.length());
	}
	if (!Line.empty())
	{
		vLine.push_back(Line);
	}

	return vLine;
}

sClient ConvertLineToRecord(string Line)
{
	sClient Client;
	vector<string> vLine = SplitString(Line);

	if (vLine.size() >= 5)
	{
		Client.AccountNumber = vLine[0];
		Client.PinCode = vLine[1];
		Client.Name = vLine[2];
		Client.Phone = vLine[3];
		Client.AccountBalance = stod(vLine[4]);

	}
	return Client;
	
}

string ConvertRecordToLine(sClient Client, string Seperator = MyDelim)
{
	string DataLine ="";
	
	DataLine += Client.AccountNumber + MyDelim;
	DataLine += Client.PinCode + MyDelim;
	DataLine += Client.Name + MyDelim;
	DataLine += Client.Phone + MyDelim;
	DataLine += to_string(Client.AccountBalance) + MyDelim;

	return DataLine;
}

//file manip

vector<sClient> LoadClientsFromFile(string FileName = ClientsFileName)
{
	vector <sClient> vClients;
	string DataLine;

	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if(MyFile.is_open())
	{
		while (getline(MyFile, DataLine))
		{
			vClients.push_back(ConvertLineToRecord(DataLine));
		}
		MyFile.close();
	}
	return vClients;
}

void AddClientsToFile(vector<sClient> vClients, string FileName = ClientsFileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);
	if (MyFile.is_open())
	{
		for (int i = 0; i < vClients.size(); i++)
		{
			if (vClients[i].MarkForDelete == true)
			{
				continue;
			}
			MyFile << ConvertRecordToLine(vClients[i]) << endl;
		}

		MyFile.close();
	}
}

//client manip

void ShowClientsList()
{
	vector<sClient> vClients;
	vClients = LoadClientsFromFile();

	cout << "(" << vClients.size() << ") Client(s) in List: \n";
	cout << "-----------------------------------------------------------------------------------------------------------\n";
	cout << "Account Number \t| PinCode \t\t| Name \t\t| Phone \t\t| Account Balance \n";

	for (int i = 0; i < vClients.size(); i++)
	{
		cout << vClients[i].AccountNumber << "\t\t";
		cout << vClients[i].PinCode << "\t\t";
		cout << vClients[i].Name << "\t\t";
		cout << vClients[i].Phone << "\t\t";
		cout << vClients[i].AccountBalance;
		cout << endl;
	}

}

string ReadAccountNumber()
{
	string AccountNumber;
	cout << "\nPlease enter Account Number? ";
	cin >> AccountNumber;
	return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient> &vClients, sClient& Client)
{
	for (int i = 0; i < vClients.size(); i++)
	{
		if (vClients[i].AccountNumber == AccountNumber)
		{
			Client = vClients[i];
			return true;
		}
	}
	return false;
}

int FindClientIndexByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	for (int i = 0; i < vClients.size(); i++)
	{
		if (vClients[i].AccountNumber == AccountNumber)
		{
			return i;
		}
	}
	return -1;
}

void DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	int Index = FindClientIndexByAccountNumber(AccountNumber, vClients);

	if (Index != -1)
	{
		vClients[Index].MarkForDelete = true;
		AddClientsToFile(vClients);
		cout << "\nClient deleted Successfully\n";
	}
	else
	{
		cout << "\nClient account number (" << AccountNumber << ") Not Found! \n";
	}
}

void printClientCard(sClient Client)
{
	cout << "\nClient Card:\n";
	cout << "--------------------------------\n";
	cout << "Account Number: " << Client.AccountNumber << endl;
	cout << "Account PinCode: " << Client.PinCode << endl;
	cout << "Account Name: " << Client.Name << endl;
	cout << "Account Phone: " << Client.Phone << endl;
	cout << "Account Balance: " << Client.AccountBalance << endl;
	cout << "--------------------------------\n";
}

sClient ReadClientRecord(bool MarkForUpdate = false, string AccountNumber = "")
{
	vector<sClient> vClients = LoadClientsFromFile();
	sClient Client;

	cout << "\nPlease fill in Client Record: \n";
	if (!MarkForUpdate)
	{
		cout << "\nAccount Number? ";
		getline(cin >> ws, AccountNumber);

		if (FindClientByAccountNumber(AccountNumber, vClients, Client))
		{
			cout << "\nAccount number (" << Client.AccountNumber << ") already exists, please choose another. \n";
			return ReadClientRecord();
		}
	}
	
		Client.AccountNumber = AccountNumber;

		cout << "\nAccount PinCode? ";
		getline(cin>>ws, Client.PinCode);

		cout << "\nAccount Name? ";
		getline(cin, Client.Name);

		cout << "\nAccount Phone? ";
		getline(cin, Client.Phone);

		cout << "\nAccount Balance? ";
		cin >> Client.AccountBalance;

		return Client;

}

void UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	int Index = FindClientIndexByAccountNumber(AccountNumber, vClients);

	if (Index != -1)
	{
		vClients[Index] = ReadClientRecord(true, AccountNumber);
		AddClientsToFile(vClients);
		cout << "\nClient Updated successfully\n";
	}
	else
	{
		cout << "\nClient account number (" << AccountNumber << ") Not Found! \n";
	}
}

//screens
void ShowClientsListScreen()
{
	system("cls");
	cout << "you choose [1] ShowClientsList.\n";
	ShowClientsList();

	cout << "\nClick any button to go back to main menu...\n";
	system("pause>0");
}

void FindClientScreen()
{
	system("cls");
	cout << "you choose [5] FindClient.\n\n";
	vector<sClient> vClients = LoadClientsFromFile();
	string AccountNumber = ReadAccountNumber();
	sClient Client;

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		printClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!\n";
	}

	cout << "\nClick any button to go back to main menu...\n";
	system("pause>0");
}

void AddNewClientScreen()
{
	system("cls");
	cout << "you choose [2] AddNewClient.\n\n";

	vector<sClient> vClients = LoadClientsFromFile();
	sClient Client = ReadClientRecord();
	vClients.push_back(Client);

	AddClientsToFile(vClients);
	cout << "\nClient added successfully\n";

	cout << "\nClick any button to go back to main menu...\n";
	system("pause>0");
	
}

void DeleteClientScreen()
{
	system("cls");
	cout << "you choose [3] DeleteClient.";

	vector<sClient> vClients = LoadClientsFromFile();
	string AccountNumber = ReadAccountNumber();

	DeleteClientByAccountNumber(AccountNumber,vClients);

	cout << "\nClick any button to go back to main menu...\n";
	system("pause>0");
}

void UpdateClientScreen() 
{
	system("cls");
	cout << "you choose [4] UpdateClientInfo.";

	vector<sClient> vClients = LoadClientsFromFile();
	string AccountNumber = ReadAccountNumber();

	UpdateClientByAccountNumber(AccountNumber,vClients);
	

	cout << "\nClick any button to go back to main menu...\n";
	system("pause>0");
}
//
void MenuSelection(int Choice)
{
	enMenu Menu;
	
		switch (Choice)
		{
			case enMenu::enShowClientsList:
			{
				ShowClientsListScreen(); break;
			}

			case enMenu::enFindClient:
			{
				FindClientScreen(); break;
			}

			case enMenu::enAddNewClient:
			{
				AddNewClientScreen(); break;
			}

			case enMenu::enDeleteClient:
			{
				DeleteClientScreen(); break;
			}

			case enMenu::enUpdateClientInfo:
			{
				UpdateClientScreen(); break;
			}


			case enMenu::enExit: //done
			{
				//system("cls");
				//cout << "you choose [6] Exit.";
				break;
			}
			default:
			{
				system("cls");
				cout << "INVALID";
			}

		}
}

void ShowMainMenu()
{
	int Choice;

	do
	{
		system("cls");
		cout << "===================================\n";
		cout << "\tMain Menu Screen\n";
		cout << "===================================\n";
		cout << "\t[1] Show Clients List.\n";
		cout << "\t[2] Add New Client. \n";
		cout << "\t[3] Delete Client. \n";
		cout << "\t[4] Update Client Info. \n";
		cout << "\t[5] Find Client.\n";
		cout << "\t[6] Exit.\n";
		cout << "===================================\n";
		cout << "Choose what do you want to do? [1 to 6]? ";
		cin >> Choice;
		MenuSelection(Choice);
	}while (Choice != 6);
	

}

int main()
{

	ShowMainMenu();


	system("pause>0");

	return 0;
}