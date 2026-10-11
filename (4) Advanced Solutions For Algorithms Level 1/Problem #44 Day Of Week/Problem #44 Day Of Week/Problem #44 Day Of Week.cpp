using namespace std;

#include <iostream>

enum enDaysOfWeek { Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thur = 5, Fri = 6, Sat = 7 };

int ReadNumberInRange(string Message, int From, int To)
{
	int N;
	do
	{
		cout << Message << endl;
		cin >> N;
	} while (N < From || N > To);

	return N;
}

enDaysOfWeek ReadDayOfWeek()
{
	return (enDaysOfWeek)ReadNumberInRange("Please Enter Day Number: Sun = 1, Mon = 2, Tue = 3, Wed = 4, Thur = 5, Fri = 6, Sat = 7",1,7);
}

string GetDayOfWeek(enDaysOfWeek Day)
{
	switch (Day)
	{
	case Sun:return "Sunday";
	case Mon:return "Monday";
	case Tue:return "Tuesday";
	case Wed:return "Wednesday";
	case Thur:return "Thursday";
	case Fri:return "Friday";
	case Sat:return "Saturday";
	default: return "Not a valid Day";
	}
}

int main()
{

	cout << GetDayOfWeek(ReadDayOfWeek()) << endl;

	return 0;
}
