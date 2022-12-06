#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <time.h>
using namespace std;

/****	GAME_DATA	****/
// GAME_DATA[index[question, solution, A, B, C, D]]
const vector<vector<string>> GAME_DATA = {
	{"Software engineering is a field that encompasses designing, writing, testing, debugging, documenting, modifying, and maintaining computer programs.", "True", "True", "False"},
	{"In programming, the terms \"line\" and \"statement\" always mean the same thing.", "False", "True", "False"},
	{"In C++, key words are written in all lowercase letters.", "True", "True", "False"},
	{"The preprocessor executes after the compiler.","False", "True", "False"},
	{"Machine language is an example of a high-level language.", "False", "True", "False"},
	{"Programming style refers to the way a programmer uses elements such as identifiers, spaces, and blank lines.", "True", "True", "False"},
	{"RAM is a volatile type of memory that is used for temporary storage.", "True", "True", "False"},
	{"An input device can sometimes be an output device too.", "True", "True", "False"},
	{"C++ is a specific purpose programming language.", "False", "True", "False"},
	{"Every C++ program must have a main function.", "True", "True", "False"},
	{"In C++, you are required to name your variables so they indicate the purpose they will be used for.", "False", "True", "False"},
	{"There are eight bits in one byte. Each bit stands for a binary digit. A binary digit is 0 or 1.", "True", "True", "False"},
	{"Internally, the CPU consists of the __________.", "Control Unit and an Arithmetic Logic Unit (ALU)", "machine code", "a hard drive and a soft drive", "Control Unit and an Arithmetic Logic Unit (ALU)", "Search Unit and Computing Unit"},
	{"In the following statement, the characters Hello! are a(n):\n\tcout << \"Hello!\";", "string literal", "object", "string literal", "comment", "variable"},
	{"The _______ causes the content of another file to be inserted into a program.", "#include directive", "#include directive", "cout object", "semicolon (;)", "double slash (//)"},
	{"Which of the following must be included in any program that uses the cout object?", "the header file iostream", "opening and closing braces", "a namespace", "comments", "the header file iostream"},
	{"In a cout statement, which of the following will advance the output position to the beginning of the next line?", "None of these", "cout << /n", "cout << endl << \\n;", "cout << \\n", "None of these"},
	{"The CPU's control unit retrieves the next instruction in a sequence of program instructions from main memory in the _______ stage.", "fetch", "fetch", "execute", "decode", "portability"},
	{"A variable definition tells the computer...", "the variable's name, the type of data it will hold, and its value.", "the variable's name and its value", " the variable's data type and its value", "the variable's name, the type of data it will hold, and its value.", "None of these"},
	{"Which of the following is not a valid C++ identifier?", "1user", "employee_number", "April2018", "_1user", "1user"},
	{"A(n) _______ is a set of instructions that the computer follows to solve a problem.", "program", "linker", "operator", "compiler", "program"},
	{"In memory, C++ automatically places a(n) ______ at the end of string literals which ______.", "null terminator, marks the end of the string", "null terminator, marks the end of the string", "bracket, marks the end of the string", "\\n, indicates an escape sequence", "semicolon, indicates the end of the statement"},
	{"What is the value of number after the following statements execute?\nint number;\nnumber = 18 / 4;", "4", "unknown", "4", "4.5", "0"},
	{"Programs are often referred to as hardware.", "False", "True", "False"},
	{"Pseudocode is a for of a program statement that will always evaluate to \"false.\"", "False", "True", "False"}
};

/**** CONSTANT VARIABLES ****/
const string TEAM_NAME = "RGB";
const double MAX_ALLOWED = 20.00;
const int MAX_INDEX = GAME_DATA.size() - 1;
const int basePoints = 150;

/**** FUNCTION PROTOTYPES ****/
void menu(
	bool& continueProgram,
	double& balance,
	int& numGamesPlayed,
	int& totalCorrectAnswers,
	int& totalWrongAnswers,
	int& totalPointsEarned,
	int& totalCreditsLost,
	string& userName
);
void setBalance(double& balance);
void game(
	double& balance,
	int& totalCorrectAnswers,
	int& totalWrongAnswers,
	int& totalPointsEarned,
	int& totalCreditsLost
);
void addPlayerData(
	double& balance,
	int& numGamesPlayed,
	int& totalCorrectAnswers,
	int& totalWrongAnswers,
	int& totalPointsEarned,
	int& totalCreditsLost,
	string& userName
);
void getPlayerData();

/****	MAIN	****/
int main() {
	bool continueProgram = true;
	double balance = 0.00;
	int numGamesPlayed = 0;
	int totalCorrectAnswers = 0;
	int totalWrongAnswers = 0;
	int totalPointsEarned = 0;
	int totalCreditsLost = 0;
	string userName;

	do {
		menu(
			continueProgram,
			balance,
			numGamesPlayed,
			totalCorrectAnswers,
			totalWrongAnswers,
			totalPointsEarned,
			totalCreditsLost,
			userName
		);
	} while (continueProgram);

	return 0;
}

void menu(
	bool& continueProgram,
	double& balance,
	int& numGamesPlayed,
	int& totalCorrectAnswers,
	int& totalWrongAnswers,
	int& totalPointsEarned,
	int& totalCreditsLost,
	string& userName
) {
	int selection;

	/**** MENU ****/
	cout << "\n*** " << TEAM_NAME << " ***\n";
	cout << "\n*** MAIN MENU ***\n";
	cout << "\nPlease select one of the following:\n";
	cout << "\n\t1: Display my available credit";
	cout << "\n\t2: Add credits to my account";
	cout << "\n\t3: Play The Guessing Game";
	cout << "\n\t4: Display my statistics";
	cout << "\n\t5: Save my statistics";
	cout << "\n\t6: Exit\n";
	cout << "\nSelection: ";
	cin >> selection;

	/**** DECISION LOGIC ****/
	switch (selection) {
	case 1:
		cout << "\n=> Your available balance is $";
		cout << setprecision(2) << fixed << balance << "\n";
		system("pause");
		break;
	case 2:
		setBalance(balance);
		system("pause");
		break;
	case 3:
		if (balance <= 0) {
			cout << "\nAccount Balance Insufficient";
			cout << "\nPlease add credits to play the game.\n\n";
			system("pause");
			break;
		}
		else {
			game(balance, totalCorrectAnswers, totalWrongAnswers, totalPointsEarned, totalCreditsLost);
			numGamesPlayed++;
			break;
		}
	case 4:
		getPlayerData();
		break;
	case 5:
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nPlease enter your name: \n";
		getline(cin, userName);
		addPlayerData(balance, numGamesPlayed, totalCorrectAnswers, totalWrongAnswers, totalPointsEarned, totalCreditsLost, userName);
		break;
	case 6:
		cout << "\n\tOption 6\n";
		continueProgram = false;
		break;
	default:
		cout << "\n\tPlease make a valid selection.\n";
		system("pause");
	}

	cin.clear();
	cin.ignore(1000, '\n');
}

void setBalance(double& balance) {
	double amount = 0.00;
	cout << "\n=> Please enter the amount you would like to add:\n";
	cin >> amount;

	if (amount < 0.00) {
		cout << "\n=>Error: Amount entered must be greater than $0.\n";
	}
	else if (amount + balance > MAX_ALLOWED) {
		cout << "\n=> Error: Maximum allowable credit is $20.00.";
		cout << "\n=> Your available balance is $";
		cout << setprecision(2) << fixed << balance << "\n";
	}
	else {
		balance += amount;
		cout << "\n=> Your available balance is $";
		cout << setprecision(2) << fixed << balance << "\n";
	}
}

void game(
	double& balance,
	int& totalCorrectAnswers,
	int& totalWrongAnswers,
	int& totalPointsEarned,
	int& totalCreditsLost
) {
	bool continueGame = true;
	int score = 0;
	int streak = 0;
	int multiplier = 1;
	int rounds = 0;

	cout << "\nWelcome to Who Wants to be a Programmer? C++ Edition\n";
	cout << "\nThe rules are simple:\n";
	cout << "\n1. Read the question.\n";
	cout << "\n2. Enter the number corresponding to the answer you've selected.\n";
	cout << "\n3. Win Big!\n";
	cout << "\nHow many rounds would you like to play?\n";
	cin >> rounds;
	int currentRound = 0;
	if (rounds <= 25 && rounds != 0) {
		cout << "\nLet's play, WHO WANTS TO BE A PROGRAMMER?\n";
		while (continueGame) {
			cout << "\nROUND: " << ++currentRound << '\n';
			srand(time(0));
			int randNum = rand() % (MAX_INDEX + 1);
			string question = GAME_DATA[randNum][0];
			string correctAnswer = GAME_DATA[randNum][1];

			cout << "\n" << currentRound << ") " << question << endl;

			// Print multiple choice 
			for (int i = 2; i != GAME_DATA[randNum].size(); i++) {
				switch (i) {
				case 2:
					cout << "\n1. " << GAME_DATA[randNum][i];
					break;
				case 3:
					cout << "\n2. " << GAME_DATA[randNum][i];
					break;
				case 4:
					cout << "\n3. " << GAME_DATA[randNum][i];
					break;
				case 5:
					cout << "\n4. " << GAME_DATA[randNum][i];
					break;
				default:
					cout << "\nOOF... We messed up. Have some points on us!\n";
				}
			}

			int playerSelection;

			cout << "\n\nSelection: ";
			cin >> playerSelection;

			if (playerSelection != 0) { // if 0, will always result in correct answer
				playerSelection += 1;

				if (playerSelection < GAME_DATA[randNum].size()) {
					if (GAME_DATA[randNum][playerSelection] == GAME_DATA[randNum][1]) {
						cout << "\nCORRECT!!!\n";
						score += basePoints * multiplier;
						totalPointsEarned += basePoints * multiplier;
						totalCorrectAnswers++;
						if (streak == 3) {
							cout << "\n3 IN A ROW! KEEP GOING!!!\n";
							multiplier += 1;
						}
						else if (streak == 6) {
							cout << "\n6 IN A ROW! YOU'RE ON FIRE!!!\n";
							multiplier += 2;
						}

						streak++;
					}
					else {
						cout << "\nSORRY! The correct answer is: " << GAME_DATA[randNum][1] << endl;
						streak = 0;
						multiplier = 1;
						balance -= 2;
						totalCreditsLost += 2;
						totalWrongAnswers += 1;
						cout << "\nRemaining Balance: " << balance << '\n';
						if (balance <= 0) {
							balance = 0;
							cout << "\nGAME OVER\n";
							cout << "\nAdd more credits to play again!\n";
							continueGame = false;
						}
					}
				}
				else {
					cout << "\nNot a valid selection.\n";
				}
			}
			else {
				cout << "\nNot a valid selection.\n";
			}
			cin.clear();
			cin.ignore(1000, '\n');
			if (rounds == 1) {
				continueGame = false;
			}
			else rounds--;
		}
		cout << "\n\nScore: " << score << '\n';
	}
	else {
		cout << "\nPlease enter a number from 1 - 25\n";
	}
}

void addPlayerData(
	double& balance,
	int& numGamesPlayed,
	int& totalCorrectAnswers,
	int& totalWrongAnswers,
	int& totalPointsEarned,
	int& totalCreditsLost,
	string& userName
) {

	ofstream playerStatsFile;
	playerStatsFile.open("PlayerStats.txt");
	if (playerStatsFile.is_open()) {
		playerStatsFile << __DATE__ << '\t';
		playerStatsFile << __TIME__ << '\n';
		playerStatsFile << userName << '\n';
		playerStatsFile << "Available Credit: " << balance << '\n';
		playerStatsFile << "Games Played: " << numGamesPlayed << '\n';
		playerStatsFile << "Correct Responses: " << totalCorrectAnswers << '\n';
		playerStatsFile << "Missed Responses: " << totalWrongAnswers << '\n';
		playerStatsFile << "Points Earned: " << totalPointsEarned << '\n';
		playerStatsFile << "Money Lost: " << totalCreditsLost << '\n';
		cout << "\nYour stats have been saved!\n";
	}
	else {
		cout << "\nERROR: Could not open file.\n";
	}
	playerStatsFile.close();
}

void getPlayerData() {
	ifstream playerStatsFile;
	playerStatsFile.open("PlayerStats.txt");
	if (playerStatsFile.is_open()) {
		while (!playerStatsFile.eof()) {
			string currentLine;
			getline(playerStatsFile, currentLine);
			cout << currentLine << '\n';
		}
	}
	else {
		cout << "\nERROR: Could not open file.\n";
	}
	playerStatsFile.close();
}