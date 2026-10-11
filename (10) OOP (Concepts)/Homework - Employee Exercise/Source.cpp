#include <iostream>

using namespace std;

class clsEmployee
{
private:
	short _ID;
	string _FirstName;
	string _LastName;
	string _Title;
	string _Email;
	string _Phone;
	float _Salary;
	string _Department;

public:

	clsEmployee(short ID, string FirstName, string LastName, string Title, string Email, string Phone, float Salary, string Department)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Title = Title;
		_Email = Email;
		_Phone = Phone;
		_Salary = Salary;
		_Department = Department;
	}

	//all properties set and get, except read-only for the ID.
	short ID()
	{
		return _ID;
	}

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

	void SetTitle(string Title)
	{
		_Title = Title;
	}

	string GetTitle()
	{
		return _Title;
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string GetEmail()
	{
		return _Email;
	}

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	string GetPhone()
	{
		return _Phone;
	}

	void SetSalary(float Salary)
	{
		_Salary = Salary;
	}

	float GetSalary()
	{
		return _Salary;
	}

	void SetDepartment(string Department)
	{
		_Department = Department;
	}

	string GetDepartment()
	{
		return _Department;
	}

	//other methods
	string FullName()
	{
		return _FirstName + " " + _LastName;
	}

	void SendEmail(string Subject, string Body)
	{
		cout << "\nThe following message sent successfully to email: " << _Email << endl;
		cout << "Subject: " << Subject << endl;
		cout << "Body: " << Body << endl;
	}

	void SendSMS(string SMS)
	{
		cout << "\nThe following SMS sent successfully to phone: " << _Phone << endl;
		cout << SMS << endl;
		
	}

	void Print()
	{
		cout << "\nEmployee Info:" << endl;
		cout << "___________________________________________" << endl;
		cout << "ID        : " << _ID << endl;
		cout << "FirstName : " << _FirstName << endl;
		cout << "LastName  : " << _LastName << endl;
		cout << "FullName  : " << FullName() << endl;
		cout << "Title     : " << _Title << endl;
		cout << "Email     : " << _Email << endl;
		cout << "Phone     : " << _Phone << endl;
		cout << "Salary    : " << _Salary << endl;
		cout << "Department: " << _Department << endl;
		cout << "___________________________________________" << endl;
	}
};

int main()
{
	clsEmployee E1(10, "Ibrahim", "Mohamed", "Software Engineer", "ibrahim@example.com", "056-123-4567", 30000, "Software Solutions");

	E1.Print();
	E1.SendEmail("Hello", "How are you?");
	E1.SendSMS("How are you?");

	system("pause>0");
	return 0;
}