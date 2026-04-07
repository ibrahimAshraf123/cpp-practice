#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const string ClientsFileName = "Clients.text";

struct stClientsRecords
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;

};

stClientsRecords ReadClientRecord()
{
	stClientsRecords Client1;

	cout << "Enter Account Number? ";
	getline(cin >> ws, Client1.AccountNumber);

	cout << "Enter PinCode? ";
	getline(cin, Client1.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client1.Name);

	cout << "Enter Phone? ";
	getline(cin, Client1.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client1.AccountBalance;

	return Client1;
}

string RecordToLine(stClientsRecords Client1, string seperator = "#//#")
{
	string Line = "";

	Line += Client1.AccountNumber + seperator;
	Line += Client1.PinCode + seperator;
	Line += Client1.Name + seperator;
	Line += Client1.Phone + seperator;
	Line += to_string(Client1.AccountBalance);

	return Line;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;
		MyFile.close();
	}
}

void AddNewClient()
{
	stClientsRecords Client1;
	Client1 = ReadClientRecord();

	AddDataLineToFile(ClientsFileName, RecordToLine(Client1));

}

void AddClients()
{
	char AddMore = 'Y';

	do
	{
		system("cls");
		cout << "Adding New Client:\n\n";

		AddNewClient();
		cout << "\n\nClient Added Successfully, do you want to add more clients? (Y/N)\n";
		cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}

int main()
{

	AddClients();

	system("pause>0");

	return 0;
}