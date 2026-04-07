
#include <iostream>

using namespace std;

enum enCountry{Japan = 1, China = 2, USA = 3, KSA = 4, UK = 5, Thailand = 6, Russia = 7, Other = 8 };

void readSelection(int &c, enCountry &country) {
	cout << "Which country do you want to visit?\n";
	cout << "(1) Japan\n";
	cout << "(2) China\n";
	cout << "(3) USA\n";
	cout << "(4) KSA\n";
	cout << "(5) UK\n";
	cout << "(6) Thailand\n";
	cout << "(7) Russia\n";
	cout << "(8) Other\n";
	cout << "************************************\n";

	cin >> c;
	country = (enCountry)c;

	if (country == enCountry::Japan) {
		cout << "Your choice is Japan\n";
	}

	else if (country == enCountry::China) {
		cout << "Your choice is China\n";
	}

	else if (country == enCountry::USA) {
		cout << "Your choice is USA\n";
	}

	else if (country == enCountry::KSA) {
		cout << "Your choice is KSA\n";
	}

	else if (country == enCountry::UK) {
		cout << "Your choice is UK\n";
	}

	else if (country == enCountry::Thailand) {
		cout << "Your choice is Thailand\n";
	}

	else if (country == enCountry::Russia) {
		cout << "Your choice is Russia\n";
	}

	else {
		cout << "Your choice is Other\n";
	}
}

int main()
{
	int c;
	enCountry country;

	readSelection(c, country);

	

	return 0;
}
