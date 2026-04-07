#include <iostream>
#include <iomanip>

using namespace std;

void FillMatrixWithOrderedNumbers(int Matrix[3][3], int Rows, int Cols)
{
	short Counter = 0;
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
			cout << setw(3) << Matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	int Matrix[3][3];
	FillMatrixWithOrderedNumbers(Matrix, 3, 3);

	cout << "The following is a 3x3 ordered matrix:" << endl;
	PrintMatrix(Matrix, 3, 3);










	return 0;
}