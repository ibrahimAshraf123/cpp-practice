#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> Nums = { 1, 2, 3, 4, 5 };

	//create an iterator for the vector
	vector<int>::iterator itr;

	//using the iterator to traverse the vector
	for (itr = Nums.begin(); itr != Nums.end(); itr++)
	{
		cout << *itr << " ";
	}
	cout << endl;



	return 0;
}