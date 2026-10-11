using namespace std;

#include <iostream>

int readN() {
	
	cout << "Enter value of N: \n";
	int N;
	cin >> N;
	cout << "***************************\n";

	return N;
}

void SumEvenNumbers(int N) {
	
	int sum = 0;

	for (int i = 0; i <= N; i += 2) {
		cout << i << endl;
		sum += i;
	}
	cout << "***************************\n";
	cout << "Sum of Even Numbers = " << sum << endl;
}

int main()
{
	
	SumEvenNumbers(readN());

	return 0;
}
