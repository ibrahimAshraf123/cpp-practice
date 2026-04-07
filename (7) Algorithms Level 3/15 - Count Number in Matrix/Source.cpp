#include <iostream>
#include <iomanip>

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

int CountNumberInMatrix(int Matrix[3][3], short Number, short Rows, short Cols)
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

int main()
{
	int Matrix1[3][3] =
	{
		{9,1,12},
		{0,9,1},
		{0,9,9}
	};

	cout << "Matrix 1:" << endl;
	PrintMatrix(Matrix1, 3, 3);

	short Number;
	cout << "\nEnter the number to count in matrix? ";
	cin >> Number;

	cout << "\nNumber " << Number << " count in matrix is " << CountNumberInMatrix(Matrix1, Number, 3, 3) << endl;






	cin.get();
	return 0;
}