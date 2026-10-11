#include <iostream>

using namespace std;

class clsA
{
public:
	static int Function1()
	{
		return 10;
	}

	int Function2()
	{
		return 20;
	}
};

int main()
{
	cout << clsA::Function1() << endl; //static function called without object

	clsA A1, A2, A3;

	cout << A1.Function1() << endl; //static function called with object
	cout << A1.Function2() << endl; //normal function called with object

	cout << A2.Function1() << endl;
	cout << A2.Function2() << endl;



	system("pause>0");
	return 0;
}