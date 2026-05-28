#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct stDate
{
	short Day;
	short Month;
	short Year;
};

vector<string> SplitString(string S1, string Delim)
{
	vector<string> result;
	short pos = 0;
	string sWord;

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);
		if (sWord != "")
		{
			result.push_back(sWord);
		}

		S1.erase(0, pos + Delim.length());
	}

	if (S1 != "")
	{
		result.push_back(S1);
	}

	return result;
}

string ReplaceWordsInString(string S1, string StringToReplace, string sReplaceTo)
{
	short pos = S1.find(StringToReplace);

	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), sReplaceTo);
		pos = S1.find(StringToReplace); //find next
	}

	return S1;
}

stDate StringToDateStructure(string sDate)
{
	stDate Date;
	vector<string> vDate = SplitString(sDate, "/");

	Date.Day = stoi(vDate[0]);
	Date.Month = stoi(vDate[1]);
	Date.Year = stoi(vDate[2]);

	return Date;
}

string FormatDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormattedDateString = "";

	FormattedDateString = ReplaceWordsInString(DateFormat, "dd", to_string(Date.Day));
	FormattedDateString = ReplaceWordsInString(FormattedDateString, "mm", to_string(Date.Month));
	FormattedDateString = ReplaceWordsInString(FormattedDateString, "yyyy", to_string(Date.Year));

	return FormattedDateString;
}

string ReadDateString(string Message)
{
	string sDate;
	cout << Message;
	getline(cin >> ws, sDate);

	return sDate;
}

int main()
{
	string sDate = ReadDateString("Please Enter Date dd/mm/yyyy? ");

	stDate Date = StringToDateStructure(sDate);

	cout << "\n" << FormatDate(Date) << "\n";

	cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << "\n";

	cout << "\n" << FormatDate(Date, "mm/dd/yyyy") << "\n";

	cout << "\n" << FormatDate(Date, "mm-dd-yyyy") << "\n";

	cout << "\n" << FormatDate(Date, "dd-mm-yyyy") << "\n";

	cout << "\n" << FormatDate(Date, "Day:dd, Month:mm, Year:yyyy") << "\n";

	system("pause>0");
	return 0;
}