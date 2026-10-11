#include <iostream>

using namespace std;

class clsPerson
{
private:
	int x = 10;
protected:
	int y = 20;
public:
	int z = 30;
};

int main()
{

	clsPerson Person1;

	cout << Person1.z << endl;


	return 0;
}