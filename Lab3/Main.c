#include <math.h>
#include <stdio.h>
#include "nrutil.h"
#include "nr.h"
#define N 11

int main()
{
    float** a = matrix(1, N, 1, N);
    float* y = vector(1, N);
    float* x = vector(1, N);
    int* idx = ivector(1, N);
    float* d = vector(1, N);
    int counter = 1;
    for(float i=-1; i<= 1; i+=0.2)
    {
        x[counter] = i;
        y[counter] = 2*sin(i);
        counter++;
    }
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            a[i][j] = pow(x[i], j-1);
            printf("%g ", a[i][j]);
        }
        printf("\n");
    }
    ludcmp(a, N, idx, d);
    lubksb(a, N, idx, y);
    printf("Polynomial interpolation coefficients:\n");
    for(int i=1; i<=N; i++)
        printf("%g ", y[i]);
}