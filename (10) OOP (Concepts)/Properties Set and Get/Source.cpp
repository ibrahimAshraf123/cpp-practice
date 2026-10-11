#include <iostream>

using namespace std;

class clsPerson
{
private:
	string _FirstName;
	string _LastName;


public:

	//property set
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	//property get
	string GetFirstName()
	{
		return _FirstName;
	}

	//property set
	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	//property get
	string GetLastName()
	{
		return _LastName;
	}

	//property get
	string GetFullName()
	{
		return _FirstName + " " + _LastName;
	}
};


int main()
{
	clsPerson Person1;

	Person1.SetFirstName("Ibrahim");
	Person1.SetLastName("Mohamed");

	cout << "First Name: " << Person1.GetFirstName() << endl;
	cout << "Last Name: " << Person1.GetLastName() << endl;
	cout << "Full Name: " << Person1.GetFullName() << endl;



	return 0;
}