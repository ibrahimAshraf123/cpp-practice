#include <iostream>

using namespace std;

class clsPerson
{
public:
	virtual void Print() //virtual function helps in upcasting with override
	{
		cout << "Hi, I'm a person!\n";
	}
};

class clsStudent : public clsPerson
{
public:
	void Print()
	{
		cout << "Hi, I'm a student!\n";
	}
};

class clsEmployee : public clsPerson
{
public:
	void Print()
	{
		cout << "Hi, I'm an employee!\n";
	}
};


int main()
{
	clsStudent Student1;
	clsEmployee Employee1;
	//Early-Static Binding (in compilation time, before runtime, faster)
	Student1.Print();
	Employee1.Print();
	
	//upcasting + virtual function = retain function override, when upcasting derivedClass to baseClass
	clsPerson* Perosn1 = &Student1;
	clsPerson* Perosn2 = &Employee1;
	//Late-Dynamic Binding (in runtime, compiler gets it after runnning)
	Perosn1->Print();
	Perosn2->Print();

	system("pause>0");
	return 0;
}