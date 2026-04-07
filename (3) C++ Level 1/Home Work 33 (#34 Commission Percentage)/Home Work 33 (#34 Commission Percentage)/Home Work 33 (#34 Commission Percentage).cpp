
#include <iostream>

using namespace std;

void readTotal(float &total) {
	cout << "Please enter total: \n";
	cin >> total;
}

void printPercentage(float total, float &p) {
	if (total >= 1000000) {
		p = (1.0 / 100);
	}
	else if (total >= 500000) {
		p = (2.0 / 100);
	}
	else if (total >= 100000) {
		p = (3.0 / 100);
	}
	else if (total >= 50000) {
		p = (5.0 / 100);
	}
	else {
		p = (0.0 / 100);
	}
	cout << "Percentage used: " << p * 100 << "%" << endl;
}

float getCommission(float total, float p) {
	float comm = (p * total);
	return comm;
}


int main()
{
	float total;
	float p;
	cout << "This program calculates commission from total and percentage... \n";

	readTotal(total);
	printPercentage(total, p);

	cout << "Your commission is: " << getCommission(total, p) << endl;

	return 0;
}
