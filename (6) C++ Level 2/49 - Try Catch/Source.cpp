#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> Nums = { 1, 2, 3, 4, 5 };

	try 
	{
		cout << Nums.at(6) << endl;
	}
	catch (...)
	{
		cout << "Vector element Out of bounds" << endl;
	}

	cout << "Hello World!" << endl;




	return 0;
}