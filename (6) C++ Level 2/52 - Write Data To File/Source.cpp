#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream MyFile;

	MyFile.open("MyFile.txt", ios::out); //ios::out -> write mode

	MyFile << "This is the 1st line, Ibrahim \n";
	MyFile << "This is the 2nd line, Is The \n";
	MyFile << "This is the 3rd line, Best Game Developer WORLDWIDE \n";

	MyFile.close();



	return 0;
}