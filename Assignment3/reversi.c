//Anisha Aggarwal	CIS330	Assignment3	reversi.c

#include <stdio.h>
#include <stdlib.h>
#include "othello.h"

int main() {
        playOthello();
        return 0;
}

void playOthello(){
        Board b;
        //get board size and allocate memory for the board
        //initialize the board to empty
        printf("Please enter size of board: ");
        scanf("%d", &b.size);
        b.cell = (enum state **) malloc (b.size * sizeof(enum state *) );
        for (int i = 0; i < b.size; i++) {
                (b.cell)[i] = (enum state *) malloc (b.size * sizeof(enum state) );
        }
        initialize_board(b);
        print_board(b);
        //while game is not done do..
        int row;
        int col;
        while(1){
                //get (x,y) coordinates from player1
                printf("Player1 - Black: enter the row and column you would like to place coin: ");
                scanf("%d %d", &row, &col);
                row = row - 1;
                col = col - 1;

                if ((row < 0) || (row > b.size) || (col < 0) || (col > b.size)) {
                        //check if board is full 
                        if ((row == 99) && (col == 99)) {
                                printf("Board full. Game done\n");
                                break;
                        } else {
                                printf("Bad input\n");
                                break;
                        }
                }
                flank(b, Black, row, col);

                //get (x,y) coordniates from player2
                printf("Player2 - White: enter the row and column you would like to place coin: ");
                scanf("%d %d", &row, &col);
                row = row - 1;
                col = col - 1;

                //check if board is full                
                if ((row < 0) || (row > b.size) || (col < 0) || (col > b.size)) {
                        //check if board is full 
                        if ((row == 99) && (col == 99)) {
                                printf("Board full. Game done\n");
                                break;
                        }else {
                                printf("Bad input\n");
                                break;
                        }
                }
                flank(b, White, row, col);
        }
}

int flank(Board b, enum state color, int x, int y) {
        int count = 0;  //count that will hold number of flipped coins

        //last 2 arguments are x-increment and y-increment as you go in a particular direction
        //go UP
        count += flank_one(b, color, x, y, -1, 0);
        //go DOWN
        count += flank_one(b, color, x, y, 1, 0);
        //go LEFT
        count += flank_one(b, color, x, y, 0, -1);
        //go RIGHT
        count += flank_one(b, color, x, y, 0, 1);
        //go LEFT UP
        count += flank_one(b, color, x, y, -1, -1);
        //go LEFT DOWN
        count += flank_one(b, color, x, y, 1, -1);
        //go RIGHT UP
        count += flank_one(b, color, x, y, -1, 1);
        //go RIGHT DOWN
        count += flank_one(b, color, x, y, 1, 1);

        if (count == 0) {
                printf("Move was invalid \n");
        } else {
                b.cell[x][y] = color;
                printf("Number of coins flipped: %d\n", count);
        }

        print_board(b);
        return count;
}

//last 2 arguments are x-increment and y-increment as you go in a particular direction
int flank_one(Board b, enum state color, int x, int y, int x_inc, int y_inc) {
        int n_x = x + x_inc;    //next x
        int n_y = y + y_inc;    //next y
        int count = 0;

        //check if there is a coin of the opposide color between one of the same color
        //we will need to flip what is in between
        while (1) {
                //check if out of board
                if ((n_x >= b.size) || (n_x < 0)|| (n_y >= b.size)|| (n_y < 0)) {
                        count = 0;      //didn't find coin of own color
                        break;
                } else if (b.cell[n_x][n_y] == color) {
                        break;
                } else if (b.cell[n_x][n_y] == Empty) {
                        count = 0;      //didn't find coin of own color
                        break;
                }

                count++;
                //check the next spot on the board in direction x_inc, y_inc
                n_x += x_inc;
                n_y += y_inc;
        }

        int temp_count = count;

        //if there were opposite colors in between
        //go back to original coin and flip the ones in between
        n_x = x + x_inc;
        n_y = y + y_inc;
        while (count != 0) {
                b.cell[n_x][n_y] = color;
                count--;
                n_x += x_inc;
                n_y += y_inc;
        }
        return temp_count;
}

void initialize_board(Board b) {
        //initialize the entire board to empty
        for (int i = 0; i < b.size; i++) {
                for (int j = 0; j < b.size; j++) {
                        b.cell[i][j] = Empty;
                }
        }

        //intialize the middle 4 spots to have 2 whites and 2 blacks
        int middle = b.size/2;
        b.cell[middle-1][middle-1] = White;
        b.cell[middle-1][middle] = Black;
        b.cell[middle][middle-1] = Black;
        b.cell[middle][middle] = White;

}

void print_board(Board b){
        //traverse through the array's rows
        for (int i = 0; i < b.size; i++) {
                //traverse through the array's columns
                for (int j = 0; j < b.size; j++) {
                        //print based on what the value is
                        switch(b.cell[i][j]) {
                                case Empty:
                                        printf("O ");
                                        break;
                                case White:
                                        printf("W ");
                                        break;
                                case Black:
                                        printf("B ");
                                        break;
                                default:
                                        printf("bad cell ");
                                        break;
                        }
                }
                printf("\n");
        }

}

