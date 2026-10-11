#include <iostream>

using namespace std;

class clsPerson
{
private:
	struct _stAdress
	{
		string _AddressLine1;
		string _AddressLine2;
		string _City;
		string _Country;
	};

public:
	string FullName;
	_stAdress Address;

	clsPerson()
	{
		FullName = "Mahmoud Shareef";
		Address._AddressLine1 = "Al Falafel";
		Address._AddressLine2 = "Villa 41";
		Address._City = "Alwidad";
		Address._Country = "Iraq";
	};

	void PrintAddress()
	{
		cout << "\nAddress:\n";
		cout << "Address Line 1: " << Address._AddressLine1 << endl;
		cout << "Address Line 2: " << Address._AddressLine2 << endl;
		cout << "City: " << Address._City << endl;
		cout << "Country: " << Address._Country << endl;
	};
};

int main()
{
	clsPerson Person1;

	cout << Person1.FullName << endl;
	cout << endl;
	Person1.PrintAddress();

	system("pause>0");
	return 0;
}