
#include <iostream>

using namespace std;

void readGrades(float grades[3]) {

	cout << "please enter grade 1? \n";
	cin >> grades[0];

	cout << "please enter grade 2? \n";
	cin >> grades[1];

	cout << "please enter grade 3? \n";
	cin >> grades[2];

}

void printGradesAverage(float grades[3]) {
	
	cout << "\n***************************\n";
	cout << "The average of grades is " << ((grades[0] + grades[1] + grades[2]) / 3) << "\n";
}

int main()
{
	float grades[3];

	readGrades(grades);
	printGradesAverage(grades);

	return 0;
}
