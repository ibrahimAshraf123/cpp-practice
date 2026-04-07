#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

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
}
void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols)
{
	short MiddleRow = Rows / 2;
	for (short j = 0; j < Cols; j++)
	{
		printf(" %0*d ", 2, arr[MiddleRow][j]);
	}
	cout << "\n";
}
void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols)
{
	short MiddleCol = Cols / 2;
	for (short j = 0; j < Rows; j++)
	{
		printf(" %0*d ", 2, arr[j][MiddleCol]);
	}
	cout << "\n";
}

int main()
{
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrixWithRandomNumbers(Matrix, 3, 3);
	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\nMiddle Row of Matrix1 is:\n";
	PrintMiddleRowOfMatrix(Matrix, 3, 3);

	cout << "\nMiddle Col of Matrix1 is:\n";
	PrintMiddleColOfMatrix(Matrix, 3, 3);


	return 0;
}