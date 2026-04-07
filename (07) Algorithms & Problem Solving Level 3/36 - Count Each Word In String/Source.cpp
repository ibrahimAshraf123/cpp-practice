#include <iostream>
#include <string>

using namespace std;

string ReadString()
{
	string S1;
	cout << "please enter your string?" << endl;
	getline(cin, S1);
	return S1;
}

int CountEachWordInString(string S1)
{

	string deLim = " ";
	int Counter = 0;
	short pos = 0;
	string sWord;

	while ((pos = S1.find(deLim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			Counter++;
		}
		S1.erase(0, pos + deLim.length());
	}

	if (S1 != "")
	{
		Counter++;
	}

	return Counter;
}

int main()
{
	string S1 = ReadString();
	cout << CountEachWordInString(S1);



	return 0;
}