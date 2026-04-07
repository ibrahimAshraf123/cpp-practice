#include <iostream>
#include <iomanip>

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

int GetMatrixMin(int Matrix[3][3], short Rows, short Cols)
{
	int Min = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] < Min)
				Min = Matrix[i][j];
		}
	}
	return Min;
}

int GetMatrixMax(int Matrix[3][3], short Rows, short Cols)
{
	int Max = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] > Max)
				Max = Matrix[i][j];
		}
	}
	return Max;
}

int main()
{
	int Matrix[3][3] = { {10, 2, 3}, {4, 1, 6}, {7, 8, 9} };

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\nMinimum Number is: " << GetMatrixMin(Matrix, 3, 3) << endl;

	cout << "\nMaximum Number is: " << GetMatrixMax(Matrix, 3, 3) << endl;


	cin.get();
	return 0;
}