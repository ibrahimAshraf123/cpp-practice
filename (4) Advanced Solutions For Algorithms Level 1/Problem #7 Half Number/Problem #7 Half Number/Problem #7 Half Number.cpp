
#include <iostream>
#include <string>

using namespace std;

int ReadNum() {
	int Num;
	cout << "Enter number:\n";
	cin >> Num;

	return Num;
}

float Half(int Num) {
	return (float)Num/2;
}

void PrintHalfNumber(int Num) {
	string Result = "Half of " + to_string(Num) + " is " + to_string(Half(Num));
	cout << endl << Result << endl;
}

int main()
{

	PrintHalfNumber(ReadNum());

	return 0;
}
