//program to check if matrix is sparse
//sparse matrix has more 0 than numbers

#include <iostream>
#include <iomanip>

using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			cout << setw(3) << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

short CountNumberInMatrix(int Matrix[3][3], short Number, short Rows, short Cols)
{
	short Counter = 0;

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
				Counter++;
		}
	}

	return Counter;
}

bool IsSparseMatrix(int Matrix[3][3], short Rows, short Cols)
{
	short MatrixSize = Rows * Cols;

	return (CountNumberInMatrix(Matrix, 0, 3, 3) >= (MatrixSize / 2));

}

int main()
{
	int Matrix1[3][3] =
	{
		{0,0,12},
		{0,0,1},
		{0,0,9}
	};

	cout << "\nMatrix1:\n";
	PrintMatrix(Matrix1, 3, 3);

	cout << (IsSparseMatrix(Matrix1, 3, 3) ? "\nYes: It is Sparse\n" : "\nNo: It's NOT Sparse\n");





	system("pause>0");

	return 0;
}