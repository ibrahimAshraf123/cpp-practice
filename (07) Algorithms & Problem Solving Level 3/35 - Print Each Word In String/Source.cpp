#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string S;
	cout << "Please enter a string? " << endl;
	getline(cin, S);
	return S;
}

void PrintEachWordInString(string S1)
{

	string deLim = " ";

	cout << "\nYour string words are: \n\n";
	short pos = 0;
	string sWord;

	while ((pos = S1.find(deLim)) != string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			cout << sWord << endl;
		}
		S1.erase(0, pos + deLim.length());
	}

	if (S1 != "")
	{
		cout << S1 << endl;
	}
}

int main()
{

	PrintEachWordInString(ReadString());



	system("pause>0");
}