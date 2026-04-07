//program to delete account by account number

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClientData
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;

};

vector<string> SplitString(string String, string Seperator = "#//#")
{
	vector<string> vSplitString;
	int pos = 0;

	while ((pos = String.find(Seperator)) != string::npos)
	{
		vSplitString.push_back(String.substr(0, pos));
		String.erase(0, pos + Seperator.length());
	}
	if (!String.empty())
	{
		vSplitString.push_back(String);
	}

	return vSplitString;
}

stClientData ConvertLineToData(string DataLine)
{
	stClientData Data;
	vector<string> vDataLine = SplitString(DataLine);

	Data.AccountNumber = vDataLine[0];
	Data.PinCode = vDataLine[1];
	Data.Name = vDataLine[2];
	Data.Phone = vDataLine[3];
	Data.AccountBalance = stod(vDataLine[4]);

	return Data;
}

vector<stClientData> LoadClientsDataFromFile(string FileName = ClientsFileName)
{
	vector<stClientData> vAllClients;
	string Line;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		while (getline(MyFile, Line))
		{
			vAllClients.push_back(ConvertLineToData(Line));
		}
		MyFile.close();
	}

	return vAllClients;
}

string ReadAccountNumber()
{
	string AccountNumber;
	cout << "Please enter Account Number? ";
	cin >> AccountNumber;
	return AccountNumber;
}

void PrintClientCard(stClientData Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "\nAccount Number : " << Client.AccountNumber;
	cout << "\nPinCode        : " << Client.PinCode;
	cout << "\nName           : " << Client.Name;
	cout << "\nPhone          : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
}

bool FoundClientByAccountNumber(string AccountNumber, vector<stClientData> &vAllClients, stClientData & Client)
{

	for (stClientData C : vAllClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool Confirmed(string ConfirmQuestion)
{
	char c;
	cout << ConfirmQuestion;
	cin >> c;
	if (toupper(c) == 'Y')
		return true;
	return false;
}

void DeleteClientByAccountNumber(string AccountNumber, vector<stClientData> &vAllClients)
{
	if (Confirmed("\nAre you sure you want to delete this client? y/n ? "))
	{
		for (int i = 0; i < vAllClients.size(); i++)
		{
			if (vAllClients[i].AccountNumber == AccountNumber)
			{
				vAllClients.erase(vAllClients.begin() + i);
				cout << "\nClient Deleted Succesfully.\n";
				return;
			}
		}
	}
	else
	{
		cout << "\nClient Not Deleted.\n";
	}
	
}

void SaveClientsDataToFile(string FileName, vector<stClientData> vAllClients, string Seperator = "#//#")
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (stClientData C : vAllClients)
		{
			MyFile 
				<< C.AccountNumber << Seperator 
				<< C.PinCode << Seperator 
				<< C.Name << Seperator 
				<< C.Phone << Seperator 
				<< C.AccountBalance << endl;
				
		}
		MyFile.close();
	}
}

int main()
{
	vector<stClientData> vAllClients = LoadClientsDataFromFile();
	stClientData Client;
	string AccountNumber = ReadAccountNumber();

	if (FoundClientByAccountNumber(AccountNumber, vAllClients,Client))
	{
		PrintClientCard(Client);
		DeleteClientByAccountNumber(AccountNumber, vAllClients);
		SaveClientsDataToFile(ClientsFileName, vAllClients);
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") Not Found!\n";
	}



	system("pause>0");

	return 0;
}