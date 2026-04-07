#include <iostream>
#include <string>
#include <vector>

using namespace std;

string JoinString(vector<string> vString, string Delim)
{
	string S1 = "";

	for (string& S : vString)
	{
		S1 += S + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

string JoinString(string arrString[], short StringLength, string Delim)
{
	string S1 = "";

	for (short i=0; i <StringLength; i++)
	{
		S1 += arrString[i] + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

int main()
{
	vector<string> vFruits = { "Apple", "Banana", "Cherry", "Date", "Elderberry" };
	string arrFruits[] = {"Apple", "Banana", "Cherry", "Date", "Elderberry"};

	cout << "\nVector after join: " << endl;
	cout << JoinString(vFruits, "///") << endl;

	cout << "\n\nArray after join: " << endl;
	cout << JoinString(arrFruits, arrFruits->length(), "///") << endl;







	system("pause>0");
}