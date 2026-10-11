#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string str;
	cout << "Enter a string: ";
	getline(cin, str);
	return str;
}

string UpperFirstLetterOfEachWord(string str)
{
	bool isFirstLetter = true;

	for (short i=0; i < str.length(); i++)
	{
		if (str[i] != ' ' && isFirstLetter)
		{
			str[i] = toupper(str[i]);
		}

		isFirstLetter = (str[i] == ' ' ? true : false);
	}

	return str;
}

int main()
{
	string str = ReadString();

	str = UpperFirstLetterOfEachWord(str);

	cout << str << endl;





	system("pause>0");

	return 0;
}