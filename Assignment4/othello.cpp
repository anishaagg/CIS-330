//Anisha Aggarwal	CIS330	Assignment4	othello.cpp

#include <iostream>
#include <cstring>
#include "othello.hpp"
using namespace std;

// board: get size
void othello_board::get_size(){
	int input_size;
	cout << "Enter board size: ";
	cin >> input_size;
	othello_board::size = input_size;
}

// board: initialize board
void othello_board::allocate_board_size() {
	// create a board of size inputted
	int size = othello_board::size;
	this->board = new chip*[othello_board::size];

	// initialize all spots on board to 'O'
	for(int i = 0; i < othello_board::size; i++) {
		board[i] = new chip[othello_board::size];
	}

	//intialize the middle 4 spots to have 2 whites and 2 blacks
	int mid = size / 2;
	othello_board::board[mid - 1][mid - 1].chip_color = 'B';
	othello_board::board[mid - 1][mid].chip_color = 'W';
	othello_board::board[mid][mid - 1].chip_color = 'W';
	othello_board::board[mid][mid].chip_color = 'B';
}

// board: display board
void othello_board::display_board() {
	//traverse through the array's rows
	for(int i = 0;i < othello_board::size; i++) {
		//traverse through the array's columns
		for(int j = 0; j < othello_board::size; j++) {
			//print based on what the value is
			switch(othello_board::board[i][j].chip_color) {
				case 'O' :
					cout << "O ";
					break;
				case 'W' :
					cout << "W ";
					break;
				case 'B' :
					cout << "B ";
					break;
				default :
					cout << "Error";
					break;
			}
		}
		cout << "\n";
	}
}

//last 2 arguments are x-increment and y-increment as you go in a particular direction
int othello_board::to_check(char color, int x, int y, int x_inc, int y_inc) {

	int new_x = x + x_inc;	//next x
	int new_y = y + y_inc;	//next y
	int count = 0;
	int temp_count;

	//check if there is a coin of the opposide color between one of the same color
    //we will need to flip what is in between
	while(1){
		if( (new_x >= othello_board::size) || (new_x < 0) || (new_y >= othello_board::size) || (new_y < 0)) {
			count = 0;	//didn't find coin of own color
			break;
		} else if (othello_board::board[new_x][new_y].chip_color == color) {
			break;
		} else if (othello_board::board[new_x][new_y].chip_color == 'O' ) {
			count = 0;	//didn't find coin of own color
			break;
		}

		count++;

		//check the next spot on the board in direction x_inc, y_inc
		new_x += x_inc;
		new_y += y_inc;
	}

	temp_count = count;

	//if there were opposite colors in between
    //go back to original coin and flip the ones in between
	new_x = x + x_inc;
	new_y = y + y_inc;
	while(count != 0){
		othello_board::board[new_x][new_y].chip_color = color;
		count--;
		//check the next spot on the board in direction x_inc, y_inc
		new_x += x_inc;
		new_y += y_inc;
	}

	return temp_count;
}

// flip coins
int othello_board::check(char color, int x, int y){
	int count = 0;	//count that will hold number of flipped coins

	//last 2 arguments are x-increment and y-increment as you go in a particular direction
    //go UP
	count += to_check(color, x, y, -1, 0);
	//go DOWN
	count += to_check(color, x, y, 1, 0);
	//go LEFT
	count += to_check(color, x, y, 0, -1);
	//go RIGHT
	count += to_check(color, x, y, 0, 1);
	//go LEFT UP
	count += to_check(color, x, y, -1, -1);
	//go LEFT DOWN
	count += to_check(color, x, y, 1, -1);
	//go RIGHT UP
	count += to_check(color, x, y, -1, 1);
	//go RIGHT DOWN
	count += to_check(color, x, y, 1, 1);

	if(count == 0){
		cout << "Invalid Move.\n";
	}else{
		othello_board::board[x][y].chip_color = color;
		cout << "Number of chips flipped: " << count << "\n";
	}

	display_board();
	return count;

}

// othello game play
void othello_game::play() {
	int row;
	int col;
	char color;

	board.get_size();
	board.allocate_board_size();
	board.display_board();

	while(1){
		//Player 1 turn
		cout << "Player 1(Black) Enter Board Position (enter: 99 99 if board is full): ";
		cin >> row >> col;
		color = 'B';
		row -= 1;
		col -= 1;

		if ((row < 0) || (row > board.size) || (col < 0) || (col > board.size)) {
			if ((row == 98) && (col == 98)) {
				cout << "Board is full! Game Over!\n";
				break;
			} else {
				cout << "Invalid Input.\n";
				break;
			}

		}
		// do a board check
		board.check(color, row, col);

		//Player 2 turn
		cout << "Player 2(White) Enter Board Position (enter: 99 99 if board is full): ";
		cin >> row >> col;
		color = 'W';
		row -= 1;
		col -= 1;

		//check if the move is a valid move
		//get user input until it is valid
		if ((row < 0) || (row > board.size) || (col < 0) || (col > board.size)) {
			if ((row == 98) && (col == 98)) {
				cout << "Board is full! Game Over!\n";
				break;
			} else {
				cout << "Invalid Input.\n";
				break;
			}
		}
		// do a board check
		board.check(color, row, col);

	}

}

int main() {

	othello_game game;
	game.play();

	return 0;
}

