#include <iostream>
#include <string>
#include <vector>

using namespace std;

string JoinString(vector<string> vString, string Delim)
{
	string result = "";

	for (string& S : vString)
	{
			result += S + Delim;	
	}

	return result.substr(0,result.length() - Delim.length());
}

int main()
{
	vector<string> vFruits = { "Apple", "Banana", "Cherry", "Date", "Elderberry" };

	cout << "Vector after join: " << endl;
	cout << JoinString(vFruits, "///") << endl;







	system("pause>0");
}