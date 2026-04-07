

#include <iostream>
using namespace std;

int main()
{
	cout << "12 > = 12 ? " << (12 >= 12) << endl;
	cout << "12 > 7 ? " << (12 > 7) << endl;
	cout << "8 < 6 ? " << (8 < 6) << endl;
	cout << "8 = 8 ? " << (8 == 8) << endl;
	cout << "12 <= 12 ? " << (12 <= 12) << endl;
	cout << "7 == 5 ? " << (7 == 5) << endl;
	cout << endl;

	cout << "NOT (12 > = 12) ? " << !(12 >= 12) << endl;
	cout << "NOT (12 > 7 ?) " << !(12 > 7) << endl;
	cout << "NOT (8 < 6 ?) " << !(8 < 6) << endl;
	cout << "NOT (8 = 8 ?) " << !(8 == 8) << endl;
	cout << "NOT (12 <= 12) ? " << !(12 <= 12) << endl;
	cout << "NOT (7 == 5) ? " << !(7 == 5) << endl;
	cout << endl;

	cout << "1 AND 1 ? " << (1 && 1) << endl;
	cout << "True AND 0 ? " << (true && 0) << endl;
	cout << "0 OR 1 ? " << (0 || 1) << endl;
	cout << "0 OR 0 ? " << (0 || 0) << endl;
	cout << "Not 0 ? " << !(0) << endl;
	cout << "Not (1 OR 0) ? " << !(1 || 0) << endl;
	cout << endl;

	cout << "(7 = 7) and (7 > 5) ? " << ((7 == 7) && (7 > 5)) << endl;
	cout << "(7 = 7) and (7 < 5) ? " << ((7 == 7) && (7 < 5)) << endl;
	cout << "(7 = 7) or (7 < 5) ? " << ((7 == 7) || (7 < 5)) << endl;
	cout << "(7 = 7) or (7 > 5) ? " << ((7 == 7) || (7 > 5)) << endl;
	cout << "NOT(7 = 7) and (7 > 5) ? " << (!(7 == 7) && (7 > 5)) << endl;
	cout << "(7 = 7) and NOT(7 < 5) ? " << ((7 == 7) && !(7 < 5)) << endl;
	cout << endl;

	return 0;
}


