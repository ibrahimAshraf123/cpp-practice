#include <iostream>

using namespace std;

int ReadNumber()
{
	int Num;
	cout << "Please enter a number? ";
	cin >> Num;
	return Num;
}

string NumberToText(int Number)
{
	//zero
	if (Number == 0)
	{
		return "";
	}

	if (Number >= 1 && Number <= 19)
	{
		string arr[] =
		{ "","one","two","three","four","five",
			"six","seven","eight","nine","ten",
			"eleven","twelve","thirteen","fourteen","fifteen",
			"sixteen","seventeen","eighteen","nineteen" 
		};

		return arr[Number] + " ";
	}

	if (Number >= 20 && Number <= 99)
	{
		string arr[] =
		{ "","","twenty","thirty","fourty","fifty",
			"sixty","seventy","eighty","ninety"
		};

		return arr[Number/10] + " " + NumberToText(Number % 10);
	}

	//hundreds
	if (Number >= 100 && Number <= 199)
	{

		return "one hundred " + NumberToText(Number % 100);
	}

	if (Number >= 200 && Number <= 999)
	{

		return NumberToText(Number / 100) + "hundreds " + NumberToText(Number % 100);
	}

	//thousands
	if (Number >= 1000 && Number <= 1999)
	{

		return "one thousand " + NumberToText(Number % 1000);
	}

	if (Number >= 2000 && Number <= 999999)
	{

		return NumberToText(Number / 1000) + "thousands " + NumberToText(Number % 1000);
	}
	
	//millions
	if (Number >= 1000000 && Number <= 1999999)
	{

		return "one million " + NumberToText(Number % 1000000);
	}

	if (Number >= 2000000 && Number <= 999999999)
	{

		return NumberToText(Number / 1000000) + "millions " + NumberToText(Number % 1000000);
	}

	//billions
	if (Number >= 1000000000 && Number <= 1999999999)
	{

		return "one billion " + NumberToText(Number % 1000000000);
	}

	if (Number >= 2000000000 && Number <= 999999999999)
	{

		return NumberToText(Number / 1000000000) + "millions " + NumberToText(Number % 1000000000);
	}
	

	
}

int main()
{
	int Number = ReadNumber();

	cout << NumberToText(Number) << endl;


	system("pause>0");

	return 0;
}