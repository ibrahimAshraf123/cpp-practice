using namespace std;

#include <iostream>

enum enCountry {UAE = 1, KSA = 2, OMAN = 3, QATAR = 4, KUWAIT = 5, BAHRAIN = 6};

void readChoice(int &choice) {
	cout << "Choose your Country:\n";
	cout << " UAE = 1,\n KSA = 2,\n OMAN = 3,\n QATAR = 4,\n KUWAIT = 5,\n BAHRAIN = 6\n";
	cout << endl;


	cin >> choice;
	
}

void printCountry(int choice, enCountry &Country) {
	Country = (enCountry)choice;

	switch (Country) {
	case enCountry::UAE:
		cout << "You chose UAE \n";
		break;
	case enCountry::KSA:
		cout << "You chose KSA \n";
		break;
	case enCountry::OMAN:
		cout << "You chose OMAN\n";
		break;
	case enCountry::QATAR:
		cout << "You chose QATAR\n";
		break;
	case enCountry::KUWAIT:
		cout << "You chose KUWAIT\n";
		break;
	case enCountry::BAHRAIN:
		cout << "You chose BAHRAIN\n";
		break;
	default:
		cout << "You chose Other...\n";

	}
}

int main()
{
	
	int choice;
	enCountry Country;

	readChoice(choice);
	printCountry(choice, Country);
	
	return 0;
}
