//Anisha Aggarwal	CIS330	Assignment4	othello.hpp

#ifndef OTHELLO_HPP_
#define OTHELLO_HPP_

class chip{
public:
	char chip_color = 'O';
	void set_color();
};

class othello_board{
public:
	int size;
	chip **board;
	void get_size();
	void allocate_board_size();
	void display_board();
	int check(char color, int x, int y);
	int to_check(char color, int x, int y, int x_off, int y_off);
};

class othello_game{
public:
	othello_board board;
	void play();
};



#endif /* OTHELLO_HPP_ */
