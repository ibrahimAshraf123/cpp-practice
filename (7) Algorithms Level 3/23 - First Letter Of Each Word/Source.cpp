#include <iostream>
#include <string>

using namespace std;

//program to read a string and print 1st letter of each word in that string

string ReadString()
{
	string String;
	cout << "Please enter your string? \n";
	getline(cin, String);
	return String;

}

void PrintFirstLetters(string String)
{
	cout << "The First Letters of this string: \n";
	cout << String[0] << endl;

	for (int i = 0; i < String.length(); i++)
	{
		if (String[i] == ' ')
		{
			cout << String[i+1] << endl;
		}
	}
}

int main()
{

	PrintFirstLetters(ReadString());





	system("pause>0");

	return 0;
}