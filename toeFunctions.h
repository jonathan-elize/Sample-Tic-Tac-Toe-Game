#ifndef TOEFUNCTIONS_H
#define TOEFUNCTIONS_H

#include <iostream>
using namespace std;

void markBoard(char pos[][3], int row, int column, char letter);
void statusDisplay(char stat);
void displayBoard(char [][3]);
bool rowCheck(char pos[][3],  char &stat);
bool columnCheck(char pos[][3],  char &stat);
bool crossCheck(char pos[][3],  char &stat);
#endif
