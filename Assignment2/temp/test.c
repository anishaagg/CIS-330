//Anisha Aggarwal       CIS330  Assignment 2    test.c

//Impliment main()

#include <stdio.h>
#include "triangle.h"

int main() {
        int **triangle;
        int height = 0;
	
	// print a 5x9 triangle
	print5Triangle();
      
	//get user input for height of triangle
	while ((height < 1) || (height > 5)) {
		printf("%s", "Please enter the height of the triangle [1-5]: ");
        	scanf("%d", &height);	
	} 

	// dynamically allocte space based on user input for triangle size 
	allocateNumberTriangle((const int) height, &triangle);
	initializeNumberTriangle((const int) height, triangle);
	printNumberTriangle((const int) height, triangle);
	deallocateNumberTriangle((const int) height, &triangle);
        
	return 0;
}


