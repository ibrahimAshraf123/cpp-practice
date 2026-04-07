
#include <iostream>

using namespace std;

void readMonth(int &num, string month[12]) {
	
	cout << "Please enter a number: \n";
	cin >> num;

	if (num >= 1 && num <= 12) {

		if (num == 1) {
			cout << month[0];
		}

		else if (num == 2) {
			cout << month[1];
		}


		else if (num == 3) {
			cout << month[2];
		}

		else if (num == 4) {
			cout << month[3];
		}

		else if (num == 5) {
			cout << month[4];
		}

		else if (num == 6) {
			cout << month[5];
		}

		else if (num == 7) {
			cout << month[6];
		}

		else if (num == 8) {
			cout << month[7];
		}

		else if (num == 9) {
			cout << month[8];
		}

		else if (num == 10) {
			cout << month[9];
		}

		else if (num == 11) {
			cout << month[10];
		}

		else if (num == 12) {
			cout << month[11];
		}
	}
	else {
		cout << "ERROR\n";
		readMonth(num, month);
	}
}

int main()
{
	int num;
	string month[12] = { "January","Febraury","March","April","May","June","July","August","September","October","November","December" };

	readMonth(num, month);
	

	return 0;
}
