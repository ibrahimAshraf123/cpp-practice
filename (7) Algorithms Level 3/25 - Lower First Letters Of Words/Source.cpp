#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString()
{
	string S1;
	cout << "Please Enter Your String? \n";
	getline(cin, S1);
	return S1;
}

string LowerFirstLettersOfEachWord(string S1)
{
	bool isFirstLetter = true;

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			S1[i] = tolower(S1[i]);
		}

		isFirstLetter = (S1[i] == ' ' ? true : false);
	}
	return S1;
}

int main()
{
	string S1;

	S1 = ReadString();
	S1 = LowerFirstLettersOfEachWord(S1);

	cout << "String after conversion: \n";
	cout << S1 << endl;
	




	system("pause>0");
	return 0;
}