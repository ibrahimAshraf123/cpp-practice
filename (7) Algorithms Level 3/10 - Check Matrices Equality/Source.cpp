#include <iostream>
#include <iomanip>
#include <random>

using namespace std;

//program to check equality of sum of elements in 2 matrices

int Random(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrix(int Matrix[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Matrix[i][j] = Random(1, 10);
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

int SumOfMatrix(int Matrix[3][3], int Rows, int Cols)
{
	int Sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Sum += Matrix[i][j];
		}
	}
	return Sum;
}

bool CheckMatricesEquality(int Matrix1[3][3], int Matrix2[3][3])
{
	return (SumOfMatrix(Matrix1, 3, 3) == SumOfMatrix(Matrix2, 3, 3));
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	FillMatrix(Matrix1, 3, 3);
	FillMatrix(Matrix2, 3, 3);

	cout << "\nMatrix 1: \n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nMatrix 2: \n";
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nSum 1 = " << SumOfMatrix(Matrix1, 3, 3);
	cout << "\nSum 2 = " << SumOfMatrix(Matrix2, 3, 3);

	cout << "\n" << (CheckMatricesEquality(Matrix1, Matrix2) ? "\nYes: matrices are equal.\n" : "\nNo: matrices are NOT equal.\n");

	

	system("pause>0");


	return 0;
}