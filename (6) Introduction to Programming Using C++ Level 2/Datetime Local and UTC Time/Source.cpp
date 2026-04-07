#include <iostream>
#include <ctime>

#pragma warning(disable: 4996)

using namespace std;

int main()
{
	time_t now = time(0); //get time now

	char* dt = ctime(&now); //convert now to string form
	cout << " The local date and time is: " << dt << endl;

	tm* gmtm = gmtime(&now); //convert now to struct tm form

	dt = asctime(gmtm); //convert now to string form
	cout << " The UTC date and time is: " << dt << endl;




	return 0;
}