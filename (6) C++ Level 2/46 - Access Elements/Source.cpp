#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> Nums = { 1, 2, 3, 4, 5 };

	//using .at() to access elements
	cout << "Num at index 0: " << Nums.at(0) << endl;
	cout << "Num at index 2: " << Nums.at(2) << endl;
	cout << "Num at index 4: " << Nums.at(4) << endl;
	cout << endl;

	//using [] to access elements
	cout << "Num at index 0: " << Nums[0] << endl;
	cout << "Num at index 2: " << Nums[2] << endl;
	cout << "Num at index 4: " << Nums[4] << endl;
	cout << endl;










	return 0;
}