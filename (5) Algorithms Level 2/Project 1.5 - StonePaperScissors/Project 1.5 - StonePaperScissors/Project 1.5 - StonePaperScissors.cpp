// Project 1.5 - StonePaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice PlayerChoice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;

};

struct stGameResults
{
	short GameRounds = 0;
	short PlayerWinTimes = 0;
	short ComputerWinTimes = 0;
	short DrawTimes = 0;
	enWinner FinalWinner;
	string WinnerName;
};

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

enGameChoice ComputerChoice()
{
	short ComChoice = RandomNumber(1, 3);

	return (enGameChoice)ComChoice;
}

enWinner GetRoundWinner(stRoundInfo Round)
{
	if (Round.PlayerChoice == Round.ComputerChoice)
		return enWinner::Draw;

	if ((Round.PlayerChoice == Stone && Round.ComputerChoice == Scissors) ||
		(Round.PlayerChoice == Paper && Round.ComputerChoice == Stone) ||
		(Round.PlayerChoice == Scissors && Round.ComputerChoice == Paper))
	{
		return enWinner::Player;
	}
	else
	{
		return enWinner::Computer;
	}
}

enWinner GetFinalWinner(short PlayerWinTimes, short ComputerWinTimes)
{
	if (PlayerWinTimes == ComputerWinTimes)
		return enWinner::Draw;
	if (PlayerWinTimes > ComputerWinTimes)
		return enWinner::Player;
	else
		return enWinner::Computer;

}

string ChoiceName(enGameChoice Choice)
{
	string arrGameChoices[3] = { "Stone","Paper","Scissors" };
	return arrGameChoices[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player:
		system("color 2F"); //turn screen to green
		break;

	case enWinner::Computer:
		system("color 4F"); //turn screen to red
		cout << "\a";
		break;

	default:
		system("color 6F"); //turn screen to yellow
		break;

	}
		
}

string WinnerName(enWinner Winners)
{
	string arrGameWinners[3] = { "Player","Computer","Draw" };
	return arrGameWinners[Winners - 1];
}

enGameChoice ReadPlayerChoice()
{
	short PlayerChoice;
	do
	{
		cout << "Enter your choice? [1]:Stone, [2]:Paper, [3]Scissors ? ";
		cin >> PlayerChoice;
	} while (PlayerChoice < 1 || PlayerChoice > 3);
	

	return (enGameChoice)PlayerChoice;
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n";
	cout << "__________Round["  << RoundInfo.RoundNumber << "]__________" << endl;
	cout << "Player   Choice: " << ChoiceName(RoundInfo.PlayerChoice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round winner   :"  << RoundInfo.WinnerName << endl;
	cout << "____________________________" << endl;

	SetWinnerScreenColor(RoundInfo.Winner);
}

stGameResults FillGameResults(short RoundsAmount, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes)
{
	stGameResults Game;

	Game.GameRounds = RoundsAmount;
	Game.PlayerWinTimes = PlayerWinTimes;
	Game.ComputerWinTimes = ComputerWinTimes;
	Game.DrawTimes = DrawTimes;
	Game.FinalWinner = GetFinalWinner(PlayerWinTimes, ComputerWinTimes);
	Game.WinnerName = WinnerName(Game.FinalWinner);

	return Game;

}

stGameResults PlayGame(short RoundsAmount)
{
	stRoundInfo Round;
	//win counters
	short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= RoundsAmount; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] Begins: \n";
		Round.RoundNumber = GameRound;
		Round.ComputerChoice = ComputerChoice();
		Round.PlayerChoice = ReadPlayerChoice();
		Round.Winner = GetRoundWinner(Round);
		Round.WinnerName = WinnerName(Round.Winner);

		//increase win counters
		if (Round.Winner == Player)
			PlayerWinTimes++;
		else if (Round.Winner == Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;
		PrintRoundResults(Round);
	}
	return FillGameResults(RoundsAmount, PlayerWinTimes, ComputerWinTimes, DrawTimes);
}

string Tabs(short TabsNum)
{
	string Tab = "";
	for (int i = 0; i <= TabsNum; i++) {
		Tab += "\t";
	}
	return Tab;

}

void ShowGameOverScreen()
{
	cout << Tabs(2) << "__________________________________" << endl;
	cout << Tabs(2) << "_____________GAME OVER____________" << endl;
	cout << Tabs(2) << "__________________________________" << endl;

}

void ShowGameResults(stGameResults Game)
{
	cout << Tabs (2)<< "\n";
	cout << Tabs(2) << "__________[Game Results]__________" << endl;
	cout << Tabs(2) << "Game Rounds  : " << Game.GameRounds << endl;
	cout << Tabs(2) << "Player   Wins: " << Game.PlayerWinTimes << endl;
	cout << Tabs(2) << "Computer Wins: " << Game.ComputerWinTimes << endl;
	cout << Tabs(2) << "Draw Times   : " << Game.DrawTimes << endl;
	cout << Tabs(2) << "Final Winner : " << Game.WinnerName << endl;
	cout << Tabs(2) << "__________________________________" << endl;

	SetWinnerScreenColor(Game.FinalWinner);
}

short ReadRoundsAmount()
{
	short Rounds;
	cout << "How many rounds?" << endl;
	cin >> Rounds;

	return Rounds;
}

void ResetScreen()
{
	system("CLS");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		ResetScreen();
		stGameResults Game = PlayGame(ReadRoundsAmount());
		ShowGameOverScreen();
		ShowGameResults(Game);

		cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;


	} while (toupper(PlayAgain) == 'Y');
	
}


int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}
