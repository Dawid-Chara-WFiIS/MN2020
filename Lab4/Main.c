#include <stdio.h>
#include <stdlib.h>
#include "nr.h"
#include "nrutil.h"


#define N 750


int main()
{
    double **A, *newX, *oldX, *b, *ptr;
    double amp = 1, vel = 0, k=2, sum, t = 2*3.1415, tMax = k*t;
    double omega = 1, h = tMax/1001;
   	double val = omega * omega * h * h - 2;
    newX = dvector(1, N);
    oldX = dvector(1, N);
    b = dvector(1, N);
    A = dmatrix(1, N, 1, N);
    // build vectors
    for(unsigned i=1; i<=N; i++)
    {
        oldX[i] = 0;
        b[i] = 0;
    }
    b[1] = amp;
    b[2] = vel*h;
    // build matrix A
    for(unsigned i=1; i<=N; i++)
    {
        for(unsigned j=1; j<=N; j++)
        {
            A[i][j] = 0;
        }
    }
    for(unsigned i=3; i<=N; i++)
    {
        A[i][i] = 1;
        A[i][i-1] = val;
        A[i][i-2] = 1;
    }
    A[1][1] = 1;
    A[2][1] = -1;
    A[2][2] = 1;

    unsigned n = 1000;
    for (unsigned k = 0; k < n; k++)
    {
        for(int i = 1; i <= N; i++)
        {
          	sum = 0;
          	for(int j = 1; j <= N; j++)
          	{
                if(j != i)
                {
                    sum += A[i][j] * oldX[j];
                }
          	}
        newX[i] = b[i] - sum;
        }
        ptr = oldX;
        oldX = newX;
        newX = ptr;
    }
    for(int i = 1; i <= N; ++i)
    {
        printf("%g, %g\n", h*(i-1), oldX[i]);
    }

    free_dmatrix(A, 1, N, 1,N);
    free_dvector(b, 1, N);
	free_dvector(oldX, 1, N);
	free_dvector(newX, 1, N);
	
}