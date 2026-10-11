
#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To)
{
	
	//srand((unsigned)time(NULL)); (use once in main)
	
	int RandNum = rand() % (To - From + 1) + From;

	return RandNum;
}

int main()
{
	srand((unsigned)time(NULL));

	cout << RandomNumber(1,10) << endl;
	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(1, 10) << endl;
	cout << rand() << endl;
	


	return 0;
}

