using namespace std;

#include <iostream>

struct stPiggyBank {
	float Pennies, Nickels, Dimes, Quarters, Dollars;
};

stPiggyBank ReadPiggyBankContent()
{
	stPiggyBank PiggyBank;

	cout << "Enter Pennies: ";
	cin >> PiggyBank.Pennies;
	cout << "Enter Nickels: ";
	cin >> PiggyBank.Nickels;
	cout << "Enter Dimes: ";
	cin >> PiggyBank.Dimes;
	cout << "Enter Quarters: ";
	cin >> PiggyBank.Quarters;
	cout << "Enter Dollars: ";
	cin >> PiggyBank.Dollars;

	return PiggyBank;
}

float CalculateTotalPennies(stPiggyBank PiggyBank)
{
	float TotalPennies = PiggyBank.Pennies + (PiggyBank.Nickels*5) + (PiggyBank.Dimes*10) + (PiggyBank.Quarters*25) + (PiggyBank.Dollars*100);

	return TotalPennies;
}

float CalculateTotalDollars(stPiggyBank PiggyBank)
{
	float TotalDollars = CalculateTotalPennies(PiggyBank) / 100;

	return TotalDollars;
}

void PrintTotalPenniesTotalDollars(float TotalPennies, float TotalDollars) {
	cout << "\n";
	cout << TotalPennies  <<" Pennies" << endl;
	cout << TotalDollars  <<" Dollars" << endl;
}

int main()
{
	stPiggyBank PiggyBank = ReadPiggyBankContent();

	float TotalPennies = CalculateTotalPennies(PiggyBank);
	float TotalDollars = CalculateTotalDollars(PiggyBank);

	PrintTotalPenniesTotalDollars(TotalPennies, TotalDollars);

	return 0;
}

