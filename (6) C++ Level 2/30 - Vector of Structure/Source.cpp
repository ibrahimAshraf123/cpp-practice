#include <iostream>
#include <vector>

using namespace std;

struct stEmployee
{
	string FirstName;
	string LastName;
	float Salary;
};

int main()
{
	//create a stEmployee vector
	//fill using tempEmployee
	//print contents of stEmployee Vector

	vector <stEmployee> vEmployees;

	stEmployee tempEmployee;

	tempEmployee.FirstName = "Mohammed";
	tempEmployee.LastName = "Abu-Hadhoud";
	tempEmployee.Salary = 1000;
	vEmployees.push_back(tempEmployee);


	tempEmployee.FirstName = "Ibrahim";
	tempEmployee.LastName = "Ashraf";
	tempEmployee.Salary = 2000;
	vEmployees.push_back(tempEmployee);


	tempEmployee.FirstName = "Pontiff";
	tempEmployee.LastName = "Sulyvan";
	tempEmployee.Salary = 3000;
	vEmployees.push_back(tempEmployee);

	for (stEmployee & Employee : vEmployees)
	{
		cout << "First Name = " << Employee.FirstName << endl;
		cout << "Last Name = " << Employee.LastName << endl;
		cout << "Salary = " << Employee.Salary << endl;
		cout << endl;
	}






	return 0;
}