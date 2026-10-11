/*
4 Main OOP Concepts:
	1 - Encapsulation: encapsulate in classes.
	2 - Abstraction: seperate data and implementation.
	3 - Inheritance: classes inherit other classes. privatley, publicly & protected.
	4 - Polymorphism: many forms. overloading, overriding & virtual functions
*/

#include <iostream>

using namespace std;

//Abstract Class / Interface / Contract.
class clsMobile
{
	//Pure virtual functions.
	//	virtual functions with no implementation. turns any class into ABSTRACT class / Interface / Contract.
public:
	virtual void Dial(string PhoneNumber) = 0;
	virtual void SendSMS(string PhoneNumber, string Text) = 0;
	virtual void TakePicture() = 0;
};

class clsiPhone : public clsMobile
{
public:
	void Dial(string PhoneNumber)
	{
		cout << "\nDialing Phone Number: " + PhoneNumber << "... \n";
	};

	void SendSMS(string PhoneNumber, string Text)
	{
		cout << "\nSending: \"" + Text + "\"\nTo Phone Number: " + PhoneNumber << "... \n";
	};

	void TakePicture()
	{
		cout << "\nTaking Picture...\n ";
	};
};

int main()
{
	clsiPhone iPhone1;
	string PhoneNum = "1234567";

	iPhone1.Dial(PhoneNum);
	iPhone1.SendSMS(PhoneNum, "Hello World!");
	iPhone1.TakePicture();

	system("pause>0");
	return 0;
}