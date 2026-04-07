
#include <iostream>
#include <iomanip>

using namespace std;

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

bool IsIdentityMatrix(int Matrix[3][3], int Rows, int Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (i == j && Matrix[i][j] != 1)
					return false;
		
			else if (i !=j && Matrix[i][j] != 0)
					return false;

		}
	}

	return true;
}

int main()
{
	int Matrix1[3][3] =
	{
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};

	cout << "Matrix1:\n";
	PrintMatrix(Matrix1, 3, 3);


	cout << "\n" << (IsIdentityMatrix(Matrix1, 3, 3) ? "YES: It is an identity matrix.\n" : "NO: It is not an identity matrix.\n");


	cin.get();

	return 0;
}