using namespace std;

#include <iostream>

int readN() {
	cout << "Enter value of N: \n";
	int N;
	cin >> N;
	cout << "***********************\n";
	return N;
}

void SumOddNumbers(int N) {
	int sum = 0;

	for (int i = 1; i <= N; i += 2) {

		cout << i << endl;
		sum += i;

	}
	cout << "***********************\n";
	cout << "Sum of Odd Numbers = " << sum << endl;
}

int main()
{
	SumOddNumbers(readN());
	
	return 0;
}
