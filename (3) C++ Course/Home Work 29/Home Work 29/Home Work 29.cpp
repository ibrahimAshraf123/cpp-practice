
#include <iostream>

using namespace std;

float getAverageFunction(float x, float y, float z) {
	float Average = ((x + y + z) / 3);
	return Average;
}

int main()
{
	float x[3];
	cout << "Please Enter Grade1? \n";
	cin >> x[0];
	cout << "Please Enter Grade2? \n";
	cin >> x[1];
	cout << "Please Enter Grade3? \n";
	cin >> x[2];
	cout << "\n*************************\n";
	cout << "The average of grades is: " << getAverageFunction(x[0], x[1], x[2]) << endl;
	return 0;
}
