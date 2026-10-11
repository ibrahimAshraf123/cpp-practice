#include <iostream>
using namespace std;

struct stEmployee
{
	string name;
	int salary;

};


int main()
{
	stEmployee CEO;
	stEmployee* Ptr;

	Ptr = &CEO;

	CEO.name = "Mohammad";
	CEO.salary = 4000;

	cout << "Name: " << CEO.name << endl;
	cout << "Salary: " << CEO.salary << endl;
	cout << endl;

	cout << "Using Pointer: " << endl;
	cout << "Name: " << Ptr->name << endl;
	cout << "Salary: " << Ptr->salary << endl;
	cout << endl;



	return 0;
}