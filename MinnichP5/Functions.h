//Jennifer Quay Minnich jminnich@cnm.edu
// Program 5 Roulette Game

//Functions.h

#ifndef  FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

//prototypes
void WriteHeader();
void ShowInstructions();
void AskForSeed();
double ShowTheMoney();
int SelectABet();

void MakeABet(int &rbetNumber);
void MakeABet(bool &rbOdd);
void MakeABet(int &rlow, int &rhigh);

int SpinTheWheel();

void FigureWinnings(double money, int spin, int betNumber, double* pWinnings);
void FigureWinnings(double money, int spin, bool bOdd, double* pWinnings);
void FigureWinnings(double money, int spin, int low, int high, double* pWinnings);

bool WriteFile(string report, string *pFilename);



#endif // ! FUNCTIONS_H
