
#include <iostream>

using namespace std;


int readN() {
	cout << "Enter value of N: \n";
	int N;
	cin >> N;

	if (N <= 0) {
		cout << "ERROR\n";
		return readN();
	}
	return N;
}

void printFactorial(int N) {
	
	
	int f = 1;

	for (int i = 1; i <= N; ++i) {

		f *= i;
		
	}
	cout << "Result: " << f << endl;
}

int main()
{
	printFactorial(readN());


	return 0;
}

