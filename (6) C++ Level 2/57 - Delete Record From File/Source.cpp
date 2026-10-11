#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void LoadFileDataToVector(string FileName, vector<string>& vData)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in);//readMode

	if (MyFile.is_open())
	{
		string Line;
		while (getline(MyFile, Line))
		{
			vData.push_back(Line);
		}

		MyFile.close();
	}

}

void SaveVectorDataToFile(string FileName, vector<string> vData)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); //write mode

	if (MyFile.is_open())
	{
		for (string& Line : vData)
		{
			if (Line != "")
			{
				MyFile << Line << endl;
			}

		}

		MyFile.close();

	}

}

void DeleteRecordFromFile(string FileName, string Record)
{
	vector<string> vData;
	LoadFileDataToVector(FileName, vData);

	for (string& Line : vData)
	{
		if (Line == Record)
		{
			Line = ""; //mark for deletion
		}
	}
	SaveVectorDataToFile(FileName, vData);

}

void PrintFileContent(string FileName)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in); //read mode

	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile, Line))
		{
			cout << Line << endl;
		}

		MyFile.close();
	}
}

int main()
{
	
	cout << "File data before record deletion.\n";
	PrintFileContent("Data.txt");

	cout << "\n\nFile data after record deletion.\n";
	DeleteRecordFromFile("Data.txt", "Ali");
	PrintFileContent("Data.txt");

	return 0;
}