#include <iostream>
using namespace std;

int main() {

	int num;
	cout << "Enter an # of students: " << endl;
	cin >> num;

	float* ptr;

	ptr = new float[num];

	cout << "Enter grades of students: " << endl;
	for (int i = 0; i < num; i++)
	{
		cout << "Student " << i + 1 << ": ";
		cin >> *(ptr + i);
	}
	cout << endl;

	cout << "Grades of students: " << endl;
	for (int i = 0; i < num; i++)
	{
		cout << "Student " << i + 1 << ": " << *(ptr + i) << "\n";
	}
	cout << endl;

	delete[] ptr;

	return 0;
}