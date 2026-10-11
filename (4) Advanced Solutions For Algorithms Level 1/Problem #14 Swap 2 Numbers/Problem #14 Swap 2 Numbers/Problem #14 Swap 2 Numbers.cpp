

#include <iostream>
using namespace std;

void ReadNumbers(int& A, int& B)
{
	cout << "Enter Value of A:\n";
	cin >> A;
	cout << "Enter Value of B:\n";
	cin >> B;
}

void Swap(int& A, int& B)
{
	int Temp = A;
	A = B;
	B = Temp;

}

void PrintNumbers(int A, int B)
{
	cout << "\n*****************\n";
	cout << "Number A = " << A << endl;
	cout << "Number B = " << B << endl;
	cout << "*****************\n";
}

int main()
{
	int A, B;
	ReadNumbers(A, B);
	PrintNumbers(A, B);
	Swap(A, B);
	cout << "\nAfter Swap\n";
	PrintNumbers(A, B);

	return 0;
}
