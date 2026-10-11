
#include <iostream>

using namespace std;

struct stInfo {
	string FirstName;
	string LastName;
	int Age;
	string Phone;
};



int main()
{
	stInfo Persons[2];

	Persons[0].FirstName = "Ibrahim";
	Persons[0].LastName = "Ashraf";
	Persons[0].Age = 26;
	Persons[0].Phone = "0563034846";

	Persons[1].FirstName = "Ali";
	Persons[1].LastName = "Maher";
	Persons[1].Age = 33;
	Persons[1].Phone = "2345676545";

	cout << Persons[0].FirstName;

	return 0;
}
