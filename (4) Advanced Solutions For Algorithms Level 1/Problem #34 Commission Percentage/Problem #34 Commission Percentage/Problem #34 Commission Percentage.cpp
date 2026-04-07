using namespace std;

#include <iostream>

float ReadTotalSales()
{
	float TotalSales;
	cout << "Enter Total Sales:\n";
	cin >> TotalSales;

	return TotalSales;
}

float GetCommissionPercentage(float TotalSales)
{
	if (TotalSales > 1000000)
		return 0.01;
	else if (TotalSales > 500000)
		return 0.02;
	else if (TotalSales > 100000)
		return 0.03;
	else if (TotalSales > 50000)
		return 0.05;
	else
		return 0.0;
}

float CalculateCommission(float TotalSales, float CommissionPercentage)
{
	float Commission = TotalSales * CommissionPercentage;
	return Commission;
}

int main()
{
	float TotalSales = ReadTotalSales();
	float CommissionPercentage = GetCommissionPercentage(TotalSales);

	cout << "\nResults: " << endl;
	cout << "Total Sales = " << TotalSales << endl;
	cout << "Commission Percentage = " << CommissionPercentage << endl;
	cout << "Commission = " << CalculateCommission(TotalSales, CommissionPercentage) << endl;

	return 0;
}
