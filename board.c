#include "includes/board.h"

void PrintfBoard(Board board){
    system("clear");    // if windows replace clear with cls
    setlocale(LC_CTYPE, "");
    printf("    "); for(int i=0; i<8; i++)
        printf("%d    ", i);
    for(int y=0; y<8; y++){
        printf("\n  -----------------------------------------\n");
        printf("%d |", y);
        for(int x=0; x<8; x++){
            if(board.piece[y][x].type != 0x00){
                printf(" %lc  |", board.piece[y][x].type);
            }
            else {
                printf("    |");
            }
        }
        printf(" %d", y);
    }
    printf("\n  -----------------------------------------\n");
    printf("    "); for(int i=0; i<8; i++)
        printf("%d    ", i);
}

Board InitBoard(){
    Board board;
    // init empty cases
    for(int y=2; y<6; y++)
        for(int x=0; x<8; x++)
            board.piece[y][x].type = 0x00;
    // Init Pawn
    for(int x=0; x<8; x++){
        board.piece[6][x].type = 0x2659;
        board.piece[1][x].type = 0x265F;
    }
    //black pieces
    board.piece[0][0].type =  board.piece[0][7].type = 0x265C;
    board.piece[0][1].type = board.piece[0][6].type = 0x265E;
    board.piece[0][2].type = board.piece[0][5].type = 0x265D;
    board.piece[0][3].type = 0x265B; board.piece[0][4].type = 0x265A;
    //white pieces
    board.piece[7][0].type = board.piece[7][7].type = 0x2656;
    board.piece[7][1].type = board.piece[7][6].type = 0x2658;
    board.piece[7][2].type = board.piece[7][5].type = 0x2657;
    board.piece[7][3].type = 0x2654; board.piece[7][4].type = 0x2655;

    return board;
}

int GetPieceID(Pieces p){
    return (p.type != 0) ? (int)(p.type - 0x2653) : 0;
}

int GetPieceTypeByPID(int n){
    return (n>6) ? n-6 : n;
}

int IsEnemyPiece(int idplayer, int pid){

    if(pid==0)
        return 1;
    if(idplayer==0)
        return (pid<7) ? 0 : 1;
    else
        return (pid>6) ? 0 : 1;
}

Coord FindPiece(int pid, Board board){
    Coord xy;
    for (int y = 0; y < 8; y++){
        for (int x = 0; x < 8; x++){
            if (board.piece[y][x].type ==  pid + 0x2653){
                xy.x = x; xy.y = y;
                return xy;
            }
        }
    }
    xy.x = xy.y = -1;
    return xy;
}