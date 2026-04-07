
#include <iostream>

using namespace std;

struct stInfo {
    int Age;
    bool HasDriverLicense;
};

stInfo ReadInfo() 
{
    stInfo Info;

    cout << "Enter your age:\n";
    cin >> Info.Age;

    cout << "Do you have a Driver's License (1/0)?\n";
    cin >> Info.HasDriverLicense;

    return Info;
}

bool IsHired(stInfo Info)
{
    return (Info.Age > 21 && Info.HasDriverLicense);
}

void PrintResult(stInfo Info) {
    if (IsHired(Info)) {
        cout << "\nHired\n";
    }
    else {
        cout << "\nRejected\n";
    }
    
}


int main()
{
    
    PrintResult(ReadInfo());
    
    return 0;
}
