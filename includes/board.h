#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>


/*                              - 0x2653 	
    Roi blanc 	    ♔ 	0x2654  	    -> 1
    Dame blanche 	♕ 	0x2655  	    -> 2
    Tour blanche 	♖ 	0x2656   	    -> 3
    Fou blanc 	    ♗ 	0x2657   	    -> 4
    Cavalier blanc 	♘ 	0x2658   	    -> 5
    Pion blanc 	    ♙ 	0x2659   	    -> 6
    Roi noir 	    ♚ 	0x265A   	    -> 7
    Dame noire 	    ♛ 	0x265B   	    -> 8
    Tour noire 	    ♜ 	0x265C   	    -> 9
    Fou noir 	    ♝ 	0x265D   	    -> 10
    Cavalier noir 	♞ 	0x265E   	    -> 11
    Pion noir 	    ♟ 	0x265F  	    -> 12
*/

typedef struct {
    wchar_t type;
} Pieces;

typedef struct {
    Pieces piece[8][8];
} Board;

void PrintfBoard(Board board);
Board InitBoard();
int GetPieceID(Pieces);
int GetPieceTypeByPID(int);
int IsEnemyPiece(int, int);
#endif