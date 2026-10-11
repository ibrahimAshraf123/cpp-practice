#pragma once
#include <iostream>
#include <vector>

using namespace std;

class clsString
{
private:
	string _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string S1)
	{
		return S1.length();
	}

	short Length()
	{
		return _Value.length();
	}

	static int CountWords(string S1)
	{

		string deLim = " ";
		int Counter = 0;
		short pos = 0;
		string sWord;

		while ((pos = S1.find(deLim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				Counter++;
			}
			S1.erase(0, pos + deLim.length());
		}

		if (S1 != "")
		{
			Counter++;
		}

		return Counter;
	};

	int CountWords()
	{
		return CountWords(_Value);
	}

	static void PrintFirstLetters(string String)
	{
		cout << "The First Letters of this string: \n";
		cout << String[0] << endl;

		for (int i = 0; i < String.length(); i++)
		{
			if (String[i] == ' ')
			{
				cout << String[i + 1] << endl;
			}
		}
	}

	void PrintFirstLetters()
	{
		PrintFirstLetters(_Value);
	}

	static string UpperFirstLetterOfEachWord(string str)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && isFirstLetter)
			{
				str[i] = toupper(str[i]);
			}

			isFirstLetter = (str[i] == ' ' ? true : false);
		}

		return str;
	}

	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;

		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);
			}

			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
		return S1;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllLetters(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);
		}

		return S1;
	}

	void UpperAllLetters()
	{
		_Value = UpperAllLetters(_Value);
	}

	static string LowerAllLetters(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}

		return S1;
	}

	void LowerAllLetters()
	{
		_Value = LowerAllLetters(_Value);
	}

	static char InvertLetterCase(char C1)
	{
		return isupper(C1) ? tolower(C1) : toupper(C1);
	}

	static string InvertAllLetters(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}

		return S1;
	}

	void InvertAllLetters()
	{
		_Value = InvertAllLetters(_Value);
	}

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;


			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;


		}

		return Counter;
	}

	static short CountSmallLetters(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountCapitalLetters(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}

	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short CountSpecificLetter(string S, char C, bool MatchCase = true)
	{
		short Counter = 0;
		for (short i = 0; i < S.length(); i++)
		{
			if (MatchCase)
			{
				if (S[i] == C)
				{
					Counter++;
				}
			}
			else
			{
				if (S[i] == C || S[i] == InvertLetterCase(C))
				{
					Counter++;
				}
			}

		}
		return Counter;
	}

	int CountSpecificLetter(char C, bool MatchCase)
	{
		return CountSpecificLetter(_Value, C, MatchCase);
	}

	static bool IsVowel(char C)
	{
		C = tolower(C);
		return (C == 'u' || C == 'a' || C == 'e' || C == 'i' || C == 'o');
	}

	static short CountVowels(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
			{
				Counter++;
			}
		}
		return Counter++;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static void PrintVowels(string S)
	{
		cout << "\nVowels in string are: ";

		for (short i = 0; i < S.length(); i++)
		{
			if (IsVowel(S[i]))
			{
				cout << S[i] << "    ";
			}
		}
	}

	void PrintVowels()
	{
		return PrintVowels(_Value);
	}

	static void PrintEachWord(string S1)
	{

		string deLim = " ";

		cout << "\nYour string words are: \n\n";
		short pos = 0;
		string sWord;

		while ((pos = S1.find(deLim)) != string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S1.erase(0, pos + deLim.length());
		}

		if (S1 != "")
		{
			cout << S1 << endl;
		}
	}

	void PrintEachWord()
	{
		return PrintEachWord(_Value);
	}

	static vector<string> Split(string S1, string deLim)
	{
		vector<string> result;
		short pos = 0;
		string token;

		while ((pos = S1.find(deLim)) != std::string::npos)
		{
			token = S1.substr(0, pos);
			if (token != "")
			{
				result.push_back(token);
			}

			S1.erase(0, pos + deLim.length());
		}

		if (S1 != "")
		{
			result.push_back(S1);
		}

		return result;
	}

	vector<string> Split(string deLim)
	{
		return Split(_Value, deLim);
	}

	static string TrimLeft(string S)
	{

		for (short i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ')
			{
				return S.substr(i, S.length() - i);
			}
		}

		return "";
	}

	static string TrimRight(string S)
	{
		for (short i = S.length() - 1; i >= 0; i--)
		{
			if (S[i] != ' ')
			{
				return S.substr(0, i + 1);
			}
		}

		return "";
	}

	static string Trim(string S)
	{

		return (TrimLeft(TrimRight(S)));
	}

	string TrimLeft()
	{
		return TrimLeft(_Value);
	}

	string TrimRight()
	{
		return TrimRight(_Value);
	}

	string Trim()
	{
		return Trim(_Value);
	}

	static string Join(vector<string> vString, string Delim)
	{
		string result = "";

		for (string& S : vString)
		{
			result += S + Delim;
		}

		return result.substr(0, result.length() - Delim.length());
	}

	static string Join(string arrString[], short StringLength, string Delim)
	{
		string S1 = "";

		for (short i = 0; i < StringLength; i++)
		{
			S1 += arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string ReverseWords(string S1)
	{
		vector<string> vString;
		string S2 = "";

		vString = Split(S1, " ");

		// declare iterator
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;

			S2 += *iter + " ";
		}


		S2 = S2.substr(0, S2.length() - 1); // remove last space

		return S2;

	}

	void ReverseWords()
	{
		_Value = ReverseWords(_Value);
	}

	static string ReplaceWord(string S1, string StringToReplace, string sReplaceWith, bool MatchCase = true)
	{
		vector<string> vStringWords = Split(S1, " ");

		for (string& s : vStringWords)
		{
			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sReplaceWith;
				}
			}

			else
			{
				if (LowerAllLetters(s) == LowerAllLetters(StringToReplace))
				{
					s = sReplaceWith;
				}
			}

		}

		return Join(vStringWords, " ");

	}

	void ReplaceWord(string StringToReplace, string sReplaceWith, bool MatchCase = true)
	{
		_Value = ReplaceWord(_Value, StringToReplace, sReplaceWith, MatchCase);
	}

	static string RemovePunctuationsFromString(string S1)
	{
		string S2 = "";

		for (size_t i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}

		return S2;
	}

	void RemovePunctuationsFromString()
	{
		_Value = RemovePunctuationsFromString(_Value);
	}

};

