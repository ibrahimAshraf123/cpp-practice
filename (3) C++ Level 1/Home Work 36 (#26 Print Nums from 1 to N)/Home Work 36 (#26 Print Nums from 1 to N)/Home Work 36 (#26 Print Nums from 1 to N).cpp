using namespace std;

#include <iostream>

int readN() {

	cout << "Please enter value of N: \n";

	int N;
	cin >> N;
	return N;

}

void printNumbers(int N){

	cout << "\nResult: \n";

	for (int c = 1; c <= N; c++) {
		cout << c << endl;
	}

}

int main()
{
	
	
	printNumbers(readN());
	

	return 0;
}
