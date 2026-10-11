#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void SaveVectorToFile(string FileName, vector <string> vData)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); //write mode

	if (MyFile.is_open())
	{
		MyFile << "Names List: " << endl;

		for (string& Line : vData)
		{
			if(Line != "")
			{
				MyFile << Line << endl;
			}
		}


		MyFile.close();
	}
}

int main()
{

	vector <string> vData = { "Ibrahim", "Ali", "Ahmed", "Omar" };

	SaveVectorToFile("Names.txt", vData);

	return 0;
}