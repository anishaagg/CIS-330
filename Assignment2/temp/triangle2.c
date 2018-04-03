//Anisha Aggarwal	CIS 330	Assignment2	triangle2.c

#include <stdio.h>
#include <stdlib.h>

/* Allocate a triangle of height "height" (a 2-D array of int) */
void allocateNumberTriangle(const int height, int ***triangle) {
	int columns = height*2 - 1;

	*triangle = (int **) malloc (height * sizeof(int *) );
	for (int i = 0; i < height; i++) {
		(*triangle)[i] = (int *) malloc (columns * sizeof(int) );
	}
	
}

/* Initialize the 2-D triangle array */
void initializeNumberTriangle(const int height, int **triangle) {
	int spaces = height - 1; // number of spaces needed before and after a number is printed in each row
        int num;        // max number to be printed in each row
		
        for (int i = 0; i < height; ++i) {
                int count1 = spaces;    // number of spaces to go on the left side of numbers
                int count2 = spaces;    // number of spaces to go on the right side of the numbers
		int j = 0;      // holds count for columns

                while (count1 > 0) {
			triangle[i][j] = -1;     //store a space
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
                        triangle[i][j] = -1;     //store a space
                        count2 = count2 - 1;
                        j++;
                }

                spaces = spaces - 1;
        }

}

/* Print a formatted triangle */
void printNumberTriangle(const int height, int **triangle) {
	int column = 2*height - 1;
	for (int r = 0; r < height; r++) {
                for (int c = 0; c < column; c++) {
                        if (triangle[r][c] == -1) {
                                printf("%s", " ");
                        } else {
                                printf("%d", triangle[r][c]);
                        }
                }
                printf("\n");   //go to the next row
        }
}

/* Free the memory for the 2-D triangle array */
void deallocateNumberTriangle(const int height, int ***triangle) {
	for (int i = 0; i < height; i++) {
		free((*triangle)[i]);
	}

	free(*triangle);
	*triangle = NULL;
}


