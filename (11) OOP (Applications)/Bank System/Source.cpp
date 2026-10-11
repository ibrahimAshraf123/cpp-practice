#include <iostream>
#include "clsLoginScreen.h";

using namespace std;

int main()
{
	//clsMainScreen::ShowMainMenu();
	
	while (true)
	{
		clsLoginScreen::ShowLoginScreen();
	}
	
	return 0;
}