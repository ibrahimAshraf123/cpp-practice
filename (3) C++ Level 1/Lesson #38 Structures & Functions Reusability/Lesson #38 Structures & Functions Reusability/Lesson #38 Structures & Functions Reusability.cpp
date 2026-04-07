
#include <iostream>
#include <string>

using namespace std;

struct strInfo {
	string FirstName;
	string LastName;
	string FavQuote;
	int Age;
	string Phone;
};

void ReadInfo(strInfo &Info) {

	cout << "Please enter First Name? \n";
	cin >> Info.FirstName;
	cout << "Please enter Last Name? \n";
	cin >> Info.LastName;
	cout << "Please enter Age? \n";
	cin >> Info.Age;
	cout << "Please enter Phone? \n";
	cin >> Info.Phone;
	cout << "Please enter Favourite Quote? \n";
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	getline(cin, Info.FavQuote);
	cout << "\n";
}

void PrintInfo(strInfo Info) {
	

	cout << "\n**************************** \n";
	cout << "First Name: " << Info.FirstName << "\n";
	cout << "Last Name: " << Info.LastName << "\n";
	cout << "Age: " << Info.Age << "\n";
	cout << "Phone: " << Info.Phone << "\n";
	cout << "Favourite Quote: \"" << Info.FavQuote << "\"\n";
	cout << "\n**************************** \n";
}

int main()
{
	strInfo Person1Info;
	ReadInfo(Person1Info);
	PrintInfo(Person1Info);

	strInfo Person2Info;
	ReadInfo(Person2Info);
	PrintInfo(Person2Info);

	return 0;
}
