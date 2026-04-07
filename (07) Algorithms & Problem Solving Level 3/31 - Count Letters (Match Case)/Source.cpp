#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
	string S;
	cout << "\nPlease enter your string?" << endl;
	getline(cin, S);
	return S;
}

char ReadChar()
{
	char C;
	cout << "\nPlease enter a character?" << endl;
	cin >> C;
	return C;
}

char InvertLetterCase(char C)
{
	return islower(C) ? toupper(C) : tolower(C);
}

short CountCharInString(string S, char C, bool MatchCase = true)
{
	short Counter = 0;
	for (short i = 0; i < S.length(); i++)
	{
		if (MatchCase)
		{
			if (S[i] == C)
			{
				Counter++;
			}
		}
		else
		{
			if (S[i] == C || S[i] == InvertLetterCase(C))
			{
				Counter++;
			}
		}
		
	}
	return Counter;
}

int main()
{
	string S1 = ReadString();
	char C1 = ReadChar();

	cout << "\nLetter '" << C1 << "' Count = " << CountCharInString(S1, C1);
	cout << "\nLetter '" << C1 << "' Or '" << InvertLetterCase(C1) << "' Count = " << CountCharInString(S1, C1, false);




	system("pause>0");

	return 0;
}