//Anisha Aggarwal	CIS 330	Assignment 2	mountain.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mountain.h"

/* Allocate a triangle of height "height" (a 2-D array of int) */
void allocateNumberTriangle(const int numPeaks, int *heights, int ***triangles) {
	int rows = 0;	// holds number of rows in triangle
	int columns = 0;	// holds number of columns in trianlges

	// figure out what the max height is of the peaks so we know the number of rows
	for (int i = 0; i < numPeaks; i++) {
		if (rows < heights[i]) {
			rows = heights[i];
			printf("%s%d\n", "rows: ", rows);
		}
	}

	//figure out number of columns needed
	for (int j = 0; j < numPeaks; ++j) {
		columns = columns + (2*heights[j] - 1);
		printf("%s%d\n", "columns: ", columns);
	}

	// allocate spce for the array using malloc
	*triangles = (int **) malloc (rows * sizeof(int *) );
	for (int i = 0; i < rows; i++) {
		(*triangles)[i] = (int *) malloc (columns * sizeof(int) );
	}
}

/* Initialize the 2-D triangle array */
void initializeNumberTriangle(const int numPeaks, int *heights, int **triangles){
	int next_triangle = 0;	// holds the indexed element # to start the next trianlge
	int rows = 0;	//max number of rows in 
    int num;        // max number to be printed in each row
	int columns = 0;	// holds number of columns in trianlges

	// figure out what the max height is of the peaks so we know the number of rows
	for (int i = 0; i < numPeaks; i++) {
		if (rows < heights[i]) {
			rows = heights[i];
			printf("%s%d\n", "rows: ", rows);
		}
	}

	// figure out number of columns needed
	for (int j = 0; j < numPeaks; j++) {
		columns = columns + (2*heights[j] - 1);
		printf("%s%d\n", "columns: ", columns);
	}

	//initialize the entire array to -1 which will print as a space
	for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
               triangles[r][c] = -1;
        }
        printf("\n");   //go to the next row
    }

    //traverse through the array to 
	while(next_triangle != columns) {
	    int max;	//variable to hold the num of columns in a single triangle
	    int t_rows;	//number of rows for a single triangle
	    int increment;	// increment keeps count of numbers per row
	    for (int k = 0; k < numPeaks; k++) {
	    	max = 2(heights[k]) - 1;
	    	t_rows = heights[k];
	    	for(int h = rows; h >= t_rows; h--) {
	    		increment = 0;
	    		j = next_triangle;
                while (increment <= max) {
                    triangle[h][] = increment;
                    increment++;
                    max = max - 2;
                }
	    	}
	    }
	    // holds the value of the beginning of the next triangle
	    next_triangle = next_triangle + ;
	}
}

/* Print a mountain consisting of numPeaks triangles.
 * @param numPeaks: number of mountain peaks
 * @param heights: an array of heights with numPeak elements
 * @param triangles: an array of triangles
 */
void printNumberMountain(const int numPeaks, int *heights, int ***triangles) {
	int rows = 0;	// holds number of rows in triangle
	int columns = 0;	// holds number of columns in trianlges


	// figure out what the max height is of the peaks so we know the number of rows
	for (int i = 0; i < numPeaks; i++) {
		if (rows < heights[i]) {
			rows = heights[i];
			printf("%s%d\n", "rows: ", rows);
		}
	}
	// figure out number of columns needed
	for (int j = 0; j < numPeaks; ++j) {
		columns = columns + (2*heights[j] - 1);
		printf("%s%d\n", "columns: ", columns);
	}

	//	traverse through the array to print spaces or numbers that were initialized
	// in the array
	for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
                if (*triangles[r][c] == -1) {
                        printf("%s", " ");
                } else {
                        printf("%d", *triangles[r][c]);
                }
        }
        printf("\n");   //go to the next row
    }
}

/* Free the memory for the 2-D triangle array */
void deallocateNumberTriangle(const int numPeaks, int *heights, int ***triangles){
	for (int i = 0; i < numPeaks; i++) {
		free((*triangles)[i]);
	}

	free(*triangles);
	*triangles = NULL;	//make sure *triangle is no longer pointing to anything
}


int main() {
	int numPeaks;	// number of mountain peaks
	int* heights;	// an array of heights with numPeak elements
	int** triangles;	// an array of triangles

	//get user input for number of mountain peaks to enter (must be 1-5 inclusive)
	while ((numPeaks > 5) || (numPeaks < 1)) {
		printf("%s", "Please enter the number of peaks [1-5]: ");
		scanf("%d", &numPeaks);
	}
	printf("%d\n", numPeaks);

	heights = (int *) malloc (numPeaks * sizeof(int) );
	//intialize all elements of height to 0;
	for (int i = 0; i < numPeaks; i++){
		heights[i] = 0;
	}

	// take in the user input for heights of triangles
	int i = 0;
	printf("Please enter the heights of the peaks [each should be between 1 and 5]: ");	
	//char a[100];
	// STDIN means standard input which is keyboard
	/*
	fgets(a, sizeof(a), stdin); 
   	char *p = strtok(a, " ");
   	while (p != NULL) {
    	heights[i++] = atoi(p);
    	p = strtok(NULL, " ");
	}
	*/

	// initialize the heights user gave
	for (int j = 0; j < numPeaks; j++){
		printf("%s%d %d ", "height ", j, heights[j]);
	}

	// call functions
	allocateNumberTriangle((const int) numPeaks, heights, &triangles);
 	initializeNumberTriangle( (const int) numPeaks, heights, triangles);
	printNumberMountain((const int) numPeaks, heights, &triangles);
	deallocateNumberTriangle((const int) numPeaks, heights, &triangles);

	return 0;
}

