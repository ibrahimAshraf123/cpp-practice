#include <iostream>
using namespace std;

int main()
{

	void* Ptr;

	float F1 = 10.5;

	Ptr = &F1;

	cout << "Value of F1: " << *(static_cast<float*>(Ptr)) << endl;
	cout << "Value of F1: " << *(float*)Ptr << endl;

	int x = 500;

	Ptr = &x;

	cout << "Value of x: " << *(static_cast<int*>(Ptr)) << endl;
	cout << "Value of x: " << *(int*)Ptr << endl;








	return 0;
}