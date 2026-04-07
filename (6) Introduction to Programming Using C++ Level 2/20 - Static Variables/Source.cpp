#include <iostream>
using namespace std;

void Function()
{
	static int Number = 1;
	cout << "Result = " << Number << "\n";
	Number++;
}

int main()
{
	Function();
	Function();
	Function();



}