#include <iostream>

using namespace std;

class clsPerson
{
private:
	short _ID;
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
	
public:

	clsPerson(short ID, string FirstName, string LastName, string Email, string Phone)
	{
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
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

	string FirstName()
	{
		return _FirstName;
	}

	void SetLastName(string LastName)
	{
		_LastName = LastName;
	}

	string LastName()
	{
		return _LastName;
	}

	void SetEmail(string Email)
	{
		_Email = Email;
	}

	string Email()
	{
		return _Email;
	}

	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}

	string Phone()
	{
		return _Phone;
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
		cout << "\nInfo:" << endl;
		cout << "___________________________________________" << endl;
		cout << "ID        : " << _ID << endl;
		cout << "FirstName : " << _FirstName << endl;
		cout << "LastName  : " << _LastName << endl;
		cout << "FullName  : " << FullName() << endl;
		cout << "Email     : " << _Email << endl;
		cout << "Phone     : " << _Phone << endl;
		cout << "___________________________________________" << endl;
	}
};

//inheritance
class clsEmployee : public clsPerson
{
private:
	string _Title;
	string _Department;
	float _Salary;


public:
	clsEmployee(short ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary)
		: clsPerson(ID, FirstName, LastName, Email, Phone)
	{
		_Title = Title;
		_Department = Department;
		_Salary = Salary;
	}

	//Set & Get properties
	string Title()
	{
		return _Title;
	}
	
	void SetTitle(string Title)
	{
		_Title = Title;
	}

	string Department()
	{
		return _Department;
	}

	void SetDepartment(string Department)
	{
		_Department = Department;
	}

	float Salary()
	{
		return _Salary;
	}

	void SetSalary(float Salary)
	{
		_Salary = Salary;
	}

	//Function Overriding
	void Print()
	{
		cout << "\nInfo:" << endl;
		cout << "___________________________________________" << endl;
		cout << "ID        : " << ID() << endl;
		cout << "FirstName : " << FirstName() << endl;
		cout << "LastName  : " << LastName() << endl;
		cout << "FullName  : " << FullName() << endl;
		cout << "Email     : " << Email() << endl;
		cout << "Phone     : " << Phone() << endl;
		cout << "Title     : " << _Title << endl;
		cout << "Department: " << _Department << endl;
		cout << "Salary    : " << _Salary << endl;
		cout << "___________________________________________" << endl;
	}
};

//multi-level inheritance
class clsDeveloper : public clsEmployee
{
private:
	string _MainProgrammingLanguage;
public:
	clsDeveloper(short ID, string FirstName, string LastName, 
		string Email, string Phone, string Title, string Department, float Salary, string MainProgrammingLanguage)
		: clsEmployee(ID, FirstName, LastName, Email, Phone, Title, Department, Salary)
	{
		_MainProgrammingLanguage = MainProgrammingLanguage;
	}

	//set & get properties
	string MainProgrammingLanguage()
	{
		return _MainProgrammingLanguage;
	}

	void SetMainProgrammingLanguage(string MainProgrammingLanguage)
	{
		_MainProgrammingLanguage = MainProgrammingLanguage;
	}

	//Function Override
	void Print()
	{
		cout << "\nInfo:" << endl;
		cout << "___________________________________________" << endl;
		cout << "ID                       : " << ID() << endl;
		cout << "FirstName                : " << FirstName() << endl;
		cout << "LastName                 : " << LastName() << endl;
		cout << "FullName                 : " << FullName() << endl;
		cout << "Email                    : " << Email() << endl;
		cout << "Phone                    : " << Phone() << endl;
		cout << "Title                    : " << Title() << endl;
		cout << "Department               : " << Department() << endl;
		cout << "Salary                   : " << Salary() << endl;
		cout << "Main Programming Language: " << _MainProgrammingLanguage << endl;
		cout << "___________________________________________" << endl;
	}
};

int main()
{
	clsDeveloper Dev1(10, "Ibrahim", "Mohamed",  "ibrahim@example.com", "056-123-4567", "CEO", "Management", 125000, "C++");

	Dev1.Print();
	Dev1.SendEmail("Hello", "How are you?");
	Dev1.SendSMS("How are you?");


	system("pause>0");
	return 0;
}