#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char ReadChar()
{
	char C;
	cout << "please enter a character? " << endl;
	cin >> C;
	return C;
}

bool IsVowel(char C)
{
	C = tolower(C);
	return (C == 'u' || C == 'a' || C == 'e' || C == 'i' || C == 'o');
}

int main()
{
	char C1 = ReadChar();

	cout << (IsVowel(C1) ? "YES a vowel" : "NO not a vowel") << endl;










	system("pause>0");

	return 0;
}