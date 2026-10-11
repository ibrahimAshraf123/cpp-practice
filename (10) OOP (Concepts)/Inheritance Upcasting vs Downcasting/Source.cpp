//Inheritance UpCasting vs DownCasting
//UpCasting: convert derivedClass to baseClass using pointer
//DownCasting: convert baseClass to derivedClass (NOT POSSIBLE)

#include <iostream>

using namespace std;

class clsPerson
{
public:
	string Name = "Ibrahim Ashraf";
};

class clsEmployee : public clsPerson
{
public:
	string Title = "Software Engineer";
};

int main()
{
	clsPerson Person1;
	clsEmployee Employee1;
	cout << "Base class Person: \n";
	cout << Person1.Name << endl;
	cout << "\n";

	cout << "Derived class Employee: \n";
	cout << Employee1.Name << endl;
	cout << Employee1.Title << endl;
	cout << "\n";

	cout << "Upcasting (derivedClass to baseClass) Employee to person: \n";
	//Upcasting (derivedClass to baseClass)
	clsPerson* Person2 = &Employee1;
	cout << Person2->Name << endl;
	

	system("pause>0");
	return 0;
}