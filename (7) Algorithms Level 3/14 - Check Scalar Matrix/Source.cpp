//rogram to check if matrix is scalar or not
//Scalar Matrix =  all main diagonal elements are equal, and all off-diagonal elements are zero.

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

bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && Matrix[i][j] != Matrix[0][0])
				return false;
			else if (i != j && Matrix[i][j] != 0)
				return false;
		}
	}
	return true;
}

int main()
{
	int MatrixA[3][3] = 
	{
		{5,0,0},
		{0,5,0},
		{0,0,5}
	};

	cout << "\nMatrix A is: \n";
	PrintMatrix(MatrixA, 3, 3);
	cout << endl;

	if (IsScalarMatrix(MatrixA, 3,3))
		cout << "YES: is a Scalar Matrix.\n";
	else
		cout << "No: NOT a Scalar Matrix.\n";


	cin.get();
	return 0;
}