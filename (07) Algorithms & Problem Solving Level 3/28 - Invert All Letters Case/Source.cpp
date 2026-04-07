#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
	string S1;
	cout << "Please enter your string?" << endl;
	getline(cin, S1);
	return S1;
}

char InvertLetterCase(char C1)
{
	return isupper(C1) ? tolower(C1) : toupper(C1);
}

string InvertAllLetters(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
        S1[i] = InvertLetterCase(S1[i]);
	}

	return S1;
}

int main()
{

	string S1 = ReadString();

	cout << "\nString after inverting ALL letters case: \n";
	cout << InvertAllLetters(S1) << endl;







	system("pause>0");

	return 0;
}