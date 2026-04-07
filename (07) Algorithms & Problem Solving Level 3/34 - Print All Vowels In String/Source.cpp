#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

string ReadString()
{
	string S1;
	cout << "Please enter a string? " << endl;
	getline(cin, S1);
	return S1;
}

bool IsVowel(char C)
{
	C = tolower(C);
	return (C == 'u' || C == 'a' || C == 'e' || C == 'i' || C == 'o');
}

void PrintVowelsInString(string S)
{
	cout << "\nVowels in string are: ";

	for (short i = 0; i < S.length(); i++)
	{
		if (IsVowel(S[i]))
		{
			cout << S[i] << "    ";
		}
	}
}

int main()
{
	string S1 = ReadString();

	PrintVowelsInString(S1);

	system("pause>0");
}