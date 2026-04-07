#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stClientRecord
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	float AccountBalance;

};

vector<string> SplitString(string str, string seperator)
{
	vector<string> vString;
	int pos = 0;

	for (int i = 0; i < str.length(); i++)
	{
		while ((pos = str.find(seperator)) != string::npos)
		{
			vString.push_back(str.substr(0, pos));
			str.erase(0, pos + seperator.length());
		}
	}

	if (str != "")
	{
		vString.push_back(str);
	}

	return vString;


}

stClientRecord ConvertLineToRecord(string LineRecord)
{
	stClientRecord Client;
	vector<string> vClientRecord;

	vClientRecord = SplitString(LineRecord,"#//#");
	Client.AccountNumber = vClientRecord[0];
	Client.PinCode = vClientRecord[1];
	Client.Name = vClientRecord[2];
	Client.Phone = vClientRecord[3];
	Client.AccountBalance = stof(vClientRecord[4]); //float value
	
	return Client;


}

void PrintClientRecord(stClientRecord Client)
{
	cout << "\n\nThe following is the extracted client record:\n\n";
	cout << "Account Number : "	<< Client.AccountNumber << endl;
	cout << "Pin Code       : "	<< Client.PinCode << endl;
	cout << "Name           : "	<< Client.Name << endl;
	cout << "Phone          : "	<< Client.Phone << endl;
	cout << "Account Balance: "	<< Client.AccountBalance << endl;
}

int main()
{
	
	string LineRecord = "A150#//#1234#//#Mohammed Abu-Hadhoud#//#079999#//#5270.00";
	cout << "\nLine Record is:\n";
	cout << LineRecord;

	stClientRecord Client1 = ConvertLineToRecord(LineRecord);

	PrintClientRecord(Client1);


	system("pause>0");
	return 0;
}