#include <iostream>
#include <cctype>
using namespace std;

int main()
{

	char x;
	char w;

	x = toupper('a');
	w = tolower('A');

	cout << "converting a to A " << x << endl;
	cout << "converting A to a " << w << endl;

	//return zero if false, and number if true
	cout << "is uppercase A? " << (isupper('A')? "Yes" : "No") << endl;

	cout << "is lowercase a? " << (islower('a') ? "Yes" : "No") << endl;

	cout << "is 5 a digit? " << (isdigit('5') ? "Yes" : "No") << endl;

	//punctuation characters: . , ! ? ; : ' " etc
	cout << "is $ punctuation ? " << (ispunct('$') ? "Yes" : "No") << endl;
	



	return 0;
}