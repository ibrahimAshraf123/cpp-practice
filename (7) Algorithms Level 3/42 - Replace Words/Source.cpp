#include <iostream>
#include <vector>
#include <string>

using namespace std;

string ReplaceWordsInString_BuiltInFunction(string S1, string StringToReplace, string sReplaceTo)
{ 
	short pos = S1.find(StringToReplace);

	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
		pos = S1.find(StringToReplace); //find next
	}

	return S1;
}

int main()
{
	string S1 = "Welcome to UAE, UAE is a nice country";
	string StringToReplace = "UAE";
	string sReplaceTo = "Jordan";

	cout << "\n\nOriginal String: \n" << S1;
	cout << "\n\nString After Replacement: ";
	cout << "\n" << ReplaceWordsInString_BuiltInFunction(S1, StringToReplace, sReplaceTo);

	system("pause>0");
}