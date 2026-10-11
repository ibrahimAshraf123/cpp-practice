#include <iostream>

using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _LastName;
	short _Age;
	char _Gender;

public:

	//default constructor
	clsPerson(string FirstName,
	string LastName,
	short Age,
	char Gender)
	{
		cout << "Hello, Im constructor.\n" << endl;

		_FirstName = FirstName;
		_LastName = LastName;
		_Age = Age;
		_Gender = Gender;
	}

	//copy constructor
	clsPerson(clsPerson & old_obj)
	{
		cout << "Hello, Im copy constructor.\n" << endl;

		_FirstName = old_obj._FirstName;
		_LastName = old_obj._LastName;
		_Age = old_obj._Age;
		_Gender = old_obj._Gender;
	}

	void SetFirstName(string FName)
	{
		_FirstName = FName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}

	void SetLastName(string LName)
	{
		_LastName = LName;
	}

	string GetLastName()
	{
		return _LastName;
	}

	void SetAge(short Age)
	{
		_Age = Age;
	}

	short GetAge()
	{
		return _Age;
	}

	void SetGender(char Gender)
	{
		_Gender = Gender;
	}

	short GetGender()
	{
		return _Gender;
	}

	void PrintPersonInfo()
	{
		cout << "Person Info: \n";
		cout << "---------------\n";
		cout << "Full Name: " << _FirstName << " " << _LastName << "\n";
		cout << "Age: " << _Age << "\n";
		cout << "Gender: " << _Gender << "\n";
		cout << "\n";
	}

	~clsPerson()
	{
		cout << "Hello, Im Destructor.\n" << endl;
	}
};

int main()
{
	clsPerson Person1("Ibrahim", "Mohamed", 27, 'M');

	Person1.PrintPersonInfo();

	clsPerson Person2 = Person1;

	Person2.PrintPersonInfo();


	system("pause>0");
	return 0;
}