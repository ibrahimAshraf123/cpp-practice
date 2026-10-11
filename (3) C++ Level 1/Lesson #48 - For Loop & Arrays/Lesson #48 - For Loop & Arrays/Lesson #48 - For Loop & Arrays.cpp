using namespace std;

#include <iostream>

void readArrayData(int &length, int Array1[100]) {
	cout << "How many numbers do you want to enter? [1 - 100]\n";
	cin >> length;
	cout << "*********************\n";

	for (int i = 0; i <= length - 1; i++) {
		cout << "Enter number " << i + 1 << " :\n";
		cin >> Array1[i];
	}
}

void printArrayData(int length,int Array1[100]) {

	for (int i = 0; i <= length - 1; i++) {
		cout << "Number [" << i + 1 << "] : " << Array1[i] << endl;

	}
}

int calcSum(int length, int Array1[100]) {
	int sum = 0;

	for (int i = 0; i <= length - 1; i++) {
		sum += Array1[i];
	}
	return sum;
}

int main()
{
	int length;
	int Array1[100];
	
	readArrayData(length, Array1);

	cout << "*********************\n";
	printArrayData(length, Array1);
	cout << "*********************\n";

	int sum = calcSum(length, Array1);
	cout << "Sum = " << sum << endl;
	cout << "Average = " << (float)sum / length << endl;

	return 0;
}