#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

// fill a 3x3 matrix with random numbers, sum each Col in another array and print them

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void FillMatrixWithRandomNumbers(int Matrix[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for(int j = 0; j < Cols; j++)
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

int ColumnSum(int Matrix[3][3], int Rows, int ColNumber)
{
	int ColSum = 0;
	for (int i = 0; i < Rows; i++)
	{
		ColSum += Matrix[i][ColNumber];
	}
	return ColSum;
}

void ColSumsInArray(int Matrix[3][3], int Rows, int Cols, int ArrColSums[3])
{
	for (int j = 0; j < Cols; j++)
	{
		ArrColSums[j] = ColumnSum(Matrix, Rows, j);
	}
}

void PrintColSums(int arrColSums[3], int Cols)
{
	cout << "The following are the sum of each col in the matrix:" << endl;
	for (int i = 0; i < Cols; i++)
	{
		cout << "Col " << i + 1 << " Sum = " << arrColSums[i] << endl;
	}
}

int main()
{
	//seeds the random number generator in C++, only once
	srand((unsigned)time(NULL));

	int Matrix[3][3];
	int arrColSums[3] = { 0,0,0 };

	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "The following is a 3x3 random matrix:" << endl;
	PrintMatrix(Matrix, 3, 3);
	cout << endl;

	ColSumsInArray(Matrix, 3, 3, arrColSums);
	PrintColSums(arrColSums, 3);

	return 0;
}