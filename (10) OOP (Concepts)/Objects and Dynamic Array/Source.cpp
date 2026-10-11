#include<iostream>
#include<vector>
#include "clsA.h";

using namespace std;

int main()

{
	short NumberOfObjects = 5;

	// allocating dynamic array
   // of Size NumberOfObjects using new keyword

	clsA* arrA = new clsA[NumberOfObjects];

	// calling constructor
	// for each index of array
	for (int i = 0; i < NumberOfObjects; i++) {
		arrA[i] = clsA(i);
	}

	// printing contents of array
	for (int i = 0; i < NumberOfObjects; i++) {
		arrA[i].Print();
	}

	return 0;


	system("pause>0");

}

