#include <iostream>
using namespace std;

int main()
{
	int Arr[] = { 10,20,30,40,50 };
	int* Pntr;
	Pntr = Arr;

	cout << "Adresses: " << endl;

	for (int i = 0; i < 5; i++)
	{
		cout << "&Arr[" << i << "] = " << (Pntr + i) << endl;
	}
	cout << endl;

	/*cout << "&Arr[0] = " << Pntr << endl;
	cout << "&Arr[1] = " << Pntr + 1 << endl;
	cout << "&Arr[2] = " << Pntr + 2 << endl;
	cout << "&Arr[3] = " << Pntr + 3 << endl;
	cout << "&Arr[4] = " << Pntr + 4 << endl;
	cout << endl;*/

	cout << "Values: " << endl;

	for (int i=0; i<5; i++)
	{
		cout << "Arr[" << i << "] = " << *(Pntr + i) << endl;
	}
	cout << endl;

	/*cout << "Arr[0] = " << *Pntr << endl;
	cout << "Arr[1] = " << *(Pntr + 1) << endl;
	cout << "Arr[2] = " << *(Pntr + 2) << endl;
	cout << "Arr[3] = " << *(Pntr + 3) << endl;
	cout << "Arr[4] = " << *(Pntr + 4) << endl;
	cout << endl;*/




	return 0;
}