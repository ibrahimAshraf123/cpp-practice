#include < iostream>
#include <random>
#include <iomanip>

using namespace std;

//fill a 3x3 matrix with random numbers, sum each row in seperate array and print results

int randomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void fillMatrixWithRandomNumbers(int Matrix[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Matrix[i][j] = randomNumber(1, 100);
		}
	}
}

void printMatrix(int Matrix[3][3], int Rows, int Cols)
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

int SumMatrixRow(int Matrix[3][3], int RowNumber, int Cols)
{
	int sum = 0;
	for (int j = 0; j < Cols; j++)
	{
		sum += Matrix[RowNumber][j];
	}
	return sum;
}

void SumMatrixRowsToArray(int Matrix[3][3], int Rows, int Cols, int RowSums[3])
{
	for (int i = 0; i < Rows; i++)
	{
		RowSums[i] = SumMatrixRow(Matrix, i, Cols);
	}
}

void printRowSums(int RowSums[3], int Rows)
{
	cout << "The following are the sum of each row in the matrix:" << endl;
	for (int i = 0; i < Rows; i++)
	{
		cout << "Row " << i + 1 << " Sum = " << RowSums[i] << endl;
	}
}

int main()
{
	//seed random number generator in C++, only once
	srand((unsigned)time(NULL));

	int Matrix[3][3];
	int RowSums[3];

	fillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "The following is a 3x3 random matrix:" << endl;
	printMatrix(Matrix, 3, 3);

	cout << endl;
	SumMatrixRowsToArray(Matrix, 3, 3, RowSums);
	printRowSums(RowSums, 3);



	return 0;
}