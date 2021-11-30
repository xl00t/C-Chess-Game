#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#define WHITE 0
#define BLACK 1


#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MakeMove(int, Board *);
int GoodInput(char *);
int len_str(char *);
int LegalMove(int , char *, Board);
int *move_to_array(char *);

int MoveKing(int, int *, Board);
int MoveQueen(int, int *, Board);
int MoveRook(int, int *, Board);
int MoveBishop(int, int *move, Board);
int MoveKnight(int, int *, Board);
int MovePawn(int, int *, Board);
#endif