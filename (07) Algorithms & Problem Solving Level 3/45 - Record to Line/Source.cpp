#include <iostream>
#include <string>

using namespace std;

struct stCLientData
{
	string AccountNumber = "";
	short PinCode = 0;
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;
};

stCLientData ReadClientData()
{
	stCLientData Client1;
	cout << "Please enter Client Data: \n\n";

	cout << "Enter Account Number: ";
	getline(cin, Client1.AccountNumber);

	cout << "Enter PinCode: ";
	cin >> Client1.PinCode;
	cin.ignore();

	cout << "Enter Name: ";
	getline(cin, Client1.Name);

	cout << "Enter Phone: ";
	getline(cin,Client1.Phone);

	cout << "Enter AccountBalance: ";
	cin >> Client1.AccountBalance;

	return Client1;
}

string RecordToLine(stCLientData Client, string Seperator = "#//#")
{
	string Line = "";

	Line += Client.AccountNumber + Seperator;
	Line += to_string(Client.PinCode) + Seperator;
	Line += Client.Name + Seperator;
	Line += (Client.Phone) + Seperator;
	Line += to_string(Client.AccountBalance);
	return Line;
}

int main()
{
	stCLientData CLient1;
	CLient1 = ReadClientData();

	cout << "\nClient Record for saving is: \n";
	cout << RecordToLine(CLient1);


	system("pause>0");
}