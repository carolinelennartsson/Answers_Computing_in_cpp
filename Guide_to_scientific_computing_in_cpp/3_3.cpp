#include "3_3.h"
#include <fstream> // enables reading and writng files
#include <iostream>
using namespace std;
#include <cstdlib> // atof converting to double


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
            y[i] = y[i-1]/(1 + h);
            write_file << x[i] << ", " << y[i] << "\n";
        }

        write_file.close();
        
    } else {
        cout << "N is smaller than 0.";
    }

}


int main(int argc, char * argv[]) {

    int n = 10000;
    implicit_Euler(n);
    
    return 0;
}
