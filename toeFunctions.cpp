#include "toeFunctions.h"
    
//----------------------------------------------------------------------------
// Purpose:   Replaces specified element of the array with specified letter.
// Arguments:
//            (1) char pos[][3] is the 2-d array who's element will be
//		  replaced and which acts as the board.
//            (2) int row is the specified row where the element will be 
//		  changed.
//            (3) int column is the specified column where the element will be 
//		  changed.
//	      (4) char letter is the specified letter that the element of the 
//	          array will be replaced with.
// Results: (Numbered list of outcomes)
//            (1)
//----------------------------------------------------------------------------
void markBoard(char pos[][3], int row, int column, char letter)
{
    pos[--row][--column] = letter;	
    
}

//----------------------------------------------------------------------------
// Purpose:   Displays status of the game on screen
// Arguments: 
//            (1) char stat is a marker which the function uses to know which 
//                status to display
// Results: 
//            (1) 
//----------------------------------------------------------------------------
void statusDisplay(char stat)
{
    switch(stat)
    {
	case 'p':cout << "==> GAME STATUS: IN PROGRESS" << endl << endl;
		break;
	case 'n':cout << "==> GAME STATUS: NEW GAME" << endl << endl;
		break;
	case 'x':cout << "==> GAME STATUS: WINNER IS X" << endl << endl;
		break;
	case 'o':cout << "==> GAME STATUS: WINNER IS O" << endl << endl;
		break;
    }//
}

//----------------------------------------------------------------------------
// Purpose:   checks to see if someone has won through consecutive letters
//	      in a row.
// Arguments: 
//            (1) char pos[][3] is the array that serves as the board and 
//		  hosts the rows to be checked.
//            (2) char &stat serves as the marker which will be used to 
//		  determine whether 'x' or 'o' won.
// Results: 
//            (1)
//----------------------------------------------------------------------------
bool rowCheck(char pos[][3],  char &stat)
{
    for(int r = 0; r < 3; r++)
    {
	if(pos[r][0] == pos [r][1] && pos[r][0] == pos[r][2])
	{
	    (pos[r][0] == 'x')? stat = 'x': stat ='o';
	    return true;
	}
	return false;
    }//for
}

//----------------------------------------------------------------------------
// Purpose:   checks to see if someone has won through consecutive letters
//	      in a column.
// Arguments: 
//            (1) char pos[][3] is the array that serves as the board and 
//		  hosts the column to be checked.
//            (2) char &stat serves as the marker which will be used to 
//		  determine whether 'x' or 'o' won.
// Results: 
//            (1)
//----------------------------------------------------------------------------
bool columnCheck(char pos[][3],  char &stat)
{
    for(int c = 0; c < 3; c++)
    {
	if(pos[0][c] == pos [1][c] && pos[0][c] == pos[2][c])
	{
	    (pos[0][c] == 'x')? stat = 'x': stat ='o';
	    return true;
	}
	return false;
    }//for
}

//----------------------------------------------------------------------------
// Purpose:   checks to see if someone has won through consecutive letters
//	      in a center diagnol.
// Arguments: 
//            (1) char pos[][3] is the array that serves as the board and 
//		  hosts the diagnol to be checked.
//            (2) char &stat serves as the marker which will be used to 
//		  determine whether 'x' or 'o' won.
// Results: 
//            (1)
//----------------------------------------------------------------------------
bool crossCheck(char pos[][3],  char &stat)
{
	if(pos[0][0] == pos [1][1] && pos[0][0] == pos[2][2])
	{
	    (pos[0][0] == 'x')? stat = 'x': stat ='o';
	    return true;
	}
	else if(pos[2][0] == pos [1][1] && pos[2][0] == pos[0][2])
	{
	    (pos[0][0] == 'x')? stat = 'x': stat ='o';
	    return true;
	}
	return false;
}

//----------------------------------------------------------------------------
// Purpose:   displays current state of the board 
// Arguments: 
//            (1) char pos[][3] is the array which holds the "pieces" on the
//		  board.
//            (2)
// Results: (Numbered list of outcomes)
//            (1)
//----------------------------------------------------------------------------
void displayBoard(char pos[][3])
{
    //------------------------------------------------------------------------
    // Declare and initialize variables
    //------------------------------------------------------------------------
    string rBorder = "---+---+---",      //serves as row boarder of board
	   indent = "                 "; //places indentation for row
    //------------------------------------------------------------------------
    // Display Game board message and top row border
    //------------------------------------------------------------------------
    cout << "==> GAME BOARD: " << endl << endl;
    cout << indent << rBorder<< endl;

    //------------------------------------------------------------------------
    // For loop to display body of the board
    //------------------------------------------------------------------------
    for(int r = 0; r < 3; r++)
    {
	    //----------------------------------------------------------------
	    // Display indent for every row
	    //----------------------------------------------------------------
	    cout << indent;

	    //----------------------------------------------------------------
	    // For loop todisplay board rows
	    //----------------------------------------------------------------
	    for(int c=0; c < 3; c++)
	    {
		cout << ' ' << pos[r][c]; 

		//------------------------------------------------------------
		// When the column isnt the last column display | afterward
		//------------------------------------------------------------
		(c<2)?cout << " |" : cout << endl<< indent << rBorder << endl;
	    }//for
    }//for
}
