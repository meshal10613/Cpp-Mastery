#include <iostream>
using namespace std;

int main()
{
	//? Quiz Game
	string questions[] = {
		"1. What year was C++ created? ",
		"2. Who invented C++? ",
		"3. What is the predecessor of C++? ",
	};
	string options[][4] = {
		{"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
		{"A. Guido Van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. Mark Zuckerburg"},
		{"A. C", "B. JavaScript", "C. C#", "D. Python"}};
	char answerKey[] = {'C', 'B', 'A'};
	int size = sizeof(questions) / sizeof(questions[0]);
	char guess;
	int score = 0;

	cout << "============================\n";
	cout << "       C++ QUIZ GAME\n";
	cout << "============================\n\n";

	for (int i = 0; i < size; i++)
	{
		cout << questions[i] << endl;
		for (int j = 0; j < sizeof(options[i]) / sizeof(options[i][0]); j++)
		{
			cout << options[i][j] << endl;
		}
		cout << endl;

		// Validate user input
		while (true)
		{
			cout << "\nChoose your answer (A, B, C, or D): ";

			if (!(cin >> guess))
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input! Please enter A, B, C, or D.\n";
				continue;
			}

			guess = toupper(static_cast<unsigned char>(guess));

			if (guess == 'A' || guess == 'B' ||
				guess == 'C' || guess == 'D')
			{
				break;
			}

			cout << "Invalid choice! Please enter A, B, C, or D.\n";
		}

		if (guess == answerKey[i])
		{
			cout << "\033[32mCorrect" << endl;
			score++;			//* Green
			cout << "\033[37m"; //* White
			system("pause");
			system("CLS");
		}
		else
		{
			cout << "\033[31mWrong" << endl; //* Red
			cout << "\033[37mAnswer: " << answerKey[i] << endl;
			system("pause");
			system("CLS");
		}

		// cout << "Score: " << score << "/" << i + 1 << "\n";
		// cout << "----------------------------\n";
	}

	// Display final results
	double percentage = (static_cast<double>(score) / size) * 100;

	cout << "\n============================\n";
	cout << "        QUIZ RESULTS\n";
	cout << "============================\n";
	cout << "Total Questions: " << size << endl;
	cout << "Correct Answers: " << score << endl;
	cout << "Wrong Answers:   " << size - score << endl;
	cout << "Final Score:     " << percentage << "%\n";

	if (score == size)
	{
		cout << "\033[32mExcellent! Perfect score!\033[0m\n";
	}
	else if (score >= size / 2.0)
	{
		cout << "Good job! Keep practicing!\n";
	}
	else
	{
		cout << "Keep learning and try again!\n";
	}

	cout << "============================\n";

	return 0;
}