#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
	string S;
	cout << "Please enter your string? " << endl;
	getline(cin, S);
	return S;
}

short CountSmallLetters(string S1)
{
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

short CountCapitalLetters(string S1)
{
	short Counter = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

int main()
{
	string S1 = ReadString();

	cout << "\nString length = " << S1.length();
	cout << "\nCapital letters count = " << CountCapitalLetters(S1);
	cout << "\nSmall letters count = " << CountSmallLetters(S1);



	system("pause>0");
	return 0;
}