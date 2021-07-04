#include "3_3.h"
#include <fstream> // enables reading and writng files
#include <iostream>
using namespace std;
#include <cstdlib> // atof converting to double


/* 
Your code should print a file called xy.dat that has two columns: the
 calculated values of x; and the calculated values of y. Plot the data
 from the file xy.dat and hence compare it with the true solution y =
 e^(−x).
 
 N = number of grid points
 h = step size
 
 
 use an assert statement to ensure that the number of grid points is
 greater than 1.
 Use the number of grid points to calculate the step size h.

*/


void implicit_Euler(int n)
{
    if (n > 0)
    {
        double h = 1.0 / (n);  //h = 1 / (n - 1.0);
        
        double x[n], y[n];
        y[0] = 1.0;
        x[0] = 0;

        std::cout << "Number of grid points = " << n << "\n";
        std::cout << "Step size = " << h << "\n";
        
        std::ofstream write_file("xy.dat");
        write_file << x[0] << ", " << y[0] << "\n";

        for (int i = 1; i < n; i++)
        {
            x[i] = x[i-1] + (1.0 /n);
            //x[i] = i / (n - 1.0);
            y[i] = y[i-1]/(1 + h); // before correction y[i] = y[i - 1]/(1 + h);
            write_file << x[i] << ", " << y[i] << "\n";
        }

        write_file.close();
        
    } else {
        cout << "N is smaller than 0.";
    }

}


// remove this later i guess

/*
int main(int argc, char * argv[]) {

    //int n = atof(argv[1]);
    int n = 10000;
    implicit_Euler(n);

    //int n1=10000;
    //implicit_Euler(n1);
    
    return 0;
} */
