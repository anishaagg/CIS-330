//Anisha Aggarwal       CIS 330 Assignement 2   triangle.c

//Implement print5Triangle()
//declare a static 2D array of integers and initialize
//print them to standard output

#include <stdio.h>
#define ROWS 5
#define COLS (2*ROWS - 1)

/* Print a triangle of the specified height containing the digits 0 - 9 */
void print5Triangle() {
	static int triangle[ROWS][COLS];	// static array that will be initialized to values to be printed 
	int spaces = 4;	// number of spaces needed before and after a number is printed in each row
	int num;	// max number to be printed in each row

	for (int i = 0; i < ROWS; ++i) {
		int count1 = spaces;	// number of spaces to go on the left side of numbers
		int count2 = spaces;	// number of spaces to go on the right side of the numbers
		int j = 0;	// holds count for columns
		while (count1 > 0) {
			triangle[i][j] = 9;	//store a space
			count1 = count1 - 1;
			j++;
		}

		num = 2*i;
		int increment = 0;
		while (increment <= num) {
			triangle[i][j] = increment;
			increment++;
			j++;
		}

		while (count2 > 0) {
			triangle[i][j] = 9;	//store a space
                	count2 = count2 - 1;
			j++;
                }

		spaces = spaces - 1;
	}
	
	// print triangle array
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			if (triangle[r][c] == 9) {
				printf("%s", " ");
			} else {
				printf("%d", triangle[r][c]);
			}
		}
		printf("\n");   //go to the next row
	}

}




