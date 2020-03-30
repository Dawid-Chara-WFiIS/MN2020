#include <stdio.h>
#include <math.h>
#include "nr.h"
#include "nrutil.h"

#define N 1000

int main(void)
{
	float *d, *e, **z;
	d=vector(1, N);
	e=vector(1, N);
	z=matrix(1, N, 1, N);
	float L = 5;
	float deltaX = 2*L/N;
	float subdiagVal = -1/(2*deltaX*deltaX);

	for(int i = 1;i < N; i++)
    {
        d[i] = 1/pow(deltaX, 2) + pow(-L+i*deltaX, 2)/2;
        if(i+1!= N)
            e[i + 1] = subdiagVal;
        for(int j = 1; j < N; j++)
        {
            if(i == j)
                z[i][j] = 1.0;
            else
                z[i][j] = 0.0;  
        }
    }

	
	tqli(d, e, N, z);
	eigsrt(d, z, N);
    
    printf("Eigenvalues:\n");
    for(int i = 1; i < 6; i++)
    {
	    printf("%g ", d[N-i]);	
	}
    printf("\n-----------------------------------------------------------\n");

    for(int i = 1; i < N; i++)
    {
        for(int j = N-1; j>N-6; j--)
        {
            printf("%f, ",z[i][j]);
        }
        printf("\n");
    }

	free_matrix(z, 1, N, 1, N);
	free_vector(e,1,N-1);
	free_vector(d,1,N-1);
	return 0;
}
