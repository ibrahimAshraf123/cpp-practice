using namespace std;

#include <iostream>

enum enPassFail { Pass = 1, Fail = 2 };

int ReadGrade() {
	int Grade;
	cout << "Enter your Grade:\n";
	cin >> Grade;

	return Grade;
}

enPassFail CheckPassFail(int Grade) {
	
	if (Grade >= 50)
		return enPassFail::Pass;
	else
		return enPassFail::Fail;
}

void PrintResults(int Grade) {

	if (CheckPassFail(Grade) == enPassFail::Pass)
		cout << "\nYou Passed" << endl;
	else
		cout << "\nYou Failed" << endl;

	
}

int main()
{
	PrintResults(ReadGrade());

	return 0;
}
