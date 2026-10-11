#include <iostream>
#include "clsPerson.h";
#include "clsEmployee.h";

using namespace std;


int main()

{

    clsEmployee Employee1(10, "Ibrahim", "Mohamed", "A@a.com", "8298982", "Software Engineer", "Software Department", 10000);

    Employee1.Print();

    system("pause>0");
    return 0;
}