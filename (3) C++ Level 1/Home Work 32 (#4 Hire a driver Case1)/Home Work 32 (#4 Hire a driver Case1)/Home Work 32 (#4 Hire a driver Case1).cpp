
#include <iostream>

using namespace std;

struct stInfo {
	int Age;
	bool HasDriverLicense;
};

void readInfo(stInfo &CandidateInfo) {
	cout << "Enter Age: \n";
	cin >> CandidateInfo.Age;
	cout << "Do you have a Driver's license? (1/0): \n";
	cin >> CandidateInfo.HasDriverLicense;
}

void HireProcedure(stInfo CandidateInfo) {
	if (CandidateInfo.Age > 21 && CandidateInfo.HasDriverLicense == true) {
		cout << "Hired" << endl;
	}
	else {
		cout << "Rejected" << endl;
	}
}

int main()
{
	
	stInfo CandidateInfo;
	
	readInfo(CandidateInfo);
	HireProcedure(CandidateInfo);


	return 0;
}
