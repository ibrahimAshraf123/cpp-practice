#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

string ClientsFileName = "Clients.txt";

struct stClientRecord {
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

vector<string> SplitString(string S1, string DeLim = "#//#")
{
	vector<string> vString;
	int pos = 0;

	while ((pos = S1.find(DeLim)) != string::npos)
	{
		
		
			vString.push_back(S1.substr(0,pos));
			S1.erase(0, pos + DeLim.length());
		
	}

	if (S1 != "")
	{
		vString.push_back(S1);
	}

	return vString;
}

stClientRecord ConvertLineToRecord(string DataLine)
{
	stClientRecord Client1;
	vector<string> vClientData = SplitString(DataLine);

	Client1.AccountNumber = vClientData[0];
	Client1.PinCode = vClientData[1];
	Client1.Name = vClientData[2];
	Client1.Phone = vClientData[3];
	Client1.AccountBalance = stod(vClientData[4]);

	return Client1;
}

vector<stClientRecord> ReadClientsFromFile(string FileName)
{
	vector<stClientRecord> vAllClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in);
	

	if (MyFile.is_open())
	{
		string Line;
		stClientRecord Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);

			vAllClients.push_back(Client);
		}
		MyFile.close();
	}
	
	return vAllClients;
}

void PrintClientData(stClientRecord Client1)
{
	cout << "| " << setw(15) << left << Client1.AccountNumber;
	cout << "| " << setw(10) << left << Client1.PinCode;
	cout << "| " << setw(40) << left << Client1.Name;
	cout << "| " << setw(12) << left << Client1.Phone;
	cout << "| " << setw(12) << left << Client1.AccountBalance;

}

void ShowAllClients(vector<stClientRecord> &AllClients)
{

	cout << "\nClient List (" << AllClients.size() << ") Client(s).\n";
	cout << "\n------------------------------------------------------------------------------------------------\n";

	cout << "| " << left << setw(15) << "AccountNumber";
	cout << "| " << left << setw(10) << "PinCode";
	cout << "| " << left << setw(40) << "Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12)  << "Balance";

	cout << "\n------------------------------------------------------------------------------------------------\n";

	for (const stClientRecord& Client : AllClients)
	{
		PrintClientData(Client);
		cout << endl;
	}
}

int main()
{
	vector<stClientRecord> vClients = ReadClientsFromFile(ClientsFileName);

	ShowAllClients(vClients);



	system("pause>0");

	return 0;
}