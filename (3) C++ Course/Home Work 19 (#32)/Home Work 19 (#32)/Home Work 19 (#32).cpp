

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	float N, M;
	cout << "This porgram calculates \"Power of M for a number N\"... \n";
	cout << "Please enter value for N and M: \n";
	cout << "N ? ";
	cin >> N;
	cout << "\n";
	cout << "M ? ";
	cin >> M;
	cout << "\n";

	float result = pow(N, M);
	cout << "Result: \n";
	cout << N << " ^ " << M << " ~ " << round(result) << endl;


	return 0;
}


