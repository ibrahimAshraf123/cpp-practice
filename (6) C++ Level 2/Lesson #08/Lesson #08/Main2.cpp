#include <iostream>
#include "MyLib.h"
#include "MyInputLib.h"

using namespace std;


int main()
{
	MyLib::My1stFunction();
	MyLib::My2ndFunction();
	MyLib::My3rdFunction();
	cout << endl;

	string Name = MyInputLib::ReadName();
	cout << "Your name is: " << Name << endl;

	int Num = MyInputLib::ReadNumber();
	cout << "Your Number is: " << Num << endl;

	return 0;
}