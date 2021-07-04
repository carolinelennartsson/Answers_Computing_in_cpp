#include "5_4.h"
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;


double calc_mean(double u[], int n)
{
	double mean = 0.0;
	
	for (int i = 0; i < n; i++)
	{
		mean += u[i];
	}
	
	mean = mean / (double)(n);
	
	return mean;
}


double calc_std(double u[], int n)
{
	double sd = 0.0;
	double mean = calc_mean(u, n);
	
	for (int i = 0; i < n; i++)
	{
		sd += pow((u[i] - mean), 2.0);
	}
	
	// not divide by zero when the length is 1
    if (n-1 != 0)
    {
        sd /= (double)(n-1);
        sd = sqrt(sd);
    } else {
        cout << "Nobody wants to divide by 0.";
    }
	
	return sd;
}


int main(int argc, char* argv[])
{
	int n = 10;
	double u[n];
	
	cout << "Numbers: ";
	for (int i = 0; i < n; i++)
	{
		u[i] = i;
		std::cout << i;
	}
	
	cout << "\n";

	double mean = calc_mean(u, n);
	double sd = calc_std(u, n);
	
	cout << "Mean of the numbers:" << mean << "\n";
	cout << "Sd of the numbers:" << sd << "\n";
	
	return 0;
}






