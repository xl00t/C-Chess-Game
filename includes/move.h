#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#define WHITE 0
#define BLACK 1


#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
    true = 1,
    false = 0
} bool; 

typedef struct {
    int idplayer;
    int y, x;           // Original location
    int ty, tx;         // Choosed Location
    int pid;            // Original Location piece ID
    int ptype;          // Original Location piece type
    int tpid;           // Choosed Location  piece ID
    bool tenemy;        // Choosed Location is enemy or not
} Move;


int MakeMove(int, Board *);
int GoodInput(char *);
int len_str(char *);
int LegalMove(Move, Board);
int IsCheck(int, Board);

Move CreateMoveStruct(int, char *, Board);

int MoveKing(Move, Board);
int MoveQueen(Move, Board);
int MoveRook(Move, Board);
int MoveBishop(Move, Board);
int MoveKnight(Move, Board);
int MovePawn(Move, Board);



int difference(int, int);
int sign(int);
#endif