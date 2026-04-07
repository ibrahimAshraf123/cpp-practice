#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> vNumbers;

	vNumbers.push_back(10);
	vNumbers.push_back(20);
	vNumbers.push_back(30);
	

	vNumbers.pop_back();

	cout << "First element = " << vNumbers.front() << endl;
	cout << "Last element = " << vNumbers.back() << endl;

	cout << "Size = " << vNumbers.size() << endl;
	cout << "Capacity = " << vNumbers.capacity() << endl;

	cout << "Empty? " << (vNumbers.empty() ? "Yes" : "No" )<< endl;


	return 0;
}