#include <iostream>
#include <iomanip>

using namespace std;

void FillMatrixWithOrderedNumbers(int Matrix[3][3], int Rows, int Cols)
{
	int Counter = 0;
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Counter++;
			Matrix[i][j] = Counter;
		}
	}
}

void PrintMatrix(int Matrix[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(4) << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void TransposeMatrix(int Matrix[3][3], int Rows, int Cols, int TransposedMatrix[3][3])
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			TransposedMatrix[i][j] = Matrix[j][i];
		}
	}

}

int main()
{
	int Matrix[3][3];
	int TransposedMatrix[3][3];

	FillMatrixWithOrderedNumbers(Matrix, 3, 3);

	cout << "The following is a 3x3 ordered matrix:" << endl;
	PrintMatrix(Matrix, 3, 3);
	cout << endl;

	TransposeMatrix(Matrix, 3, 3, TransposedMatrix);
	cout << "The following is the transposed matrix:" << endl;
	PrintMatrix(TransposedMatrix, 3, 3);

	return 0;
}