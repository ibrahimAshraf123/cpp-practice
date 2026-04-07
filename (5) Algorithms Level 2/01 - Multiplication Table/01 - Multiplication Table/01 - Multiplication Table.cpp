#include <iostream>

using namespace std;

struct stTable
{
	int x[10]; //rows
	int y[10]; //columns
};


void PrintTitle(string Message)
{
	cout << "\t\t\t\t" << Message << "\t\t\t\t" << endl;
	cout << endl;
}

void PrintHeader( stTable Table)
{
	for (int i = 0; i <= 10; i++)
	{
		Table.x[i] = i;
		cout << Table.x[i] << "\t";
	}
	cout << endl;
	cout << "___________________________________________________________________________________\n";
}

void PrintMultiplicationTable(stTable Table)
{
	PrintTitle("Multiplication Table From 1 to 10");
	PrintHeader(Table);

	for (int i = 1; i <= 10; i++)
	{
		Table.y[i] = i;
		cout << Table.y[i];
		if(i<10)
			cout << "   |  ";
		else
			cout << "  |  ";
		for (int j = 1; j <= 10; j++)
		{
			Table.x[j] = j;
			cout << Table.x[j] * Table.y[i] << "\t";
		}

		cout << "\n";
	}
}

//void PrintAdditionTable(stTable Table)
//{
//	PrintTitle("Addition Table From 1 to 10");
//	PrintHeader(Table);
//
//	for (int i = 1; i <= 10; i++)
//	{
//		Table.y[i] = i;
//		cout << Table.y[i];
//		if (i < 10)
//			cout << "   |  ";
//		else
//			cout << "  |  ";
//		for (int j = 1; j <= 10; j++)
//		{
//			Table.x[j] = j;
//			cout << Table.x[j] + Table.y[i] << "\t";
//		}
//
//		cout << "\n";
//	}
//}
//
//void PrintSubtractionTable(stTable Table)
//{
//	PrintTitle("Subtraction Table From 1 to 10");
//	PrintHeader(Table);
//
//	for (int i = 1; i <= 10; i++)
//	{
//		Table.y[i] = i;
//		cout << Table.y[i];
//		if (i < 10)
//			cout << "   |  ";
//		else
//			cout << "  |  ";
//		for (int j = 1; j <= 10; j++)
//		{
//			Table.x[j] = j;
//			cout << Table.x[j] - Table.y[i] << "\t";
//		}
//
//		cout << "\n";
//	}
//}
//
//void PrintDivisionTable(stTable Table)
//{
//	PrintTitle("Division Table From 1 to 10");
//	PrintHeader(Table);
//
//	for (int i = 1; i <= 10; i++)
//	{
//		Table.y[i] = i;
//		cout << Table.y[i];
//		if (i < 10)
//			cout << "   |  ";
//		else
//			cout << "  |  ";
//		for (int j = 1; j <= 10; j++)
//		{
//			Table.x[j] = j;
//			cout << round(double(Table.x[j]) / Table.y[i]) << "\t";
//		}
//
//		cout << "\n";
//	}
//}

int main()
{
	stTable MulTable{};
	
	PrintMultiplicationTable(MulTable);


	return 0;
}