#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

// fill a 3x3 matrix with random numbers, print each Col Sum

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
			Matrix[i][j] = RandomNumber(1, 99);
		}
	}
}

void PrintMatrix(int Matrix[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int SumCol(int Matrix[3][3], int Rows, int ColNumber)
{
	int Sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		Sum += Matrix[i][ColNumber];
	}
	return Sum;
}

void PrintColSums(int Matrix[3][3], int Rows, int Cols)
{
	cout << "The following are the sum of each col in the matrix:" << endl;

	for (int j = 0; j < Cols; j++)
	{
		cout << "Col " << j + 1 << " Sum = " << SumCol(Matrix, Rows, j) << endl;
	}
}

int main()
{
	//seed random number generator in C++, only once
	srand((unsigned)time(NULL));

	int Matrix[3][3];
	FillMatrixWithRandomNumbers(Matrix, 3, 3);

	cout << "The following is a 3x3 random matrix:" << endl;
	PrintMatrix(Matrix, 3, 3);

	cout << endl;
	PrintColSums(Matrix, 3, 3);




	return 0;
}