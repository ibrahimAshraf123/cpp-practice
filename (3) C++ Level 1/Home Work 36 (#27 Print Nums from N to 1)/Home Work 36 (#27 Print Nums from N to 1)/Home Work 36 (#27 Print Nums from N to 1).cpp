using namespace std;

#include <iostream>

int readN() {
	cout << "Please enter value of N: \n";

	int N;
	cin >> N;
	return N;
}

void printNumbers(int N) {
	cout << "\nResults:\n";

	for (int i = N; i >= 1; i--) {

		cout << i << endl;
	}
}

int main()
{
	
	printNumbers(readN());
	

	return 0;
}
