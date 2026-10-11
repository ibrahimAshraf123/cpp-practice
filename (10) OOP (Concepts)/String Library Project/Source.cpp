#include <iostream>
#include <vector>
#include "clsString.h";

using namespace std;

int main()
{
	
	clsString String1;

	String1.SetValue("ibrahim ashraf");
	
	
	String1.UpperAllLetters();

	cout << String1.Value << endl;

	system("pause>0");
	return 0;
}