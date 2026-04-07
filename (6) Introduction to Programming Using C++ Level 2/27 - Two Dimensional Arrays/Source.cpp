#include <iostream>;
#include <iomanip>;
using namespace std;

int main()
{

	//int ArrX [rows] [columns]
	int Array1[3][3] =
	{
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << Array1[i][j] << " ";
		}
		cout << endl;
	}


	return 0;
}