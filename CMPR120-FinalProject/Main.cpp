#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const string TEAM_NAME = "RGB";

int main() {
	bool continueProgram = true; // used to decide when to exit the menu
	int selection; // used to capture user input

	do { // everything in body of do-while loop will execute until continueProgram == false

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

		cout << selection;

		/**** DECISION LOGIC ****/

		switch (selection) {
		case 1: // User input == 1
			cout << "\n\tOption 1\n";
			break;
		case 2: // User input == 2
			cout << "\n\tOption 2\n";
			break;
		case 3: // User input == 3
			cout << "\n\tOption 3\n";
			break;
		case 4: // User input == 4
			cout << "\n\tOption 4\n";
			break;
		case 5: // User input == 5
			cout << "\n\tOption 5\n";
			break;
		case 6: // User input == 6
			cout << "\n\tOption 6\n";
			continueProgram = false; // continueProgram set to false, ending the do-while loop
			break;
		default:
			cout << "\n\tPlease make a valid selection.\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}

	} while (continueProgram);

	return 0;
}