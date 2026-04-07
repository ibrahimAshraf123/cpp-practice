#include <iostream>
#include <string>

using namespace std;

struct stInfo {
	string Name;
	int Age;
	string City;
	string Country;
	int MonthlySalary;
	int YearlySalary;
	char Gender;
	bool Married;
};

void ReadInfo(stInfo& Info) {

	cout << "Please enter your Full Name? \n";
	getline(cin, Info.Name);

	cout << "Please enter your Age? \n";
	cin >> Info.Age;

	cout << "Please enter your City? \n";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, Info.City);

	cout << "Please enter your Country? \n";
	cin >> Info.Country;

	cout << "Please enter your Monthly Salary? \n";
	cin >> Info.MonthlySalary;

	cout << "Please enter your Gender (M/F)? \n";
	cin >> Info.Gender;

	cout << "Please enter your Marital Status (1/0)? \n";
	cin >> Info.Married;

}

void PrintInfo(stInfo Info) {
	cout << "\n*************************\n";
	cout << "Name: " << Info.Name << "\n";
	cout << "Age: " << Info.Age << "\n";
	cout << "City: " << Info.City << "\n";
	cout << "Country: " << Info.Country << "\n";
	cout << "Monthly Salary: " << Info.MonthlySalary << "\n";
	cout << "Yearly Salary: " << (Info.MonthlySalary * 12) << "\n";
	cout << "Gender: " << Info.Gender << "\n";
	cout << "Married: " << (Info.Married ? "Yes":"No") << "\n";
	cout << "\n*************************\n";
}

int main()
{

	stInfo Person1Info;
	ReadInfo(Person1Info);
	PrintInfo(Person1Info);


	return 0;
}





