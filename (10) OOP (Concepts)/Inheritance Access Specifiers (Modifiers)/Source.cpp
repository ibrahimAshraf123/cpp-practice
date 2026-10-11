//Inheritance: Access Specifiers/Modifiers, visibility mode, Inheritance Types practice
// 
// Access Specifiers/Modifiers:		1-private	2-protected		3-public
// 
//visibility modes:
//syntax: class inheritedClass : <visibility mode> baseClass
//visibility modes:		1-public	2-protected		3-private
//
//Inheritance Types: 1-single 	2-multi-level 	3-hierarchal, other types: 4-multiple	5-hybrid
// single (a : b), multi-level (a : b : c), hierarchal (a : b,c,d)
// multiple (a,b : c), hybrid (a : b,c : d)

#include <iostream>

using namespace std;

class clsA
{
private:
	string Var1 = "Variable 1";
	string Func1()
	{
		return "Function 1";
	}
protected:
	string Var2 = "Variable 2";
	string Func2()
	{
		return "Function 2";
	}
public:
	string Var3 = "Variable 3";
	string Func3()
	{
		return "Function 3";
	}
};

class clsB : public clsA
{
public:
	string Var4 = "Variable4";
	string Func4()
	{
		return "Function4";
	}
	string InheritedFunction()
	{
		return clsA::Func2();
	}
	string InheritedVar2 = clsA::Var2;
};


//different visibility modes
class clsX : public clsA
{
	//public inheritance keeps the same visibility to variables and functions (protected -> protected, public -> public)
	string var2x = clsA::Var2;
	string var3x = clsA::Var3;

	string Func2x()
	{
		return clsA::Func2();
	}
	
	string Func3x()
	{
		return clsA::Func3();
	}
		
};

class clsY : protected clsA
{
	//protected inheritance turns inherited varibales and functions into protected
	string VarY2 = clsA::Var2;
	string VarY3 = clsA::Var3;

	string FunctionY2()
	{
		return clsA::Func2();
	}
	
	string FunctionY3()
	{
		return clsA::Func3();
	}
};

class clsZ : private clsA
{
	//private inheritance turns inherited variables and functions private
	string VarZ2 = clsA::Var2;
	string VarZ3 = clsA::Var3;

	string FuncZ2()
	{
		return clsA::Func2();
	}

	string FuncZ3()
	{
		return clsA::Func3();
	}
};

int main()
{
	clsA A;
	clsB B;
	clsX X;
	clsY Y;
	clsZ Z;

	cout << "Class A:" << endl;
	cout << A.Var3 << endl;
	cout << A.Func3() << endl;

	cout << endl;

	cout << "Class B:" << endl;
	cout << B.InheritedVar2 << endl;
	cout << B.InheritedFunction() << endl;
	

	cout << B.Var3 << endl;
	cout << B.Func3() << endl;

	cout << B.Var4 << endl;
	cout << B.Func4() << endl;
	cout << endl;

	cout << "Class X:" << endl;
	cout << X.Var3 << endl;
	cout << X.Func3() << endl;
	cout << endl;

	cout << "Class Y:" << endl;
	cout << endl;

	cout << "Class Z:" << endl;
	cout << endl;


	system("pause>0");
	return 0;
}