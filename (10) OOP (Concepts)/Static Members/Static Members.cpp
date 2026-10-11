#include <iostream>

using namespace std;

class clsA
{
private:

public:

    int var;
    int static counter;

    clsA()
    {
        counter++;
    };

    void print()
    {
        cout << var << endl;
        cout << counter << endl;
        cout << endl;
    }
};

int clsA::counter = 0;

int main()
{

    clsA A, B, C;

    A.var = 10;
    B.var = 20;
    C.var = 30;

    A.print();
    B.print();
    C.print();

    A.counter = 500;

    cout << "\nAfter changing counter to 500\n\n";

    A.print();
    B.print();
    C.print();

    system("pause>0");
    return 0;
}
