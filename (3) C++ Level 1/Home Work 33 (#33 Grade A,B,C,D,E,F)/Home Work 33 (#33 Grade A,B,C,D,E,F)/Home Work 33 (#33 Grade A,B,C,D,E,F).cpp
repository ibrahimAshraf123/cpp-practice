
#include <iostream>

using namespace std;

void readGrade(int &grade) {
	cout << "Please enter your grade: \n";
	cin >> grade;
}

void printGrade(int grade) {
	cout << "Your grade is: " << grade << "\n";
}

void checkGradeScore(int grade){
	cout << "Your score is: ";
	if (grade >= 90) {
		cout << "A\n";
}
	else if (grade >= 80) {
		cout << "B\n";
	}
	else if (grade >= 70) {
		cout << "C\n";
	}
	else if (grade >= 60) {
		cout << "D\n";
	}
	else if (grade >= 50) {
		cout << "E\n";
	}
	else {
		cout << "F\n";
	}
}

int main()
{
	
	int grade;

	cout << "This program checks grade and prints scores \"A,B,C,D,E,F\"...\n";

	readGrade(grade);
	printGrade(grade);
	checkGradeScore(grade);

	return 0;
}
