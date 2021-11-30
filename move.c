#include "includes/move.h"

int len_str(char *str){
    int len =0;
    for(;str[len]!='\0';)
        len++;
    
    return len;
}


int MakeMove(int idPlayer, Board *board){
    char move[5];
    scanf(" %5[^\n]", move);
    if(!GoodInput(move))
        return 0;
    if(!LegalMove(idPlayer, move, *board))
        return 0;

    int *mov = move_to_array(move);
    int y = mov[1]; int x = mov[0];
    int ty = mov[4]; int tx = mov[3];

    board->piece[ty][tx].type = board->piece[y][x].type;
    board->piece[y][x].type = 0x00;
    

    return 1;
}

int GoodInput(char *move){
    if(len_str(move) != 5)
        return 0;
    for(int i=0; i<5; i++)
        if(i != 2 &&(move[i] < '0' || move[i] > '7'))
            return 0;

    if(move[2]!= ' ')
        return 0;
    return 1;
}

int LegalMove(int idPlayer, char *move, Board board){

    int *mov = move_to_array(move);
    int y = mov[1]; int x = mov[0];
    int ty = mov[4]; int tx = mov[3];
    int pid = GetPieceID(board.piece[y][x]);
    int ptype = GetPieceTypeByPID(pid);
    //Cant move empty pieces
    if(pid == 0)
        return 0;
    //No moves ?
    if(ty == y && tx == x)
        return 0;
    //Cant move other player pieces
    if((idPlayer == WHITE && (pid > 6)) || (idPlayer == BLACK && (pid < 7)))
        return 0;

    switch(ptype){
        case 1: return MoveKing(idPlayer, mov, board);
        case 2: return MoveQueen(idPlayer, mov, board);
        case 3: return MoveRook(idPlayer, mov, board);
        case 4: return MoveBishop(idPlayer, mov, board);
        case 5: return MoveKnight(idPlayer, mov, board);
        case 6: return MovePawn(idPlayer, mov, board);
        default:
            return 0;
    }
    return 1;
}

int *move_to_array(char *str){
    int *arr = malloc(sizeof(int) * 4);
    for(int i=0; i<5; i++){
        if(i!=2)
            arr[i] = str[i] - '0';
    }

    return arr;
}

int MoveKing(int idPlayer, int *move, Board board){

    return 1;
}
int MoveQueen(int idPlayer, int *move, Board board){

    return 1;
}
int MoveRook(int idPlayer, int *move, Board board){

    return 1;
}
int MoveBishop(int idPlayer, int *move, Board board){

    return 1;
}
int MoveKnight(int idPlayer, int *move, Board board){

    return 1;
}
int MovePawn(int idPlayer, int *move, Board board){

    int y = move[1]; int x = move[0];
    int ty = move[4]; int tx = move[3];
    int pid = GetPieceID(board.piece[y][x]);
    int ptype = GetPieceTypeByPID(pid);

    //First move of pawn cant be > 2 in y axe
    if((idPlayer == WHITE && (y - ty > 2)) || (idPlayer == BLACK && (ty - y > 2)))
        return 0;

    //Pawn cant go two case front if no first move
    if((pid == 6 || pid == 12) && (idPlayer == WHITE && y != 6 && (y - ty > 1)) || (idPlayer == BLACK && y != 1 && (ty - y > 1)))
        return 0;
    
    if((pid==12 || pid ==6) && GetPieceID(board.piece[ty][tx]) == 0 && tx!=x)
        return 0;

    if((pid==12 || pid ==6) && GetPieceID(board.piece[ty][tx]) == 0 && tx!=x)
        return 0;
    
    return 1;
}