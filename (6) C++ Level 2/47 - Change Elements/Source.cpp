#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> Nums = { 1, 2, 3, 4, 5 };

	cout << "Initial elements: ";
	for (const int& i : Nums)
	{
		cout << i << " ";
	}
	cout << endl;

	cout << "Updated elements: ";
	for (int& i : Nums)
	{
		i = 20;
		cout << i << " ";
	}
	cout << endl;

	Nums.at(0) = 10;
	Nums.at(1) = 20;
	Nums[2] = 30;
	Nums[3] = 40;
	Nums[4] = 50;

	cout << "Updated elements: ";
	for (const int& i : Nums)
	{
		cout << i << " ";
	}
	cout << endl;


	return 0;
}