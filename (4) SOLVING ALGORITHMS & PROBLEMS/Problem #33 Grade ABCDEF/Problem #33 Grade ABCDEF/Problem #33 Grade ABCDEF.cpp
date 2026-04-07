using namespace std;

#include <iostream>
#include <string>

enum enGrade { A, B, C, D, E, F };

int ReadMark() {
    int Mark;
    cout << "Enter Mark from 0 to 100:\n";
    cin >> Mark;

    if (Mark > 100) {
        cout << "\nERROR\n";
        ReadMark();
    }
        return Mark;
}

enGrade GetGrade(int Mark)
{
    if (Mark >= 90 && Mark <= 100)
        return A;

    else if (Mark >=80)
        return B;

    else if (Mark >= 70)
        return C;

    else if (Mark >= 60)
        return D;

    else if (Mark >= 50)
        return E;

    else 
        return F;
}

string GradeToString(enGrade Grade)
{
    switch (Grade) {
    case A: return "A";
    case B: return "B";
    case C: return "C";
    case D: return "D";
    case E: return "E";
    case F: return "F";
    default: return "Invalid";
    }
}

int main()
{
    int M = ReadMark();
    enGrade Grade = GetGrade(M);

    cout << "Your grade is: " << GradeToString(Grade) << endl;
    
    return 0;
}
