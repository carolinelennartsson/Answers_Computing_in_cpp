#include "5_3.h"
#include <iostream>
#include <cmath>


/*
5.3 Write a function that swaps the values of two double precision floating point
numbers, so that these changes are visible in the code that has called this function.
1. Write this function using pointers.
2. Write this function using references.
*/


//  Function with pointers
void swap_pointer(double *a, double *b) {
	double temp;
	temp = *a; 
	*a = *b;
	*b = temp;  
}


// Function using references 
void swap_ref(double& a, double& b) {
        double temp;
        temp = a;
        a = b;
        b = temp;
}



// Need this for compiling remove later

/*

int main(int argc, const char * argv[]) {
	
	double* a;
	double* b; 

	a = new double; 
	b = new double; 

	*a = 3; 
	*b = 7; 
	
	// calling the functions
	std::cout << "Before:" << *a << " " << *b << "\n";
	swap_pointer(a, b);
	std::cout << "After:" << *a << " " << *b << "\n";
 	
	double c = 4, d = 8;
	std::cout << "Before:" << c << " " << d << "\n";
	swap_ref(c, d);
	std::cout << "After 2x:" << c << " " << d << "\n";	

	return 0;
}

*/

