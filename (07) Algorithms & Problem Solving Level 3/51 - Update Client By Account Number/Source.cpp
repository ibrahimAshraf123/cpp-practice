//program to update client by account number

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

const string ClientsFileName = "Clients.txt";
const string MySeperator = "#//#";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};

string ReadAccountNumber()
{
	string Number;
	cout << "Please enter Account Number? ";
	cin >> Number;
	return Number;
}

vector<string> SplitString(string String, string Seperator = MySeperator)
{
	vector<string> vString;
	int pos = 0;

	while ((pos = String.find(Seperator)) != string::npos)
	{
		vString.push_back(String.substr(0, pos));
		String.erase(0, pos + Seperator.length());
	}
	if (!String.empty())
	{
		vString.push_back(String);
	}

	return vString;
}

sClient ConvertLineToRecord(string DataLine)
{
	sClient Client;
	vector<string> vDataLine = SplitString(DataLine);

	if (vDataLine.size() >= 5)
	{
		Client.AccountNumber = vDataLine[0];
		Client.PinCode = vDataLine[1];
		Client.Name= vDataLine[2];
		Client.Phone= vDataLine[3];
		Client.AccountBalance= stod(vDataLine[4]);
	}

	return Client;

}

string ConvertRecordToLine(sClient Client, string Seperator = MySeperator)
{
	string DataLine = "";

	DataLine += Client.AccountNumber + Seperator;
	DataLine += Client.PinCode + Seperator;
	DataLine += Client.Name + Seperator;
	DataLine += Client.Phone + Seperator;
	DataLine += to_string(Client.AccountBalance);

	return DataLine;
}

vector<sClient> LoadClientsFromFile(string FileName)
{
	vector<sClient> vClients;
	

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string DataLine;
		sClient Client;

		while (getline(MyFile, DataLine))
		{
			Client = ConvertLineToRecord(DataLine);
			vClients.push_back(Client);
		}
		MyFile.close();
	}

	return vClients;
}

void PrintClientDetails(sClient Client)
{
	cout << "\n\nThe following are the client details:\n";
	cout << "\nAccount Number : "	<< Client.AccountNumber;
	cout << "\nPinCode        : "	<< Client.PinCode;
	cout << "\nName           : "	<< Client.Name;
	cout << "\nPhone          : "	<< Client.Phone;
	cout << "\nAccount Balance: "	<< Client.AccountBalance;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient>& vClients, sClient &Client)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

sClient ChangeClientRecord(string AccountNumber)
{
	sClient Client;

	Client.AccountNumber = AccountNumber;

	cout << "\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "\nEnter Name? ";
	getline(cin >> ws, Client.Name);

	cout << "\nEnter Phone? ";
	getline(cin, Client.Phone);

	cout << "\nEnter AccountBalance? ";
	cin >> Client.AccountBalance;

	return Client;
}

void SaveClientsToFile(string FileName, vector<sClient> vClients)
{

	fstream MyFile;
	MyFile.open(FileName, ios::out);

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

bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientDetails(Client);
		cout << "\n\nAre you sure you want to update this client? y/n? ";

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
			SaveClientsToFile(ClientsFileName, vClients);

			cout << "\n\nClient Updated Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\n\nClient with Account Number (" << AccountNumber << ") Not Found!";
		return false;
	}
	
	
}

int main()
{
	vector<sClient> vClients = LoadClientsFromFile(ClientsFileName);
	string AccountNumber = ReadAccountNumber();

	UpdateClientByAccountNumber(AccountNumber, vClients);



	system("pause>0");

	return 0;
}