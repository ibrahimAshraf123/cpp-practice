//program to check if matrices are Identical (have same values) or not

#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

int RandomNum(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrix(int Matrix[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Matrix[i][j] = RandomNum(1, 10);
		}
	}
}

void PrintMatrix(int Matrix[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf(" %0*d ", 2, Matrix[i][j]);
		}
		cout << endl;
	}
}

bool AreMatricesIdentical(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
				return false;
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillMatrix(Matrix1, 3, 3);
	FillMatrix(Matrix2, 3, 3);

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	cout << endl;

	cout << (AreMatricesIdentical(Matrix1, Matrix2, 3, 3) ? "YES: matrices are Identical" : "No: matrices are NOT Identical") << endl;

	cin.get();


	return 0;
}