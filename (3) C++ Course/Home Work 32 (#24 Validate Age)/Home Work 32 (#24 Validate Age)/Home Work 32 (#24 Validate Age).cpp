
#include <iostream>

using namespace std;

void readAge(int &age) {
	cout << "Please enter age: (must be 18 to 45) \n";
	cin >> age;
}

void ValidateAge(int age) {
	if (age >= 18 && age <= 45) {
		cout << "Valid Age \n";
	}
	else {
		cout << "Invalid Age \n";
	}
}

int main()
{
	int age;
	readAge(age);
	ValidateAge(age);

	return 0;
}
