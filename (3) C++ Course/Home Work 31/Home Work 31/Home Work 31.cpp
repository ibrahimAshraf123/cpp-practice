
#include <iostream>

using namespace std;

struct stInfo {
	string FirstName;
	string LastName;
	int Age;
	string Phone;
};

void readInfo(stInfo &Info){
	cout << "Please enter First Name? \n";
	cin >> Info.FirstName;
	cout << "Please enter Last Name? \n";
	cin >> Info.LastName;
	cout << "Please enter Age? \n";
	cin >> Info.Age;
	cout << "Please enter Phone? \n";
	cin >> Info.Phone;
}

void printInfo(stInfo Info) {
	cout << "\n*******************************\n";
	cout << "First Name: " << Info.FirstName << "\n";
	cout << "Last Name: " << Info.LastName << "\n";
	cout << "Age: " << Info.Age << "\n";
	cout << "Phone: " << Info.Phone << "\n";
	cout << "\n*******************************\n";
}

void readPersonsInfo(stInfo Persons[2]) {
	readInfo(Persons[0]);
	cout << "\n************************\n";
	readInfo(Persons[1]);
}

void printPersonsInfo(stInfo Persons[2]) {
	printInfo(Persons[0]);
	printInfo(Persons[1]);
}

int main()
{
	stInfo Persons[2];

	readPersonsInfo(Persons);
	printPersonsInfo(Persons);

	return 0;
}
