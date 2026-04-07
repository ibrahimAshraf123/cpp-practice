
#include <iostream>

using namespace std;

struct stInfo {
	float marks[3];
	float Average;
};

void readMarks(stInfo &StudentInfo) {
	cout << "Please enter mark 1: \n";
	cin >> StudentInfo.marks[0];
	cout << "Please enter mark 2: \n";
	cin >> StudentInfo.marks[1];
	cout << "Please enter mark 3: \n";
	cin >> StudentInfo.marks[2];
	StudentInfo.Average = ((StudentInfo.marks[0] + StudentInfo.marks[1] + StudentInfo.marks[2]) / 3);
}

void printMarks(stInfo StudentInfo) {
	cout << "\n************************\n";
	cout << "Your Marks are: \n";
	cout << StudentInfo.marks[0] << "\t" << StudentInfo.marks[1] << "\t" << StudentInfo.marks[2] << "\n";
	cout << "Your Average is: \n";
	cout << StudentInfo.Average <<"\n";
	cout << "\n************************\n";
}

void AveragePassFailProcedure(stInfo StudentInfo) {
	if (StudentInfo.Average >= 50) {
		cout << StudentInfo.Average << " is >= 50 \nPass\n";
	}
	else {
		cout << StudentInfo.Average << " is not >= 50 \nFail\n";
	}
}

int main()
{
	stInfo Student1;

	readMarks(Student1);
	printMarks(Student1);
	AveragePassFailProcedure(Student1);

	return 0;
}
