#include <iostream>
#include <vector>

using namespace std;

struct stEmployee
{
	string FirstName;
	string LastName;
	float Salary;
};

void ReadEmployees(vector<stEmployee>& vEmployees)
{
	char AddMore = 'Y';
	stEmployee tempEmployee;
	
	while (toupper(AddMore) == 'Y')
	{
		cout << "Enter First Name: ";
		cin >> tempEmployee.FirstName;

		cout << "Enter Last Name: ";
		cin >> tempEmployee.LastName;

		cout << "Enter Salary: ";
		cin >> tempEmployee.Salary;

		vEmployees.push_back(tempEmployee);

		cout << "Do you want to add more employees? Y/N: ";
		cin >> AddMore;
		cout << "\n";
	}

}

void PrintEmployees(vector<stEmployee>& vEmployees)
{
	cout << "You have entered the following employees: \n" << endl;

	for (stEmployee& Emp : vEmployees)
	{
		cout << "First Name: " << Emp.FirstName << endl;
		cout << "Last Name : " << Emp.LastName << endl;
		cout << "Salary : " << Emp.Salary << endl;
		cout << "------------------------" << endl;
	}
}

int main()
{
	vector<stEmployee> vEmployees;

	ReadEmployees(vEmployees);
	PrintEmployees(vEmployees);

	return 0;
}