#include "5_6.h"
#include <iostream>
using namespace std;

/*
Overload the function Multiply written in the previous exercise so that it
may be used to multiply:
1. a vector and a matrix of given sizes;
2. a matrix and a vector of given sizes;
3. a scalar and a matrix of a given size; and
4. a matrix of a given size and a scalar.

*/

// matrix multiplication
void Multiply(double **res, double **A, double **B, int ARows, int ACols, int BRows, int BCols)
{
    if (ACols == BRows)
    {
        for (int i = 0; i < ARows; i++)
        {
            for (int j=0; j <BCols; j++)
            {
                for (int k=0; k<ACols; k++)
                {
                    res[i][j] = res[i][j] + A[i][k] * B[k][j];
                }
            }
        }
    } else {cout << "Wrong dimensions.";}
}

// 1. a vector (A) and a matrix (B) of given sizes;
void Multiply(double *res, double *A, double **B, int ACols, int BRows, int BCols)
{
    if (ACols == BRows)
    {
        for (int i = 0; i < ACols; i++)
        {
            for (int j = 0; j < BRows; j++)
            {
                res[j] += A[i] * B[i][j];
            }
        }
    } else {cout << "Wrong dimensions.";}
}



// 2. a matrix A and a vector B
void Multiply(double *res, double **A, double *B, int ARows, int ACols, int BRows)
{
    if (ACols == BRows)
    {
        for (int i = 0; i < ARows; i++)
        {
            for (int j = 0; j < ACols; j++)
            {
                res[i] += A[i][j] * B[j];
            }
        }
    } else {cout << "Wrong dimensions.";}
}





// 3. a scalar and a matrix of a given size

void Multiply(double **res, double scalar, double **B, int BRows, int BCols)
{
	for (int i = 0; i < BRows; i++)
	{
		for (int j=0; j < BCols; j++)
		{
			res[i][j] = scalar * B[i][j];
		}
	}
}





// 4. a matrix of a given size and a scalar.
void Multiply(double **res, double **B, double scalar, int BRows, int BCols)
{
	for (int i = 0; i < BRows; i++) 
	{
		for (int j=0; j< BCols; j++)
		{
			res[i][j] = scalar * B[i][j];
		}
	}
}


double** AllocateMemory(int rows, int cols)
{
	double** A = new double* [rows];
	
	for (int i = 0; i < rows; i++)
	{
		A[i] = new double [cols];
	}
	
	return A;
}


void FreeMemory(double** A, int rows_A)
{
	for (int i = 0; i < rows_A; i++)
	{
		delete[] A[i];
	}
	delete[] A;
}




// Need this for compiling remove later

/*

int main(int argc, char* argv[])
{
	double scalar = 3.0;

	// defining a matrix A
	int ARows = 2, ACols = 2;
	double** A = AllocateMemory(ARows, ACols);
	A[0][0] = 5.0; A[0][1] = 3.0; A[1][0] = 2.0; A[1][1] = 2.0;
	

	// defining a matrix B
	int BRows = 2, BCols = 2;
	double** B = AllocateMemory(BRows, BCols);
	B[0][0] = 1.0; B[0][1] = 1.0; B[1][0] = 1.0; B[1][1] = 1.0;
	
	
	// defining result vector
	int length = 2;
	double* res1 = new double [length];
    double* A1 = new double [length];
    A1[0] = 2; A1[1] = 2;
    
    // 1. vector A1 multiplied by matrix
	Multiply(res1, A1, B, ACols, BRows, BCols);
    
    cout<< "\nVector A1 multiplied by matrix B:\n" ;
    for (int i = 0; i < length; i++)
    {
        cout<< " " << res1[i] << " ";
        cout<< "\n";
    }
    cout<< "\n";
    
    delete[] res1;
    delete[] A1;
    // correct 16 22

    
	// 2.
    int lengthB = 2;
    double* B1 = new double [lengthB];
    double* res3 = new double [lengthB];
    B1[0] = 3; B1[1] = 7;
    Multiply(res3, A, B1, ARows, ACols, BRows);

    // print Result matrix
    cout<< "Matrix A multiplied by a vector B1:\n" ;
    for (int i = 0; i < length; i++)
    {
        cout<< " " << res3[i] << " ";
        cout<< "\n";
    }
    cout<< "\n";
    
    delete[] B1;
    delete[] res3;
    
    
    // 36 20 correct!!!!

    
	// 3 .  // scalar times matrix
	// defining a result matrix
	//int RRows = 2, RCols = 2;
	//double** res = AllocateMemory(RRows, RCols);
	//Multiply(res, scalar, B, BRows, BCols);


	// 4. 
	//Multiply(res, B, scalar, BRows, BCols);

    
    // matrix multiplication
    //double** res2 = AllocateMemory(RRows, RCols);
    //Multiply(res2, A, B, ARows, ACols, BRows, BCols);
    

	// free the memory
	FreeMemory(A, ARows);
	FreeMemory(B, BRows);
	//FreeMemory(res, RRows);
    //FreeMemory(res2, RRows);
	
	return 0;
} 


*/
