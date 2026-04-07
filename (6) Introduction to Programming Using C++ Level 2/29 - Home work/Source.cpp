#include <iostream>
#include <vector>
using namespace std;

void ReadNumbers(vector <int>& vNumbers)
{
	char ReadMore = 'Y';
	int Number;

	while (ReadMore == 'Y' || ReadMore == 'y')
	{
		printf("\nEnter Number to add into vector: ");
		cin >> Number;

		vNumbers.push_back(Number);

		printf("Do you want to add more numbers? (Y/N)? ");
		cin >> ReadMore;

	}

}

void PrintVectorElements(vector <int> & vNumbers)
{
	printf("\nVector Numbers: \n");

	for (int Number : vNumbers)
	{
		printf("%.d\n", Number);
	}
	cout << endl;
}

int main()
{
	vector <int> vNumbers;
	ReadNumbers(vNumbers);
	PrintVectorElements(vNumbers);

	return 0;
}