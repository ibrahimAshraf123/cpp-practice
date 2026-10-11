
#include <iostream>

using namespace std;

bool HireADriverCase2(int age, bool HasDriverLicense, bool HasRecommendation) {

	bool result = ((HasRecommendation == 1) || (age > 21 && HasDriverLicense == 1));

	return result;
}

int main()
{
	int myAge;
	bool myDriverLicense;
	bool myRecommendation;

	cout << "This program automatically hires Driver candidates... \n";
	cout << "Please enter your age: \n";
	cin >> myAge;
	cout << "\n";
	cout << "Do you have a Driver's License? (1/0)... \n";
	cin >> myDriverLicense;
	cout << "\n";
	cout << "Do you have a Recommendation letter? (1/0)... \n";
	cin >> myRecommendation;
	cout << "\n";

	cout << "Your hiring results are: \n";
	cout << HireADriverCase2(myAge, myDriverLicense, myRecommendation) << endl;


	return 0;
}
