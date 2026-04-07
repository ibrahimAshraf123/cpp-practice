
#include <iostream>
#include <cmath>

using namespace std;

bool HireADriver(int Age, bool DriverLicense) {
	
	bool result = (Age > 21 && DriverLicense == 1);
	return result;
}

int main()
{
	cout << "Your Hiring results are: \n";
	cout << HireADriver(19, 1) << endl;


	return 0;
}
