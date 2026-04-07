#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadString()
{
	string S;
	cout << "Please Enter Your String?" << endl;
	getline(cin, S);
	return S;
}

vector<string> SplitString(string S1, string deLim)
{
	vector<string> result;
	short pos = 0;
	string token;

	while ((pos = S1.find(deLim)) != std::string::npos)
	{
		token = S1.substr(0, pos);
		if (token != "")
		{
			result.push_back(token);
		}
		
		S1.erase(0, pos + deLim.length());
	}

	if(S1 != "")
	{
		result.push_back(S1);
	}

	return result;
}

int main()
{
	vector<string> vString;

	
	vString = SplitString(ReadString(), " ");

	cout << endl;
	cout << "Tokens = " << vString.size() << endl;

	for (string& str : vString)
	{
		cout << str << endl;
	}





	system("pause>0");
}