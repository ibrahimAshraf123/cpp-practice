
#include <iostream>

using namespace std;

struct stInfo {
	int Age;
	bool HasDriverLicense;
	bool HasRecommendations;
};

stInfo ReadInfo() {
	stInfo Info;
	cout << "Enter Age:\n";
	cin >> Info.Age;
	cout << "Do you have a Driver's License? (1/0)\n";
	cin >> Info.HasDriverLicense;
	cout << "Do you have a Recommendation Letter? (1/0)\n";
	cin >> Info.HasRecommendations;

	return Info;
}

bool IsHired(stInfo Info) {
	if (Info.HasRecommendations) {
		return true;
	}
	else {
		return (Info.Age > 21 && Info.HasDriverLicense);
	}
	
}

void PrintResult(stInfo Info){
	if (IsHired(Info)) {
		cout << "\nHired\n";
	}
	else {
		cout << "\nRejected\n";
	}
}

int main()
{
	PrintResult(ReadInfo());

	return 0;
}
