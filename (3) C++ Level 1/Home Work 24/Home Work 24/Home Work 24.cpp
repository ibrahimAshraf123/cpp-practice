
#include <iostream>

using namespace std;

void MySumProcedure() {
	int Number1;
	int Number2;

	cout << "Please Enter Number1? \n";
	cin >> Number1;
	cout << "\n";

	cout << "Please Enter Number2? \n";
	cin >> Number2;
	cout << "\n";
	cout << "******************************\n";
	cout << Number1 + Number2 << endl;
}

int MySumFunction() {
	int Number1;
	int Number2;

	cout << "Please Enter Number1? \n";
	cin >> Number1;
	cout << "\n";

	cout << "Please Enter Number2? \n";
	cin >> Number2;
	cout << "\n";
	cout << "******************************\n";
	return Number1 + Number2;


}

int main()
{
	
	//MySumProcedure();
	cout << MySumFunction() << endl;



	return 0;
}
