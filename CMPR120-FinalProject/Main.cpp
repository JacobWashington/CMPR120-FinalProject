#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**** FUNCTION PROTOTYPES ****/
void menu(bool& continueProgram, double& balance);
void setBalance(double& balance);

/**** CONSTANT VARIABLES ****/
const string TEAM_NAME = "RGB";
const double MAX_ALLOWED = 20.00;

int main() {
	bool continueProgram = true;
	double balance = 0.00;

	do {
		menu(continueProgram, balance);
	} while (continueProgram);

	return 0;
}

void menu(bool& continueProgram, double& balance) {
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
		break;
	case 2:
		setBalance(balance);
		break;
	case 3:
		cout << "\n\tOption 3\n";
		break;
	case 4:
		cout << "\n\tOption 4\n";
		break;
	case 5:
		cout << "\n\tOption 5\n";
		break;
	case 6:
		cout << "\n\tOption 6\n";
		continueProgram = false;
		break;
	default:
		cout << "\n\tPlease make a valid selection.\n";
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

void playGuessingGame() {

}