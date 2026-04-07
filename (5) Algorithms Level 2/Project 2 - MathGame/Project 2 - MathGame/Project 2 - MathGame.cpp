// Project 2 - MathGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

using namespace std;

enum enQuestionsLevel { Easy = 1, Medium = 2, Hard = 3, Mix = 4 };

enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, Mix = 5 };

struct stQuizz
{
	int HowManyQuestions;
	enQuestionsLevel QuestionsLevel;
	enOperationType OperationType;
	int RightAnswers;
	int WrongAnswers;
	bool Pass;

};

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

void ResetScreen()
{
	system("color 0F");
	system("CLS");
}

int ReadHowManyQuestions()
{
	int HowManyQuestions;
	cout << "\nHow many questions do you want to answer? ";
	cin >> HowManyQuestions;

	return HowManyQuestions;
}

enQuestionsLevel ReadQuizzLevel()
{
	int QuizzLevel;
	do
	{

		cout << "\nEnter questions level? [1]:Easy, [2]:Medium, [3]:Hard? ";
		cin >> QuizzLevel;

	} while (QuizzLevel < 1 || QuizzLevel > 3);

	return (enQuestionsLevel)QuizzLevel;
}

enOperationType ReadOpType()
{
	int OpType;
	do
	{
		cout << "\nEnter operation type? [1]:Add, [2]:Sub, [3]:Mul, [4]:Div, [5]:Mix? ";
		cin >> OpType;

	} while (OpType < 1 || OpType > 5);

	return (enOperationType)OpType;
}

string QuizzLevelName(stQuizz Quizz)
{
	switch (Quizz.QuestionsLevel)
	{
	case Easy:
		return "Easy";
	case Medium:
		return "Medium";
	case Hard:
		return "Hard";
	case Mix:
		return "Mix";
	}
}

string OpTypeName(stQuizz Quizz)
{
	switch (Quizz.OperationType)
	{
	case Add:
		return "Addition";
	case Sub:
		return "Subtraction";
	case Mul:
		return "Multiplication";
	case Div:
		return "Division";
	case Mix:
		return "Mix";
	}
}

void GenerateQuestion(stQuizz Quizz)
{


}

void ShowFinalResults(stQuizz Quizz)
{

	int HowManyQuestions = ReadHowManyQuestions();
	string QuizzLevel = QuizzLevelName(Quizz);
	string OpType = OpTypeName(Quizz);
	int RightAnswersAmount = Quizz.RightAnswers;
	int WrongAnswersAmount = Quizz.WrongAnswers;
	bool FinalResult = Quizz.Pass;

	cout << "\n";
	cout << "____________________________________\n";
	cout << "        Final Result is: " << FinalResult		<< endl;
	cout << "____________________________________\n";
	cout << "Number of questions: " << HowManyQuestions		<<endl;
	cout << "Questions level: "		<< QuizzLevel			<<endl;
	cout << "Operation Type: "		<< OpType				<<endl;
	cout << "# of right answers: "	<< RightAnswersAmount	<< endl;
	cout << "# of wrong answers: "	<< WrongAnswersAmount	<<endl;
	cout << "____________________________________\n";
	cout << "Do you want to play again? Y/N? " << endl;
	cout << "____________________________________\n";
}

void StartQuizz()
{
	ResetScreen();

	stQuizz Quizz{};
	Quizz.HowManyQuestions = ReadHowManyQuestions();
	Quizz.QuestionsLevel = ReadQuizzLevel();
	Quizz.OperationType = ReadOpType();
	


}

int main()
{
	srand((unsigned)time(NULL));

  
	return 0;
}
