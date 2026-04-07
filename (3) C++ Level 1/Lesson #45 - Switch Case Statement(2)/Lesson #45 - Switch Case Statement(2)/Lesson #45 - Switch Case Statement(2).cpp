using namespace std;

#include <iostream>

enum enColor {Blue = 1, Green = 2, Cyan = 3, Red = 4,Pink = 5, Yellow = 6, Grey = 7};

int main()
{
	cout << "Choose your screen color:\n";
	cout << " Blue = 1,\n Green = 2,\n Cyan = 3,\n Red = 4,\n Pink = 5,\n Yellow = 6,\n Grey = 7" << endl;
	cout << endl;

	int c;
	enColor Color;
	cin >> c;

	Color = (enColor)c;

	switch (Color) {
	case enColor::Blue:
		system("color 1F");
		break;
	case enColor::Green:
		system("color 2F");
		break;
	case enColor::Cyan:
		system("color 3F");
		break;
	case enColor::Red:
		system("color 4F");
		break;
	case enColor::Pink:
		system("color 5F");
		break;
	case enColor::Yellow:
		system("color 6F");
		break;
	case enColor::Grey:
		system("color 7F");
		break;

	default:
		cout << "ERROR wrong choice" << endl;
	}


	return 0;
}
