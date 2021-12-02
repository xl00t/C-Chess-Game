#include "includes/move.h"

int len_str(char *str){
    int len =0;
    for(;str[len]!='\0';)
        len++;
    
    return len;
}

int myatoi(char c){
    return c-'0';
}

Move CreateMoveStruct(int idplayer, char *mov, Board board){
    Move move;
    move.idplayer = idplayer;
    move.y = myatoi(mov[1]); move.x = myatoi(mov[0]);
    move.ty = myatoi(mov[3]); move.tx = myatoi(mov[2]);
    move.pid = GetPieceID(board.piece[move.y][move.x]);
    move.ptype = GetPieceTypeByPID(move.pid);
    move.tpid = GetPieceID(board.piece[move.ty][move.tx]); //id of choosed location
    move.tenemy = IsEnemyPiece(idplayer, move.tpid); //is location is enemy piece (empty location counted as ennemy)
    
    //printf("idplayer\t%d\ny\t%d\nx\t%d\nty\t%d\ntx\t%d\npid\t%d\nptype\t%d\nidtpid\t%d\ntenemy\t%d\n", idplayer, move.y, move.x, move.ty, move.tx, move.pid, move.ptype, move.tpid, move.tenemy);

    return move;
}

int MakeMove(int idplayer, Board *board){
    char mov[4];
    scanf(" %4[^\n]", mov);

    if(!GoodInput(mov) )
        return 0;

    Move move = CreateMoveStruct(idplayer, mov, *board);
    if(!LegalMove(move, *board))
        return 0;

    Board tmp = *board;
    tmp.piece[move.ty][move.tx].type = tmp.piece[move.y][move.x].type;
    tmp.piece[move.y][move.x].type = 0x00;

    if(IsCheck(idplayer, tmp))
        return 0;
    
    board->piece[move.ty][move.tx].type = board->piece[move.y][move.x].type;
    board->piece[move.y][move.x].type = 0x00;

    return 1;
}

int GoodInput(char *move){
    if(len_str(move) != 4)
        return 0;
    for(int i=0; i<4; i++)
        if(move[i] < '0' || move[i] > '7')
            return 0;

    return 1;
}

int LegalMove(Move move, Board board){

    //Cant move empty pieces
    if(move.pid == 0)
        return 0;
    
    if(!move.tenemy)
        return 0;
    //No moves ?
    if(move.ty == move.y && move.tx == move.x)
        return 0;
    //Cant move other player pieces
    if((move.idplayer == WHITE && (move.pid > 6)) || (move.idplayer == BLACK && (move.pid < 7)))
        return 0;

    switch(move.ptype){
        case 1: return MoveKing(move, board);
        case 2: return MoveQueen(move, board);
        case 3: return MoveRook(move, board);
        case 4: return MoveBishop(move, board);
        case 5: return MoveKnight(move, board);
        case 6: return MovePawn(move, board);
        default:
            return 0;
    }
}

int IsCheck(int idplayer, Board board){
    Coord KingPos;
    if (idplayer==0)
        KingPos = FindPiece(1, board);
    else if(idplayer==1)
        KingPos = FindPiece(7, board);


    return 0;
}

int MoveKing(Move move, Board board){
    if(difference(move.y, move.ty) > 1 || difference(move.x, move.tx) > 1)
        return 0;
    return 1;
}

int MoveQueen(Move move, Board board){
    if((move.y == move.ty || move.x == move.tx) || (difference(move.y, move.ty) == difference(move.x, move.tx))){
        int ydir = sign(move.y - move.ty) * - 1;
            int xdir = sign(move.x - move.tx) * - 1;
            for (int y = move.y+ydir, x = move.x+xdir; y!=move.ty; y+=ydir, x+=xdir){
                if(GetPieceID(board.piece[y][x]) != 0)
                    return 0;
            }
        return 1;
    }
    return 0;
}

int MoveRook(Move move, Board board){
        if(move.y == move.ty || move.x == move.tx){
            int ydir = sign(move.y - move.ty) * - 1;
            int xdir = sign(move.x - move.tx) * - 1;
            for (int y = move.y+ydir, x = move.x+xdir; y!=move.ty; y+=ydir, x+=xdir){
                if(GetPieceID(board.piece[y][x]) != 0)
                    return 0;
            }
        return 1;
    }
    return 0;
}

int MoveBishop(Move move, Board board){
    if(difference(move.y, move.ty) == difference(move.x, move.tx)){
        int ydir = sign(move.y - move.ty) * - 1;
        int xdir = sign(move.x - move.tx) * - 1;
        for (int y = move.y+ydir, x = move.x+xdir; y!=move.ty; y+=ydir, x+=xdir){
            if(GetPieceID(board.piece[y][x]) != 0)
                return 0;
        }
        return 1;
    }
    return 0;
}

int MoveKnight(Move move, Board board){
    if((difference(move.y, move.ty) == 2 && difference(move.x, move.tx) == 1) || (difference(move.y, move.ty) == 1 && difference(move.x, move.tx) == 2))
        return 1;
    return 0;
}

int MovePawn(Move move, Board board){

    // no pawn backwards
    if((move.idplayer == WHITE && move.ty > move.y) || (move.idplayer == BLACK && move.y > move.ty)){
        return 0;
    }
    //first pawn move 2 authorized
    if(((move.idplayer == WHITE && move.y == 6) || (move.idplayer == BLACK && move.y == 1)) && difference(move.y, move.ty) < 3){
        if((move.x == move.tx) && move.tpid == 0)
            if((move.idplayer == WHITE && GetPieceID(board.piece[move.ty+1][move.tx]) == 0) || (move.idplayer == BLACK && GetPieceID(board.piece[move.ty-1][move.tx]) == 0))
            return 1;
    }
    if(difference(move.y, move.ty) == 1){
        if(move.x == move.tx && move.tpid == 0)
            return 1;
        else if(difference(move.x, move.tx) == 1 && move.tenemy)
            return 1;
    }
    return 0;
}

int difference(int a, int b){
    return (a>b) ? a-b : b-a;
}

int sign(int x) {
    return (x > 0) - (x < 0);
}