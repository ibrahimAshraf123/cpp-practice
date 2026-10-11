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

	//declaration specification class: property
	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

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

	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	//property get
	string GetFullName()
	{
		return _FirstName + " " + _LastName;
	}
};


int main()
{
	clsPerson Person1;

	Person1.FirstName = "Ibrahim";
	Person1.LastName = "Mohamed";

	cout << "First Name: " << Person1.FirstName << endl;
	cout << "Last Name: " << Person1.LastName << endl;
	cout << "Full Name: " << Person1.GetFullName() << endl;



	return 0;
}