

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string st1 = "43.22";
    int N1 = 20;
    double N2 = 33.5;
    float N3 = 55.23;

    double st1_double = stod(st1);
    float st1_float = stof(st1);
    int st1_int = stoi(st1);

    string N1_string = to_string(N1);

    string N2_string = to_string(N2);

    string N3_string = to_string(N3);
    int N3_int = int(N3);
    int N3_int = (int)N3;

    cout << st1_double << endl;
    cout << st1_float << endl;
    cout << st1_int << endl;

    cout << N1_string << endl;
    cout << N2_string << endl;
    cout << N3_string << endl;
    cout << N3_int << endl;
    
    return 0;
}

