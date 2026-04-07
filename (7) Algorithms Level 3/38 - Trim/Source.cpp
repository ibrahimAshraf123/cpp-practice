#include <iostream>
#include <string>

using namespace std;

string TrimLeft(string S)
{
	
	for (short i = 0; i < S.length(); i++)
	{
		if (S[i] != ' ')
		{
			return S.substr(i, S.length() - i);
		}
	}

	return "";
}

string TrimRight(string S)
{
	for (short i = S.length(); i >= 0; i--)
	{
		if (S[i] != ' ')
		{
			return S.substr(0, i+1);
		}
	}

	return "";
}

string Trim(string S)
{
	
	return (TrimLeft(TrimRight(S)));
}

int main()
{
	string S1 = "           Ibrahim Ashraf Ibrahim             ";

	cout << "String = " << S1 << endl;
	cout << "Trim Left = " << TrimLeft(S1) << endl;
	cout << "Trim Right = " << TrimRight(S1) << endl;
	cout << "Trim = " << Trim(S1) << endl;





	system("pause>0");
}