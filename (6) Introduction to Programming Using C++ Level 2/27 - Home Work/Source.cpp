#include <iostream>
using namespace std;

int main()
{
	//int x [rows][columns]
	int MultTable[10][10];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			MultTable[i][j] = (i+1) * (j+1);
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%0*d ", 2, MultTable[i][j]);
		}
		cout << endl;
	}
	

	return 0;
}