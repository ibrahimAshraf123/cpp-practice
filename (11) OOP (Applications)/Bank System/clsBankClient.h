#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h";
#include "clsString.h";

using namespace std;

class clsBankClient : public clsPerson
{
private:
	
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;
	}

	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); //read mode

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);
			}


			MyFile.close();
		}

		return vClients;
	}

	static void _SaveClientsDataToFile(vector<clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out); //overwrite mode

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsBankClient C : vClients)
			{
				if (C.MarkedForDelete() == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app); //append mode

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientsDataToFile(_vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

public:
	
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) 
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	};

	//get & set properties
	string AccountNumber()
	{
		return _AccountNumber;
	};

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	};

	string GetPinCode()
	{
		return _PinCode;
	};

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	};

	float GetAccountBalance()
	{
		return _AccountBalance;
	};

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	//methods
	/*
		No UI related code inside object
	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n---------------";
		cout << "\nFirst Name    : " << FirstName;
		cout << "\nLast Name     : " << LastName;
		cout << "\nFull Name     : " << FullName();
		cout << "\nEmail         : " << Email;
		cout << "\nPhone         : " << Phone;
		cout << "\nAccountNumber : " << AccountNumber();
		cout << "\nPinCode       : " << PinCode;
		cout << "\nAccountBalance: " << AccountBalance;
		cout << "\n---------------";
		cout << "\n";

	}*/

	static clsBankClient Find(string AccountNumber)
	{
		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); //read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	};

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector<clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); //read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	};

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		return (!Client1.IsEmpty());
	};

	enum enSaveResults { svFailedEmptyObject = 0, svSucceeded = 1, svFailedAccountNumberExists = 2 };

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
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFailedAccountNumberExists;
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

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		
		//delete object from file
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();


		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}
		
		_SaveClientsDataToFile(_vClients);
		
		
		*this = _GetEmptyClientObject(); //delete object from memory

		return true;
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient> vClients = _LoadClientsDataFromFile();

		double TotalBalances = 0;

		for (clsBankClient C : vClients)
		{
			TotalBalances += C.AccountBalance;
		}

		return TotalBalances;
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
		}
	}
};

