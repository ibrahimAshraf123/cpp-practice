#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

//store result of multiplying random Matrices values in ResultMatrix

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Matrix[i][j] = RandomNumber(1, 10);
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
			//cout << setw(3) << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void ProductOfMatrices(int Matrix1[3][3], int Matrix2[3][3], int ResultMatrix[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			ResultMatrix[i][j] = Matrix1[i][j] * Matrix1[i][j];
		}
	}
}

int main()
{
	//seeds the random number generator in C++, only once
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3], ResultMatrix[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);
	FillMatrixWithRandomNumbers(Matrix2, 3, 3);

	cout << "Matrix1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	cout << "Matrix2:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	ProductOfMatrices(Matrix1, Matrix2, ResultMatrix, 3, 3);
	cout << "Results:" << endl;
	PrintMatrix(ResultMatrix, 3, 3);

	return 0;
}