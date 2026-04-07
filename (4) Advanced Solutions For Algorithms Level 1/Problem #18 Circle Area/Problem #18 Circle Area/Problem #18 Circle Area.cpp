using namespace std;

#include <iostream>
#include <cmath>

float ReadRadius()
{
    float r;

    cout << "Circle's radius?\n";
    cin >> r;

    return r;
}

float CircleArea(float r)
{
    const float PI = 3.14159;

    float Area = PI * pow(r, 2);
    return Area;
}

void PrintResults(float CircleArea)
{
    cout << "\nCircle Area = " << CircleArea << endl;
}

int main()
{
    
    PrintResults(CircleArea(ReadRadius()));

    return 0;
}
