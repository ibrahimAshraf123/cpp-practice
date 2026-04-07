

#include <iostream>

using namespace std;

struct stAdress {
    string street;
    string POBOX;
};




struct Employee {
    string name;
    short age;
    string city;
    string country;
    float monthlySalary;
    float yearlySalary;
    //char gender;
   //bool married;

    stAdress ibrahimAddress;

};

enum gender{Male,Female};
enum status{single,married};
enum color{white,red,orange,yellow,green,blue,purple,black};

int main()
{
    Employee ibrahim;

    ibrahim.name = "Ibrahim Ashraf";
    ibrahim.age = 26;
    ibrahim.city = "Al Ain";
    ibrahim.country = "UAE";
    ibrahim.monthlySalary = 35000;
    ibrahim.yearlySalary = (ibrahim.monthlySalary * 12);
    //ibrahim.gender = 'M';
    //ibrahim.married = true;
    ibrahim.ibrahimAddress.street = "Al Foufilli";
    ibrahim.ibrahimAddress.POBOX = "NoN";

    gender ibrahimGender;
    status ibrahimStatus;
    color ibrahimColor;

    ibrahimGender = gender::Male;
    ibrahimStatus = status::single;
    ibrahimColor = color::black;

    cout <<
        "**************************\n" <<
        "Name: " << ibrahim.name << "\n" <<
        "Age: " << ibrahim.age << "\n" <<
        "City: " << ibrahim.city << "\n" <<
        "Country: " << ibrahim.country << "\n" <<
        "Monthly Salary: " << ibrahim.monthlySalary << "\n" <<
        "Yearly Salary: " << ibrahim.yearlySalary << "\n" <<
        "Gender: " << ibrahimGender << "\n" << 
        "Married: " << ibrahimStatus << "\n" << 
        "Fav Color: " << ibrahimColor << "\n" <<
        //"Gender: " << ibrahim.gender << "\n" <<
        //"Married: " << ibrahim.married << "\n" <<
        "Street: " << ibrahim.ibrahimAddress.street << "\n" <<
        "PO Box: " << ibrahim.ibrahimAddress.POBOX << "\n" <<
        "**************************\n";

    return 0;                       
}


