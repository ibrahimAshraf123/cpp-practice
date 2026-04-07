#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
	string S;
	cout << "Please enter a string?" << endl;
	getline(cin, S);
	return S;
}

bool IsVowel(char C)
{
	C = tolower(C);
	return (C == 'u' || C == 'a' || C == 'e' || C == 'i' || C == 'o');
}

short CountVowels(string S1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
		{
			Counter++;
		}
	}
	return Counter++;
}

int main()
{
	string S1 = ReadString();

	cout << "\nNumber of vowels is: " << CountVowels(S1) << endl;


	system("pause>0");

}