//Friend Class: when a class is declared as "friend class", it can access all members of it's friend without traditional inheritance, (but not vice versa).
#include <iostream>

using namespace std;

class clsA
{
private:
	int _Var1 = 10;

protected:
	int _Var3 = 30;

public:
	int Var2 = 20;

	//this will grant access to everything to clsB
	friend class clsB;	//friend class
};

class clsB
{
public:
	void Display(clsA A1)
	{
		cout << "\nValue of Var1 = " << A1._Var1 << endl;
		cout << "\nValue of Var2 = " << A1.Var2 << endl;
		cout << "\nValue of Var3 = " << A1._Var3 << endl;
	}
};


int main()
{
	clsA A1;
	clsB B1;

	B1.Display(A1);
	//members of clsA are accessble inside clsB, but not outside of the class


	system("pause>0");
	return 0;
}