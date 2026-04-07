#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void LoadFileDataToVector(string FileName, vector <string> & vFileData)
{
	fstream MyFile;

	MyFile.open("MyFile.txt", ios::in); //read mode

	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile, Line))
		{
			vFileData.push_back(Line);
		}

		MyFile.close();
	}

}

int main()
{
	vector <string> vFileData;

	LoadFileDataToVector("MyFile.txt", vFileData);

	for (string &Line : vFileData)
	{
		cout << Line << endl;
	}


	return 0;
}