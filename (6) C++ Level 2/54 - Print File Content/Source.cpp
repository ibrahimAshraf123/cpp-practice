#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void PrintFileContents(string FileName)
{
	fstream File;
	File.open(FileName, ios::in);

	if (File.is_open())
	{
		string Line;
		
		while (getline(File, Line))
		{
			cout << Line << endl;
		}
		File.close();
	}

}


int main()
{
	PrintFileContents("C:\\Users\\ibrah\\OneDrive\\Desktop\\PROGRAMMING\\Programming Advices RoadMap\\C++ Journal.txt");


	return 0;
}