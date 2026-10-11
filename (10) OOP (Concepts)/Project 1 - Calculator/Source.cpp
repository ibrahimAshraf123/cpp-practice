#include <iostream>

using namespace std;

class clsCalculator
{
private:
	
	float _Result = 0;
	float _LastNum = 0;
	string _LastOperation = "Clear";
	float _PreviousResult = 0;

	bool _IsZero(float Num)
	{
		return (Num == 0);
	}

public:
	

	void Add(float Num)
	{
		_LastNum = Num;
		_PreviousResult = _Result;
		_LastOperation = "Adding";
		_Result += Num;
	}

	void Sub(double Num)
	{
		_LastNum = Num;
		_PreviousResult = _Result;
		_LastOperation = "Subtracting";
		_Result -= Num;
	}

	void Mul(double Num)
	{
		_LastNum = Num;
		_PreviousResult = _Result;
		_LastOperation = "Multiplying";
		_Result *= Num;
	}

	void Div(double Num)
	{
		_LastNum = Num;

		if (_IsZero(Num))
		{
			Num = 1;
		}

		_PreviousResult = _Result;
		_LastOperation = "Dividing";
		_Result /= Num;
	}

	float GetFinalResult()
	{
		return _Result;
	}

	void Clear()
	{
		_LastNum = 0;
		_PreviousResult = 0;
		_LastOperation = "Clear";
		_Result = 0;
	}

	void CancelLastOperation()
	{
		_LastNum = 0;
		_LastOperation = "Cancelling Last Operation";
		_Result = _PreviousResult;
	}

	void PrintResult()
	{
		cout << "Result ";
		cout << "After " << _LastOperation << " " <<
			_LastNum << " is: " << _Result << endl;
	}

};

int main()
{
	clsCalculator Calc;

	Calc.Clear();

	Calc.Add(10);
	Calc.PrintResult();

	Calc.Add(100);
	Calc.PrintResult();

	Calc.Sub(20);
	Calc.PrintResult();

	Calc.Div(0);
	Calc.PrintResult();

	Calc.Div(2);
	Calc.PrintResult();

	Calc.Mul(3);
	Calc.PrintResult();

	Calc.CancelLastOperation();
	Calc.PrintResult();

	Calc.Clear();
	Calc.PrintResult();


	system("pause>0");
	return 0;
}