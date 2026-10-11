using namespace std;

#include <iostream>

struct stTaskDuration {
	float Days;
	float Hours;
	float Minutes;
	float Seconds;
};

float ReadPositiveNumber(string Message)
{
	int N;

	do {
		cout << Message << endl;
		cin >> N;
	} while (N < 0);

	return N;
}

stTaskDuration ReadTaskDuration()
{
	stTaskDuration TaskDuration;

	TaskDuration.Days = ReadPositiveNumber("Please enter number of Days: ");
	TaskDuration.Hours = ReadPositiveNumber("Please enter number of Hours: ");
	TaskDuration.Minutes = ReadPositiveNumber("Please enter number of Minutes: ");
	TaskDuration.Seconds = ReadPositiveNumber("Please enter number of Seconds: ");

	return TaskDuration;
}

float TaskDurationInSeconds(stTaskDuration TaskDuration)
{
	float TaskDurationInSeconds = (TaskDuration.Days * 24 * 60 * 60) + (TaskDuration.Hours * 60 * 60) + (TaskDuration.Minutes * 60) + TaskDuration.Seconds;

	return TaskDurationInSeconds;
}


int main()
{

	cout << "Task Duration In Seconds = " << TaskDurationInSeconds(ReadTaskDuration()) << endl;


	return 0;
}
