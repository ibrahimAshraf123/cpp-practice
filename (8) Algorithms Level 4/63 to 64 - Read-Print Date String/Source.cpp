#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

vector<string> SplitString(string S1, string DeLim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; //define a string variable

	//use find() to get the position of the delimiters
	while ((pos = S1.find(DeLim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); //store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + DeLim.length());
	}

	if (S1 != "")
	{
		vString.push_back(S1); //adds last word of the string
	}

	return vString;
}

string DateToString(stDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

stDate StringToDate(string DateString)
{
	stDate Date;
	vector <string> vDate;

	vDate = SplitString(DateString, "/");
	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string ReadStringDate(string Message)
{
	string DateString;

	cout << Message;
	getline(cin >> ws, DateString);
	return DateString;
}


int main()
{
	string DateString = ReadStringDate("\nPlease Enter date? dd/mm/yyyy? ");

	stDate Date = StringToDate(DateString);

	cout << "\nDay: " << Date.Day << endl;
	cout << "Month: " << Date.Month << endl;
	cout << "Year: " << Date.Year << endl;

	cout << "\nYou Entered: " << DateToString(Date) << endl;

	system("pause>0");
	return 0;
}