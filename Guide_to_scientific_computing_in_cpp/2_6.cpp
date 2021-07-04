#include <iostream>
#include <math.h>
#include "2_6.h"

// double initialGuess, double epsilon
// create f(x) and f'(x) as seperate functions

double equation(double x) {
    double y = exp(x) + pow(x, 3) - 5;
    
    return y;
}

double derivate(double x) {
    double y = exp(x) + 3 * pow(x, 3);
    return y;
}


double newton_Raphson(double initialGuess, double epsilon)
    {
    // initialise x at 0
    int count = 0;
    
    double x = initialGuess - (equation(initialGuess)/ derivate(initialGuess));
    
    while (epsilon < abs(x - initialGuess))
        
        {
        // update x to be the new value
        initialGuess = x;
        x = initialGuess - (equation(initialGuess)/ derivate(initialGuess));
            
        // print out the x value for each iteration
        count++;
        std::cout << "Iteration: " << count << ", x :" << x << "\n";
        }
    
    return x;
    
    }


// Need this for compiling remove later 

/*
int main(int argc, const char * argv[]) {
    double result = newton_Raphson(0, 0.0001);
    std::cout << "Result Newton Raphson algorithm: " << result << "\n";
    return 0;
}*/

