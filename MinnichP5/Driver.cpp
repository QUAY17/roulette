//Jennifer Quay Minnich jminnich@cnm.edu
// Program 5 Roulette Game

//Driver.cpp

#include "Functions.h"

int main()
{
	//declare variables, assign function variables
	double money, winnings, totalWinnings = 0.0;
	int choice, spin, betNumber, low, high, game = 0;
	char answer = 'y';
	bool bOdd;
	string filename = "";
	stringstream ss;
	ss.precision(2);
	ss.setf(ios::fixed || ios::showpoint);

	//call functions
	WriteHeader(); //get header
	ShowInstructions(); //get instructions
	AskForSeed(); //seed random number generator

	do //start play loop
	{
		//initialize inputs
		game++;
		money = ShowTheMoney();
		choice = SelectABet();
		spin = SpinTheWheel();

		ss << "Game number: " << game << "\n Roulette spin: " << spin << endl;

		switch (choice)
		{
		case 1: //BET NUMBER
			MakeABet(betNumber);
			FigureWinnings(money, spin, betNumber, &winnings);
			ss << "You bet on " << betNumber << endl;
			break;
		case 2: //BET ODD OR EVEN
			MakeABet(bOdd);
			FigureWinnings(money, spin, bOdd, &winnings);
			if (bOdd) ss << "You bet on Odd" << endl;
			else ss << "You bet on Even" << endl;
			break;
		case 3: //BET DOZENS RANGE
			MakeABet(low, high);
			FigureWinnings(money, spin, low, high, &winnings);
			ss << "You bet on the range " << low << " - " << high << endl;
			break;
		default: // invalid number
			ss << "Please enter a valid number." << endl;
			continue;
		}
		//spin!
		cout << "You spinned a " << spin << endl;

		//add to the stringstream what the winnings are from that round
		ss << fixed << " & you won $" << winnings << endl;

		//add the current winnings to a variable called totalWinnings
		totalWinnings += winnings;

		cout << "\n ***********************************************************************************";
		cout << "\n Would you like to spin again? Answer y/n: "; //ask user to play again
		cin >> answer; cin.ignore();

	} while (answer == 'y');
	
	ss << "\n Your total winnings for all games were $" << fixed << totalWinnings; // add total winnings to report
	ss << "\n Thanks for playing!" << endl;
	string report = ss.str(); //create a string out of ss
	bool bOpenFile = WriteFile(report, &filename); //call WriteFile();
	if (bOpenFile == true)
	{
		cout << "\n Locate " << filename << " for your full game report." << endl;
	}
	else
	{
		cout << "\n No report available.";
	}

	cout << "Thanks for playing, adios!" << endl;
	cin.get(); //enter

	return 0;
}

