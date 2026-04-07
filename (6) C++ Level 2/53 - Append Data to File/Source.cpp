#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream MyFile2;

	MyFile2.open("MyFile2.txt", ios::out | ios::app); // out -> open, app -> append

	MyFile2 << "This is a new line added to the file.\n";



	return 0;
}