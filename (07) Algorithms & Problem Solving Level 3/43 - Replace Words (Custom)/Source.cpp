#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vStringWords;
	size_t pos = 0;
	
	while ((pos = S1.find(Delim)) != string::npos)
	{
		vStringWords.push_back(S1.substr(0, pos));
		S1.erase(0, pos + Delim.length());
	}

	if (!S1.empty())
	{
		vStringWords.push_back(S1); // Add the last word
	}

	return vStringWords;
}

string LowerAllString(string S1)
{
	for (char& c : S1)
	{
		c = tolower(c);
	}

	return S1;
}

string JoinString(vector<string> vString, string Delim)
{
	string Result = "";

	for (size_t i = 0; i < vString.size(); i++)
	{
		Result += vString[i];

		if (i != vString.size() - 1)
		{
			Result += Delim;
		}
	}

	return Result;
}

string ReplaceWordsInStringUsingSplit(string S1, string StringToReplace, string sReplaceWith, bool MatchCase = true)
{
	vector<string> vStringWords = SplitString(S1, " ");

	for (string& s : vStringWords)
	{
		if (MatchCase)
		{
			if (s == StringToReplace)
			{
				s = sReplaceWith;
			}
		}

		else
		{
			if (LowerAllString(s) == LowerAllString(StringToReplace))
			{
				s = sReplaceWith;
			}
		}

	}

	return JoinString(vStringWords, " ");

}

int main()
{
	string S1 = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "jordan";
	string sReplaceWith = "Canada";

	cout << "\nOriginal String: \n" << S1;
	cout << "\n\nReplace with match case: \n" << ReplaceWordsInStringUsingSplit(S1, StringToReplace, sReplaceWith);
	cout << "\n\nReplace without match case: \n" << ReplaceWordsInStringUsingSplit(S1, StringToReplace, sReplaceWith, false);



	system("pause>0");
}