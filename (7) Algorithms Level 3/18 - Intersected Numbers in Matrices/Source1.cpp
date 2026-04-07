#include <iostream>
#include <iomanip>

// program to print intersected numbers in matrices

using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for(short j = 0; j < Cols; j++)
		{ 
			cout << setw(3) << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

bool NumberExistsInMatrix(int Number, int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
				return true;
		}
	}
	return false;
}

void PrintIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	int Number;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Number = Matrix1[i][j];
		
			if (NumberExistsInMatrix(Number, Matrix2, Rows, Cols))
				cout << Number << "\t";
		}
	}
}

int main()
{
	int Matrix1[3][3] =		{{1,2, 3},{4, 5, 6},{7, 8, 9}};
	int Matrix2[3][3] =		{{5, 6, 7},{8, 9, 10},{ 11, 12, 13 }};

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);
	cout << "\nMatrix2:\n";
	PrintMatrix(Matrix2, 3, 3);

	cout << "\nIntersected Numbers are: \n";
	PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3);

	cin.get();
	return 0;
}