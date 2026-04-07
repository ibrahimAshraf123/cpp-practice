#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

//a program to fill a 3x3 matrix with random numbers from 0 to 100 and print it to the console

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void fillMatrixWithRandomNumber(int Matrix[3][3], short Rows, short Cols)
{
	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Matrix[i][j] = RandomNumber(0, 100);
		}
	}
}

void printMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << setw(3) << Matrix[i][j] << "\t";
		}
		cout << "\n";
	}
}

int main()
{
	//seed the random number generator, called only once
	srand((unsigned)time(NULL));

	int Matrix[3][3];

	fillMatrixWithRandomNumber(Matrix,3,3);
	cout << "The following is a 3x3 random matrix: " << endl;
	printMatrix(Matrix,3,3);




	return 0;
}