using namespace std;

#include <iostream>

float ReadDiameter() {
    float D;
    cout << "Circle's Diameter?\n";
    cin >> D;

    return D;
}

float CircleAreaD(float D) {
    const float PI = 3.14159;

    float Area = (PI * pow(D, 2)) / 4;

    return Area;
}

void PrintResults(float CircleAreaD) {

    cout << "\nCircle Area by Diameter = " << CircleAreaD << endl;
}

int main()
{
    PrintResults(CircleAreaD(ReadDiameter()));

    return 0;
}
