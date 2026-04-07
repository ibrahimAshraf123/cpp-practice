#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

//write a program to fill 3x3 matrix with random numbers, then print each row sum


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
			Matrix[i][j] = randomNumber(1, 10);
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

int getRowSum(int Matrix[3][3], int RowIndex, int Cols)
{
	int sum = 0;
	for (int j = 0; j < Cols; j++)
	{
		sum += Matrix[RowIndex][j];
	}
	return sum;
}

void printRowSums(int Matrix[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		int sum = getRowSum(Matrix, i, Cols);
		cout << "Row " << i+1 << " Sum = " << sum << endl;
	}
}

int main()
{
	//seed the random number generator, only once
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	fillMatrixWithRandomNumbers(Matrix, 3, 3);

	cout << "The following is a 3x3 random matrix: " << endl;
	printMatrix(Matrix, 3, 3);
	cout << endl;

	cout << "The following are the sum of each row in the matrix: " << endl;
	printRowSums(Matrix, 3, 3);

	return 0;
}