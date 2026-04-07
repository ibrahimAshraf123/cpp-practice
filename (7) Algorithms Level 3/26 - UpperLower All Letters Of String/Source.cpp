#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
	string S1;
	cout << "Please enter your string?\n";
	getline(cin, S1);
	return S1;
}

string UpperAllLetters(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = toupper(S1[i]);
	}

	return S1;
}

string LowerAllLetters(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}

	return S1;
}

int main()
{
	string S1;

	S1 = ReadString();

	S1 = UpperAllLetters(S1);
	cout << "\nString after Upper: \n" << S1 << endl;

	S1 = LowerAllLetters(S1);
	cout << "\nString after Lower: \n" << S1 << endl;







	system("pause>0");
	return 0;
}