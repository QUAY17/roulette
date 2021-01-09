#include "Functions.h"

void WriteHeader()
{
	cout << "\n Jennifer Q Minnich's Roulette Program";
	cout << "\n Email: jminnich@cnm.edu ";
	cout << "\n ***********************************************************************************";
	cout << "\n Use this program to test your luck and play a few spins of roulette!";
	cout << "\n You will place a bet, spin the wheel, and see if you can take home any money.";
	cout << "\n ***********************************************************************************";
}

void ShowInstructions()
{
	cout << "\n Rules:";
	cout << "\n The C++ Roulette Wheel has the numbers 0-36 on it.";
	cout << "\n 1.     Bet on a number.";
	cout << "\n 2.	Bet on Odd or Even.";
	cout << "\n 3.	Bet on a dozen (1-12), (13-24), (25-36). ";
	cout << "\n The number zero does not count for odd or even, but can count as a number bet.";
	cout << "\n ***********************************************************************************";
}

void AskForSeed()
{
	unsigned int seed = 0;
	cout << "\n Please enter a seed value for rand(): ";
	cin >> seed; cin.ignore();
	srand(seed); //seed random number generator
	cout << "...Seed rand with " << seed << endl;
}

double ShowTheMoney()
{
	double money = 0.0;
	cout << "\n Please enter your bet in dollars:  $";
	cin >> money; cin.ignore();
	return money;
}

int SelectABet()
{
	vector<string>vMenu; //show a menu of three types of bet they can make
	vMenu.push_back("BET ON A NUMBER payoff is 36x the bet------------------------>  $1 gets you $36");
	vMenu.push_back("BET ON AN ODD OR EVEN payoff is 2x the bet------------------->  $1 gets you $2");
	vMenu.push_back("BET ON A DOZEN (1-12), (13-24), (25-36) payoff is 3x the bet->  $1 gets you $3");

	cout << setw(20);

	for (int i = 0; i < vMenu.size(); ++i)
	{
		cout << "\n" << i + 1 << ". " << setw(10) << vMenu.at(i) << endl;
	}

	//ask the user to choose a number from the menu
	int choice = 0;
	cout << "\n\n Please enter the number of your bet: ";
	cin >> choice; cin.ignore();
	return choice; //return bet
}

void MakeABet(int& rbetNumber) //ask user to enter a number between 0 and 36
{
	
		do {
		cout << "Please enter a number between 0 and 36: ";
		cin >> rbetNumber; cin.ignore();
		if (rbetNumber < 0 || rbetNumber > 37) //check number range in a loop 
		{
			cout << "\n Oops, please enter a number between 0 and 36: ";
		}
		cout << "\n ***********************************************************************************\n";

	} while (rbetNumber < 0 || rbetNumber > 36);
}

void MakeABet(bool& rbOdd) //ask user if they want to bet on 1. odd or 2. even
{

		int evenOdd = 0;
	
	do {
		cout << "\n You can bet 1 for odd or 2 for even, enter number here: ";
		cin >> evenOdd; cin.ignore();
		if (evenOdd == 1)//read the number and check the number 
		{
			cout << "Okay, odd numbers...";
			rbOdd = true;//convert answer to true or false
		}
		else if (evenOdd == 2)
		{
			cout << "/n Okay, even numbers... ";
			rbOdd = false;
		}
		else
		{
			cout << "\n Oops, enter 1 for odd or 2 for even: ";
		}
		cout << "\n ***********************************************************************************\n";
	} while (evenOdd > 2 || evenOdd < 1);
}

void MakeABet(int& rlow, int& rhigh) //ask user to choose a range for the dozen 1, 2, 3
{
	int range = 0;
	cout << "\n Choose from the following ranges: "; 
	cout << "\n 1:  0-12 ";
	cout << "\n 2:  13-24 ";
	cout << "\n 3:  25-36 \n";
	cin >> range; cin.ignore();

	do {

		switch (range)//Based on the choice, assign the variables (use a switch and set high and low)
		{

		case 1: //range 1
			cout << "You have chosen 0-12 " << endl;
			rlow = 0;
			rhigh = 12;
			break;

		case 2: //range 2
			cout << "You have chosen 13-24" << endl;
			rlow = 13;
			rhigh = 24;
			break;

		case 3: //range 3
			cout << "You have chosen 25-36" << endl;
			rlow = 25;
			rhigh = 36;
		default: // invalid number
			cout << "Please enter a valid number." << endl;
			continue;
		}
	} while (range < 1 || range > 3);

}

int SpinTheWheel() //roulette wheel spin
{
	int spin = 0;
	spin = rand() % 37;
	return spin;
}

void FigureWinnings(double money, int spin, int betNumber, double* pWinnings) //determine user's winnings based on their bet choice
{

	if (spin == betNumber) //check if user matched the number 
	{
		*pWinnings = money * 36; //update pointer Winnings
		cout << "\n You win!";
		cout << " Winnings this game: $" << *pWinnings << endl;
	}
	else 
	{
		*pWinnings = 0;
		cout << "\n Sorry, not a winner today." << endl;

	}
}
	

void FigureWinnings(double money, int spin, bool bOdd, double* pWinnings)
{

	if ((bOdd && spin%2 == 1) || (!bOdd && spin % 2 == 0)) //check if odd or even matches the number  
	{
		*pWinnings = money * 2; //update pointer Winnings
		cout << "\n You win!";
		cout << " Winnings this game: $" << *pWinnings << endl;
	}
	else if (spin == 0) 
	{
		*pWinnings = 0.0;
		cout << "\n You lost this round because the spin was zero.";
	}
	else
	{
		*pWinnings = 0.0;
		cout << "\n Sorry, not a winner today." << endl;
	}
}

void FigureWinnings(double money, int spin, int low, int high, double* pWinnings)
{

	if (spin >= low && spin <= high) //check if spin is in the range of dozen chosen by user
	{
		*pWinnings = money * 3; //update pointer Winnings
		cout << "\n You win!";
		cout << " Winnings this game: $" << *pWinnings << endl;
	}
	else
	{
		*pWinnings = 0.0;
		cout << "\n Sorry, not a winner today." << endl;
	}
}

bool WriteFile(string report, string* pFilename) //write report file with stream
{
	cout << "\n Your game report is available, please enter a filename such as 'file.txt' " << endl; //get filename from user, advise format
	cout << "--lowercase, one word, ending with '.txt' " << endl;
	cin >> *pFilename; cin.ignore();

	ofstream output; //write data to file, open file
	output.open((*pFilename).c_str());
	if (!output) return false; //check to see if file exists

	
	output << "\n Jennifer Q Minnich's Roulette Program";
	output << "\n Email: jminnich@cnm.edu ";
	output << "\n ***********************************************************************************";
	output << "\n Game report: \n\n" << report << endl; // file output 
	
	output.close(); //close output file
	return true;
}
