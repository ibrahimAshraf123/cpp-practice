#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S1 = "Hello my name is Ibrahim Ashraf, I am a programmer.";

    //Prints the length of the string
    cout << S1.length() << endl;

    //Returns the letter at position 3
    cout << S1.at(3) << endl;

    //Adds @HiakilStudios to the end of string
    S1.append("@HiakilStudios");
    cout << S1 << endl;

    //inserts Ali at position 16
    S1.insert(16, " Ali");
    cout << S1 << endl;

    //Prints all the next 8 letters from position 16.
    cout << S1.substr(16, 8) << endl;

    //Adds one character to the end of the string
    S1.push_back('X');
	cout << S1 << endl;

    //Removes one character from the end of the string
    S1.pop_back();
    cout << S1 << endl;

    //Finds Ali in the string
    cout << S1.find("Ali") << endl;

    //Finds ali in the string
    cout << S1.find("ali") << endl;
    if (S1.find("ali") == S1.npos)
    {
		cout << "No position found" << endl;
    }

    //clears all string letters.
    S1.clear();
    cout << S1.length() << endl;
    cout << S1 << endl;

	return 0;
}