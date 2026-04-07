#include <iostream>
using namespace std;

int main()
{

	int Page = 1, numberOfPages = 10;

	printf("This is number %d Page \n", Page);
	printf("There are %d Pages \n", numberOfPages);
	printf("This is page %d out of %d \n", Page, numberOfPages);
	printf("\n");

	printf("There is %0*d %% chance that I fail at learning programming \n", 2, Page);
	printf("There is %0*d %% chance that I fail at learning programming \n", 3, Page);
	printf("There is %0*d %% chance that I fail at learning programming \n", 4, Page);
	printf("There is %0*d %% chance that I fail at learning programming \n", 5, Page);
	printf("\n");

	int num1 = 20, num2 = 30;

	printf("%d + %d = %d \n", num1, num2, num1 + num2);




	return 0;
}