#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string ClientsFileName = "Clients.txt";
const string DefaultSeperator = "#//#";

struct sClientData
{
	string AccNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccBalance;
	bool MarkForDeletion = false;

};

vector<string> SplitString(string String, string Seperator = DefaultSeperator)
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

sClientData ConvertLineToRecord(string LineString)
{
	sClientData Data;
	vector< string> vDataLine = SplitString(LineString);

	if (vDataLine.size() >= 5)
	{
		Data.AccNumber = vDataLine[0];
		Data.PinCode = vDataLine[1];
		Data.Name = vDataLine[2];
		Data.Phone = vDataLine[3];
		Data.AccBalance = stod(vDataLine[4]);
	}
	
	return Data;
}

string ConvertRecordToLine(sClientData Record, string Seperator = DefaultSeperator)
{
	string DataLine = "";
	DataLine += Record.AccNumber + Seperator;
	DataLine += Record.PinCode + Seperator;
	DataLine += Record.Name + Seperator;
	DataLine += Record.Phone + Seperator;
	DataLine += to_string(Record.AccBalance);

	return DataLine;

}

vector<sClientData> LoadClientsFromFile(string FileName = ClientsFileName)
{
	vector<sClientData> vAllClients;
	string Line;

	fstream MyFile;
	MyFile.open(FileName, ios::in);
	
	if (MyFile.is_open())
	{
		while (getline(MyFile, Line))
		{
			vAllClients.push_back(ConvertLineToRecord(Line));
		}
		MyFile.close();
	}

	return vAllClients;
}

string ReadAccountNumber()
{
	string AccNum;
	cout << "Please enter Account Number? ";
	cin >> AccNum;
	return AccNum;
}

void PrintClientCard(sClientData Client)
{
	cout << "\nThe following are the client details:\n";

	cout << "\nAccount Number : " << Client.AccNumber	<< endl;
	cout << "\nPinCode        : " << Client.PinCode		<< endl;
	cout << "\nName           : " << Client.Name		<< endl;
	cout << "\nPhone          : " << Client.Phone		<< endl;
	cout << "\nAccount Balance: " << Client.AccBalance	<< endl;
}

bool FoundClientByAccountNumber(string AccountNumber, vector<sClientData> &vAllClients, sClientData &Client)
{
	for (sClientData& C : vAllClients)
	{
		if (C.AccNumber == AccountNumber)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClientData> &vAllClients)
{
	for (sClientData& C : vAllClients)
	{
		if (C.AccNumber == AccountNumber)
		{
			C.MarkForDeletion = true;
			return true;
		}
	}
	return false;
}

vector<sClientData> SaveClientsDataToFile(string FileName, vector<sClientData> vAllClients)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out);

	string DataLine;

	if (MyFile.is_open())
	{
		for (sClientData& C : vAllClients)
		{
			if (C.MarkForDeletion == false)
			{
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}

		MyFile.close();
	}
	return vAllClients;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClientData>& vAllClients)
{
	sClientData Client;
	char Answer = 'n';

	if (FoundClientByAccountNumber(AccountNumber, vAllClients, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want to delete this client? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vAllClients);
			SaveClientsDataToFile(ClientsFileName, vAllClients);

			vAllClients = LoadClientsFromFile(ClientsFileName);

			cout << "\n\nClient deleted successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with account number (" << AccountNumber << ") Not Found!";
		return false;
	}
	return false;
}

int main()
{
	vector<sClientData> vAllClients = LoadClientsFromFile(ClientsFileName);

	string AccountNumber = ReadAccountNumber();

	DeleteClientByAccountNumber(AccountNumber, vAllClients);


	system("pause>0");

	return 0;
}