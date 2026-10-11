#include <iostream>

using namespace std;

class clsPerson
{
private:
	//private members (variables)
	short _ID; 
	string _FirstName; 
	string _LastName; 
	string _Email; 
	string _PhoneNumber;

public:

	//constructor
	clsPerson(short ID, string FirstName, string LastName, string Email, string PhoneNumber)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_PhoneNumber = PhoneNumber;
	}

	//methods (functions)
	//read only property
	short ID()
	{
		return _ID;
	}

	//read and write properties (Set and Get methods)
	void SetFirstName(string FirstName)
	{
		_FirstName = FirstName;
	}

	string GetFirstName()
	{
		return _FirstName;
	}

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	string GetLastName()
	{
		return _LastName;
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}

	void SetPhoneNumber(string PhoneNumber)
	{
		_PhoneNumber = PhoneNumber;
	}

	string GetPhoneNumber()
	{
		return _PhoneNumber;
	}

	//other methods
	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	void Print()
	{
		cout << "\nInfo:\n";
		cout << "________________________\n";
		cout << "ID          : "<< _ID <<"\n";
		cout << "First Name  : " << _FirstName << "\n";
		cout << "Last Name   : " << _LastName << "\n";
		cout << "Full Name   : " << FullName() << "\n";
		cout << "Email       : " << _Email << "\n";
		cout << "Phone Number: " << _PhoneNumber << "\n";
		cout << "________________________\n";
		cout << endl;
	}

	void SendEmail(string Subject, string Body)
	{
		cout << "\nThe following message sent successfully to email: " << _Email;
		cout << "\nSubject: " << Subject;
		cout << "\nBody: " << Body;
		cout << endl;
	}

	void SendSMS(string Message)
	{
		cout << "\nThe following SMS sent successfully to phone: " << _PhoneNumber << endl;;
		cout << Message;
		cout << endl;
	}
};

int main()
{
	clsPerson Person1(10, "Ibrahim", "Mohamed", "ibrahim@example.com", "056-123-4567");

	Person1.Print();
	Person1.SendEmail("Hi", "How are you?");
	Person1.SendSMS("How are you?");

	system("pause>0");
	return 0;
}