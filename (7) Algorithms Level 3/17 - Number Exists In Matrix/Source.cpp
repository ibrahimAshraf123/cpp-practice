#include <iostream>
#include<iomanip>

using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

bool NumberExistInMatrix(int Matrix[3][3], int Number, short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
				return true;
		}
	}
	return false;
}

int main()
{
	int Matrix1[3][3] = 
	{ 
		{1,2,3}, 
		{4,5,6}, 
		{7,8,9} 
	};

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	int Number;
	cout << "\nPlease enter the number to lokk for in matrix? " << endl;
	cin >> Number;

	if (NumberExistInMatrix(Matrix1, Number, 3, 3))
		cout << "\nYes it is there\n";
	else
		cout << "\nNo it is not there\n";


	cin.get();
	return 0;
}