using namespace std;
#include <iostream>

struct stInfo {
	string FirstName;
	string LastName;
	int Age;
	string Phone;
};

void readInfo(stInfo Persons[100]) {
	
	cout << "First Name: ";
	cin >> Persons[0].FirstName;
	cout << "Last Name: ";
	cin >> Persons[0].LastName;
	cout << "Age: ";
	cin >> Persons[0].Age;
	cout << "Phone: ";
	cin >> Persons[0].Phone;
}

void printInfo(stInfo Persons[100]) {
	cout << "************************\n";
	cout << "First Name: " << Persons[0].FirstName << "\n";
	cout << "Last Name : " << Persons[0].LastName << "\n";
	cout << "Age       : " << Persons[0].Age << "\n";
	cout << "Phone     : " << Persons[0].Phone << "\n";
	cout << "************************\n";
}

void readPersonsInfo(stInfo Persons[100], int &length) {
	cout << "How many persons you want to enter? \n";
	cin >> length;
	cout << "************************\n";
	
	for (int i = 0; i <= length - 1; i++) {
		cout << "please enter Person " << i + 1 << " Info: \n";
		readInfo(Persons);
		cout << "\n";
	}
}

void printPersonsInfo(stInfo Persons[100], int length) {

	for (int i = 0; i <= length - 1; i++) {
		cout << "Person number [" << i + 1 << "] Info: \n";
		printInfo(Persons);
		cout << "\n";
	}
}


int main()
{
	stInfo Persons[100];
	int length;
	readPersonsInfo(Persons, length);
	printPersonsInfo(Persons, length);
	
	return 0;
}
