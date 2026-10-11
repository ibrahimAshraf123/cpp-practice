#include<iostream>
#include<vector>
#include "clsA.h";

using namespace std;

int main()

{

	// Initializing 3 array Objects with function calls of
	// parameterized constructor as elements of that array
	clsA obj[] = { clsA(10), clsA(20), clsA(30) };

	// using print method for each of three elements.
	for (int i = 0; i < 3; i++) {
		obj[i].Print();
	}

	return 0;


	system("pause>0");

}

