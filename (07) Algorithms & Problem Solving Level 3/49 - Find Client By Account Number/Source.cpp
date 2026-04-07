#include <iostream>
#include <string>
#include <vector>
#include<fstream>

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

vector<string> SplitString(string sDataLine, string seperator = "#//#")
{
	vector<string> vData;
	int pos = 0;
	
	while ((pos = sDataLine.find(seperator)) != string::npos)
	{
		vData.push_back(sDataLine.substr(0, pos));
		sDataLine.erase(0, pos + seperator.length());

	}
	if (!sDataLine.empty())
	{
		vData.push_back(sDataLine);
	}
	return vData;
	
}

stClientData ConvertLineToRecord(string Line)
{
	stClientData Client;
	vector<string> vDataLine;

	vDataLine = SplitString(Line);

	Client.AccountNumber = vDataLine[0];
	Client.PinCode = vDataLine[1];
	Client.Name = vDataLine[2];
	Client.Phone = vDataLine[3];
	Client.AccountBalance = stod(vDataLine[4]);

	return Client;

}

vector <stClientData> LoadClientsDataFromFile(string FileName = ClientsFileName)
{
	vector <stClientData> vAllClients;
	string Line;

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		while(getline(MyFile, Line))
		{
			vAllClients.push_back(ConvertLineToRecord(Line));
		}
		MyFile.close();
	}
	

	return vAllClients;
}

void PrintClientCard(stClientData Client)
{
	cout << "\nThe following are the client details:"			<< endl;
	cout << "Acount Number  : "	<< Client.AccountNumber		<< endl;
	cout << "Pin Code       : "	<< Client.PinCode			<< endl;
	cout << "Name           : "	<< Client.Name				<< endl;
	cout << "Phone          : "	<< Client.Phone				<< endl;
	cout << "Account Balance: " << Client.AccountBalance	<< endl;
}

bool FindClientByAccountNumber(string AccountNumber, stClientData& Client)
{
	vector <stClientData> vClients = LoadClientsDataFromFile(ClientsFileName);
	
	for (stClientData C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}	
	}
	return false;
}

string ReadClientAccountNumber()
{
	string AccountNumber;
	cout << "Please Enter Account Number? ";
	cin >> AccountNumber;
	return AccountNumber;
}

int main()
{
	stClientData Client;
	string AccountNumber = ReadClientAccountNumber();

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with account number (" << AccountNumber << ") Not Found!\n";
	}




	system("pause>0");

	return 0;
}