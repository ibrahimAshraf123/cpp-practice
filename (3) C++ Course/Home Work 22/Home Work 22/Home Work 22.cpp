#include <string>
#include <iostream>

using namespace std;

int main()
{
	string String1, String2, String3;
	cout << "Please enter String1? \n";
	getline(cin,String1);
	cout << "\n";

	cout << "Please enter String2? \n";
	getline(cin, String2);
	cout << "\n";

	cout << "Please enter String3? \n";
	getline(cin, String3);
	cout << "\n";

	cout << "****************** \n";
	cout << "The length of String 1 is: " << String1.length() << "\n";
	cout << "Characters at 0,2,4,7 are: " << String1[0] << " " << String1[2] << " " << String1[4] << " " << String1[7] << "\n";
	cout << "Concatenating String 2 and String 3 = " << String2 + String3 << "\n";

	int stringProd = stoi(String2) * stoi(String3);
	cout << String2 << " * " << String3 << " = " << stringProd << endl;

	return 0;
}
