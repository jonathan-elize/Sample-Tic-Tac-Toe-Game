//------------------------------------------------------------------
// File name:   toe.cpp
// Assign ID:   TICTACTOE
// Due Date:    01/17/13 at 11pm 
// 
// Purpose:     Simulate a basic tic tac toe game
// 
// Author:      jelize Jonathan Elize
// 
// -----------------------------------------------------------------
#include "toeFunctions.h"

int main()
{
    //------------------------------------------------------------------------
    // Declare and Initialize variables
    //------------------------------------------------------------------------
    int row,		       //row user chooses to place mark
        column,		       //column user chooses to place mark
        numMoves = 0;          //number of moves user will make
    bool endGame = false;      // flag to know whether to end game
    char mark,                 //mark user chooses
         gStatus = 'n',        //character that marks status of game
	 position[3][3] = {{' ', ' ', ' '},  //layout of board pieces
			   {' ', ' ', ' '}, 
    			   {' ', ' ',' '}};
    //-|----------------------------------------------------------------------
    //-| Print the copyright notice declaring authorship.
    //-|----------------------------------------------------------------------
    cout << endl << "(c) 2017, jelize Jonathan Elize" << endl << endl;   

    //-|------------------------------------------------------------------------
    //-| Intro
    //-|------------------------------------------------------------------------
    cout << "Moves:  0" << endl << endl;
    statusDisplay(gStatus);
    displayBoard(position);	
    //-|----------------------------------------------------------------------
    //-| 1.  Loop game until winner is found
    //-|----------------------------------------------------------------------
    while(!endGame)
    {
	//-|------------------------------------------------------------------
	//-| 2. Status of game is now progress
	//-|------------------------------------------------------------------
	gStatus = 'p';

	//-|------------------------------------------------------------------
	//-| 3. Prompt for numMoves
	//-|------------------------------------------------------------------
    	cout << "Moves: ";
    	cin >> numMoves;

	//-|------------------------------------------------------------------
	//-| 4. For loop to mark board and check for winner
	//-|------------------------------------------------------------------
    	for(int i = 0; i < numMoves; i++)
    	{
	   //-|---------------------------------------------------------------
	   //-| 5. Input for mark, row, and column
	   //-|---------------------------------------------------------------
	   cin >> mark >> row >> column;

	   //-|---------------------------------------------------------------
	   //-| 6. Use function markBoard to mark board
	   //-|---------------------------------------------------------------
    	   markBoard(position, row, column, mark);

	   //-|---------------------------------------------------------------
    	   //-| 7. Use "check" functions to search for winner
	   //-|---------------------------------------------------------------
	   if(rowCheck(position, gStatus))
		endGame = true;
	   else if(columnCheck(position, gStatus))
		endGame = true;
	   else if(crossCheck(position, gStatus))
		endGame = true;
    
	   //-|---------------------------------------------------------------
	   //-| 8. Determine status of game through statusDisplay function
	   //-|---------------------------------------------------------------
    	   statusDisplay(gStatus);
    
	   //-|---------------------------------------------------------------
    	   //-| 9. Use function displayBoard
	   //-|---------------------------------------------------------------
    	   displayBoard(position);
    	}//for
    }//while

    //-|----------------------------------------------------------------------
    //-| Print the copyright notice declaring authorship.
    //-|----------------------------------------------------------------------
    cout << endl << "(c) 2017, jelize Jonathan Elize" << endl << endl;   
    return 0;
}


