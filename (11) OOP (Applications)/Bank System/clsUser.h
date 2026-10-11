#pragma once
#include <iostream>
#include "clsPerson.h";
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h";

using namespace std;

class clsUser : public clsPerson
{

private:
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedforDelete = false;

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector<string> vUserData;
		vUserData = clsString::Split(Line, Seperator);

		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));
	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string stUserRecord = "";
		stUserRecord += User.FirstName + Seperator;
		stUserRecord += User.LastName + Seperator;
		stUserRecord += User.Email + Seperator;
		stUserRecord += User.Phone + Seperator;
		stUserRecord += User._UserName + Seperator;
		stUserRecord += User._Password + Seperator;
		stUserRecord += to_string(User._Permissions);

		return stUserRecord;
	}

	static vector<clsUser> _LoadUsersDataFromFile()
	{
		vector<clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in); //read mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser Client = _ConvertLineToUserObject(Line);
				vUsers.push_back(Client);
			}


			MyFile.close();
		}

		return vUsers;
	}

	static void _SaveUsersDataToFile(vector<clsUser> vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out); //overwrite mode

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsUser U : vUsers)
			{
				if (U.MarkedForDelete() == false)
				{
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app); //append mode

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsUser> vUsers;
		vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U.UserName == _UserName)
			{
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(vUsers);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

public:
	clsUser(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string UserName, string Password,
		int Permissions) : 
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkedForDelete()
	{
		return _MarkedforDelete;
	}

	string GetUserName()
	{
		return _UserName;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	string GetPassword()
	{
		return _Password;
	}

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	int GetPermissions()
	{
		return _Permissions;
	}

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	static clsUser Find(string UserName)
	{
		vector<clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in); //read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	};

	static clsUser Find(string UserName, string Password)
	{
		vector<clsUser> vUsers;

		fstream MyFile;
		MyFile.open("Users.txt", ios::in); //read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName && User.Password == Password)
				{
					MyFile.close();
					return User;
				}
				vUsers.push_back(User);
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	};

	static bool IsUserExist(string UserName)
	{
		clsUser User1 = clsUser::Find(UserName);

		return (!User1.IsEmpty());
	};

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedUserNameExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
		{
			return enSaveResults::svFailedEmptyObject;

		}

		case enMode::UpdateMode:
		{
			_Update();

			return enSaveResults::svSucceeded;
			break;
		}

		case enMode::AddNewMode:
		{
			if (clsUser::IsUserExist(_Password))
			{
				return enSaveResults::svFailedUserNameExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}
			break;
		}
		}

	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete()
	{

		//delete object from file
		vector<clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();


		for (clsUser& U : _vUsers)
		{
			if (U.UserName == _UserName)
			{
				U._MarkedforDelete = true;
				break;
			}
		}

		_SaveUsersDataToFile(_vUsers);


		*this = _GetEmptyUserObject(); //delete object from memory

		return true;
	}

	static vector<clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	enum enPermissions { eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64 };

	bool CheckAccessPermission(enPermissions Permission)
	{
		if ((this->Permissions == enPermissions::eAll))
			return true;

		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;
	}

};

