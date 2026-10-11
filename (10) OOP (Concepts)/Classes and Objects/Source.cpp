#include <iostream>

using namespace std;

class clsPerson
{
	int x;

	public:
		string FirstName;
		string LastName;

		string FullName()
		{
			return FirstName + " " + LastName;
		}

};

int main()
{

	clsPerson Person1;

	Person1.FirstName = "Ibrahim";
	Person1.LastName = "Mohamed";

	cout << Person1.FullName() << endl;

	return 0;
}