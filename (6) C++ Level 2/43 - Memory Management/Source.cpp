#include <iostream>
using namespace std;

int main() {

	int* pX;
	float* pY;

	pX = new int;
	pY = new float;

	*pX = 10;
	*pY = 3.14f;

	cout << *pX << endl;
	cout << *pY << endl;

	delete pX;
	delete pY;





	return 0;
}