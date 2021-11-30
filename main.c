#include <stdio.h>
#include "includes/board.h"
#include "includes/move.h"



int main() {

    Board board = InitBoard();
    for(int i=0;;i++){
        PrintfBoard(board);
        printf("\n\nTour aux %s\n", i%2==0 ? "Blancs" : "Noirs");

        while(!MakeMove(i%2, &board)){}
    }
    return 1;
}