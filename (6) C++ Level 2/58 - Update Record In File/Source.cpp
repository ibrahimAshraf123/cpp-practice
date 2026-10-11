#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


void LoadFileContentToVector(string FileName, vector <string>& vFileContent)
{
	fstream MyFile;
	MyFile.open(FileName, ios::in); //read mode

	if (MyFile.is_open())
	{

		string Line;
		while (getline(MyFile, Line))
		{
			vFileContent.push_back(Line);
		}

		MyFile.close();
	}
}

void WriteVectorToFile(string FileName, vector <string>& vFileContent)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out); // write mode
	if (MyFile.is_open())
	{
		for (string Line : vFileContent)
		{
			if (Line != "")
			{
				MyFile << Line << endl;
			}
		}

		MyFile.close();
	}

}

void UpdateFileRecord(string FileName, string Record, string UpdateTo)
{
	vector <string> vFileContent;
	LoadFileContentToVector(FileName, vFileContent);

	for (string& Line : vFileContent)
	{
		if (Line == Record)
		{
			Line = UpdateTo;
		}
	}
	WriteVectorToFile(FileName, vFileContent);
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
	//update record in file
	cout << "File content before any update.\n";
	PrintFileContent("MyFile.txt");

	UpdateFileRecord("MyFile.txt", "Saeed", "Jamal");
	cout << "\nFile content after update.\n";
	PrintFileContent("MyFile.txt");


	return 0;
}