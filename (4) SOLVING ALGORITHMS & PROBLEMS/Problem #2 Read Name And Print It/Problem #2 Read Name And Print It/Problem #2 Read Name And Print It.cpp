
#include <iostream>
#include <string>

using namespace std;

string ReadName() {
    string name;
    cout << "Enter your name: \n";
    getline(cin, name);
    return name;
}

void PrintName(string name) {
    cout << "\nYour name is: " << name << endl;
}

int main()
{
    
    PrintName(ReadName());

    return 0;
}
