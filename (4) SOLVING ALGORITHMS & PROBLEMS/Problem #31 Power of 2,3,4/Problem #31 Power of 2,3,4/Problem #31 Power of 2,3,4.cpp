using namespace std;

#include <iostream>

int ReadNumber() {
	int N;

	cout << "Enter Number:\n";
	cin >> N;

	return N;
}

void PrintPower(int N, int M)
{
	int Power = 1;
	for (int i = 1; i <= M; i++)
	{
		Power *= N;
	}
	cout << "\n" << N << " ^ " << M << " = " << Power <<endl;
}

int main()
{
	int N = ReadNumber();
	PrintPower(N, 2);
	PrintPower(N, 3);
	PrintPower(N, 4);

	return 0;
}
