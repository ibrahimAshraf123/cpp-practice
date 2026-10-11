using namespace std;

#include <iostream>

float ReadPositiveNumber(string Message)
{
	float Number;
	do
	{
		cout << Message << endl;
		cin >> Number;

	} while (Number < 0.0);

	return Number;
}

float TotalBillAfterServiceAndTax(float BillValue)
{

	 BillValue = BillValue * 1.10;
	 BillValue = BillValue * 1.16;
	
	
	return BillValue;

}

void PrintTotalBill(float TotalBill)
{
	cout << "\nTotalBill = " << TotalBill << endl;
}

int main()
{
	float BillValue = ReadPositiveNumber("Please Enter Bill Value? ");

	PrintTotalBill(TotalBillAfterServiceAndTax(BillValue));

	return 0;
}
