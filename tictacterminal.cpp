/*
 *  Created on: Aug 27, 2013
 *      Author: Jeffrey D.
 *      email:  literallyelvis@gmail.com
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

void charSelection( char &, char & );
void printBoard( char cell[][3] );
int  firstSelector( int & );
void clearBoard( char cell[][3] );
void compCellSelector( int &, char cell[][3] , char );
void playerCellSelector( int &turns, char cell[][3], char playerChar );
bool gameVictory( char cell[][3], char &, bool & );
void victoryDeclaration( char, char, char &, char cell[][3] );

int main()
{
	const int ROWS = 3,
			  COLS = 3;

	int turns = 0,
		first = 0;

	char cell[ROWS][COLS] =
	{
		{ 'T', 'I', 'C' },
		{ 'T', 'A', 'C' },
		{ 'T', 'O', 'E' }
	};

	char playerChar,
		 compChar,
		 victorChar;

	bool victory = 0;

	cout << "Welcome to Tic Tac Terminal!" << endl;
	printBoard( cell );
	firstSelector( first );
	charSelection( playerChar, compChar );
	clearBoard( cell );
	if ( first == 1 )
	{
		compCellSelector( turns, cell, compChar );
	}
	playerCellSelector( turns, cell, playerChar );

	while ( !victory )
	{
		if( first == 1 )
		{
			playerCellSelector( turns, cell, playerChar );
			compCellSelector( turns, cell, compChar );
		}
		else
		{
			compCellSelector( turns, cell, compChar );
			playerCellSelector( turns, cell, playerChar );
		}
		if( victory == 1 )
		{
			break;
		}
		gameVictory( cell, victorChar, victory );
	}

	victoryDeclaration( playerChar, compChar, victorChar, cell );

	return 0;
}

void printBoard( char cell[][3] )
{
	cout << endl;
	cout << " " << cell[0][0] << " | " << cell[0][1] << " | " << cell[0][2]
		 << " " << endl	 << "---|---|---" << endl
		 << " " << cell[1][0] << " | " << cell[1][1] << " | " << cell[1][2]
		 << " " << endl	 << "---|---|---" << endl
		 << " " << cell[2][0] << " | " << cell[2][1] << " | " << cell[2][2]
		 << " " << endl << endl;
}

void charSelection( char &playerChar, char &compChar )
{
	int done = 0;
	cout << "Would you like to be X or O?" << endl;
	while( done == 0 )
	{
		cin >> playerChar;
		switch( playerChar )
		{
		case 'X':
		case 'x':
			playerChar = 'X';
			compChar = 'O';
			done = 1;
			break;
		case 'O':
		case 'o':
			playerChar = 'O';
			compChar = 'X';
			done = 1;
			break;
		default:
			cout << "Please choose either letter X or O." << endl;
			break;
		}
	}
}

int firstSelector( int &first )
{
	cout << "Who will go first? Let's flip a coin! ..." << endl << endl;
	sleep(2);
	int i;
	i = rand();
	if( i % 2 == 1 )
	{
		cout << "Player gets to go first!" << endl << endl;
		first = 0;
	}
	else
	{
		cout << "Computer gets to go first!" << endl << endl;
		first = 1;
		sleep(1);
	}

	return first;
}

void clearBoard( char cell[][3] )
{
	for( int i = 0; i < 3; i++ )
	{
		for( int j = 0; j < 3; j++ )
		{
			cell[i][j] = ' ';
		}
	}
}

void compCellSelector( int &turns, char cell[][3], char compChar )
{
	bool done = 0;
	while( !done )
	{
		int i = rand() % 3,
			j = rand() % 3;

		if( cell[i][j] == ' ' )
		{
			cell[i][j] = compChar;
			turns++;
			done = 1;
			printBoard( cell );
		}
		else
		{
			i = 4;
			j = 4;
		}
	}
}

void playerCellSelector( int &turns, char cell[][3], char playerChar )
{
	int x,
		y;

	bool done = 0;
	while ( !done )
	{
		cout << endl << "Choose a column: ";

		cin >> x;
		switch( x )
		{
		case 1:
			x = 0;
			break;
		case 2:
			x = 1;
			break;
		case 3:
			x = 2;
			break;
		default:
			cout << "please choose a number from one to three." << endl;
			break;
		}

		cout << "Choose a row: ";
		cin >> y;
		switch( y )
		{
		case 1:
			y = 0;
			break;
		case 2:
			y = 1;
			break;
		case 3:
			y = 2;
			break;
		default:
			cout << "please choose a number from one to three." << endl;
			break;
		}

		if( cell[y][x] == ' ')
		{
			cell[y][x] = playerChar;
			turns++;
			done = 1;
			printBoard( cell );
		}
		else
		{
			cout << "You cannot choose that space.";
		}
	}
}

bool gameVictory( char cell[][3], char &victorChar, bool &victory )
{
	if( cell[0][0] != ' '
  	 && cell[0][0] == cell[0][1]
  	 && cell[0][1] == cell[0][2] )
	{
		victorChar = cell[0][0];
		victory = 1;
	}
	else if( cell[0][0] != ' '
		   && cell[0][0] == cell[1][0]
		   && cell[1][0] == cell[2][0] )
	{
		victorChar = cell[0][0];
		victory = 1;
	}
	else if( cell[0][0] != ' '
		  &&  cell[0][0] == cell[1][1]
		  && cell[1][1] == cell[2][2] )
	{
		victorChar = cell[0][0];
		victory = 1;
	}
	else if( cell[0][2] != ' '
		   && cell[0][2] == cell[1][2]
		   && cell[1][2] == cell[2][2] )
	{
		victorChar = cell[0][2];
		victory = 1;
	}
	else if( cell[2][0] != ' '
		   && cell[2][0] == cell[2][1]
	   	   && cell[2][1] == cell[2][2] )
	{
		victorChar = cell[2][0];
		victory = 1;
	}
	else if( cell[2][0] != ' '
			&& cell[2][0] == cell[1][1]
		    && cell[1][1] == cell[0][2] )
	{
		victorChar = cell[2][0];
		victory = 1;
	}
	else if( cell[1][0] != ' '
		  && cell[1][0] == cell[1][1]
		  && cell[1][1] == cell[1][2] )
	{
		victorChar = cell[1][0];
		victory = 1;
	}
	else if( cell[0][1] != ' '
			&& cell[0][1] == cell[1][1]
			&& cell[1][1] == cell[2][1] )
	{
		victorChar = cell[0][1];
		victory = 1;
	}
	return victory;
}

void victoryDeclaration( char playerChar, char compChar,
								char &victorChar, char cell[][3] )
{
	if( victorChar == playerChar )
	{
		cout << "Player has won the game!";
	}
	else
	{
		cout << "Computer has won the game!";
	}
}
