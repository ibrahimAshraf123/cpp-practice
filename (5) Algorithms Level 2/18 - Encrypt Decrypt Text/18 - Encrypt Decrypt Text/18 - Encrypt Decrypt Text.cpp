// 18 - Encrypt Decrypt Text.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

string ReadText(string Message)
{
	string Text;
	cout << Message << endl;
	cin >> Text;

	return Text;
}

string EncryptText(string Text)
{
	for (int i = 0; i < Text.size(); i++)
	{
		Text[i] = char(Text[i] + 2);
	}

	return Text;
}

string DecryptText(string EncryptedText)
{
	for (int i = 0; i < EncryptedText.size(); i++)
	{
		EncryptedText[i] = char(EncryptedText[i] - 2);
	}

	return EncryptedText;
}

int main()
{
	string Text = ReadText("Please enter text to encrypt:");

	string EncryptedText = EncryptText(Text);
	cout << "Encrypted Text:" << EncryptedText << endl;

	string DecryptedText = DecryptText(EncryptedText);
	cout << "Decrypted Text:" << DecryptedText << endl;


	return 0;
}
