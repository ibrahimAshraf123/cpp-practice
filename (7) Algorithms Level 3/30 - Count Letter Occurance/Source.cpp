#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
	string S;
	cout << "Enter a string: " << endl;
	getline(cin, S);
	return S;
}

char ReadChar()
{
	char C;
	cout << "Enter a character: " << endl;
	cin >> C;
	return C;
}

int CountCharInString(string S, char C)
{
	int Counter = 0;

	for (short i = 0; i < S.length(); i++)
	{
		if (S[i] == C)
		{
			Counter++;
		}
	}
	return Counter;
}

int main()
{
	string S1 = ReadString();
	char C1 = ReadChar();

	cout << "\nLetter '" << C1 << "' Count = " << CountCharInString(S1, C1) << endl;








	system("pause>0");
}