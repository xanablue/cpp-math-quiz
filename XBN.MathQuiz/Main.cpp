// Xana Navoichick - Assignment 5
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() 
{
	// Setting file paths
	string readfilepath = "C:\\Users\\Public\\mathproblems.txt";
	string writefilepath = "QuizResults.txt";

	// Initializing streams
	ifstream ifs(readfilepath);
	ofstream ofs(writefilepath);

	// Preparing string to hold a single read line
	string line;

	// Creating vector for holding multiple read lines
	vector <string> lines;
	while (getline(ifs, line))
	{
		lines.push_back(line);
	}

	// Setting up random generator
	srand(time(NULL));

	// Creating a variable to hold the user's answer
	int userAnswer;

	// Begin writing to console
	cout << "Welcome to the Math Quiz!\n";

	// For loop that generates a new random line and accepts the user's answer
	for (int i = 0; i < 3; i++)
	{
		// Generate random question and accept input
		int randomNumber = rand() % lines.size();
		cout << "\nQuestion " << (i + 1) << ": " << lines[randomNumber] << " = \n";
		cout << "Enter your answer: ";
		cin >> userAnswer;

		// Output question and answer to file
		ofs << lines[randomNumber] << " = " << userAnswer << "\n";
	}

	// Save confirmation
	cout << "\nResults saved to " << writefilepath;
	
	// Closing streams
	ifs.close();
	ofs.close();
	
	(void)_getch();
	return 0;
}
