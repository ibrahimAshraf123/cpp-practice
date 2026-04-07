#include <iostream>

using namespace std;

int main()
{
	float PI = 3.14159265359;

	printf("The value of PI = %.*f \n", 1, PI);
	printf("The value of PI = %.*f \n", 2, PI);
	printf("The value of PI = %.*f \n", 3, PI);
	printf("The value of PI = %.*f \n", 4, PI);
	printf("\n");

	double x = 7.0, y = 9.0;
	printf("Result of dividing %.3f / %.3f = %.3f \n", x, y, x / y);
	printf("\n");

	printf("The value of PI is approximately = %.9f \n", PI);


	return 0;
}