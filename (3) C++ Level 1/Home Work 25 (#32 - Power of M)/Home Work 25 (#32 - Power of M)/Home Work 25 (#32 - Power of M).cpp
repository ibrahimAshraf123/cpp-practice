
#include <iostream>
#include <cmath>

using namespace std;

void PowerOfMProcedure(float n, float m) {
	float result = pow(n, m);
	cout << result << endl;
	return;
}

int main()
{
	float myN, myM;
	cout << "This program prints \"Power of M of a number N\"... \n";
	cout << "please enter number value N: \n";
	cin >> myN;
	cout << "please enter power value M: \n";
	cin >> myM;
	cout << "\n";

	cout << myN << " ^ " << myM << " = ";
	PowerOfMProcedure(myN, myM);

	return 0;
}
