#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

int RandomNumber(short From, short To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrixRandomly(int Matrix[3][3], int Rows, int Cols)
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

int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	FillMatrixRandomly(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << "\nSum of Matrix1 is: " << SumOfMatrix(Matrix1, 3, 3) << endl;
	


	system("pause>0");


	return 0;
}
