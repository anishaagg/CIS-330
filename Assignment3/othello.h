//Anisha Aggarwal	CIS330	Assignment3	othello.h

#ifndef _OTHELLO_H_
#define _OTHELLO_H_

enum state {Empty, White, Black};

struct board {
        int size;
        enum state **cell;      //each position in the board
};

typedef struct board Board;

//prototypes
void playOthello();
int flank(Board b,enum state color, int x, int y);
int flank_one(Board b, enum state color, int x, int y, int x_inc, int y_inc);
void initialize_board(Board b);
void print_board(Board b);


#endif


