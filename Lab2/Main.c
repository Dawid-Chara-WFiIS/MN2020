#include <stdio.h>
#include <stdlib.h>
#include "nrutil.h"
#include "nr.h"


int main()
{
    float** a = matrix(1, 4, 1, 4);
    float** b = matrix(1, 4, 1, 1);


float a_temp[4][4] = {{10, 7, 8, 7}, {7, 5, 6, 5}, 
{8, 6, 10, 9}, {7, 5, 9, 10}};
float b_temp[4][1] = {{32}, {23}, {33}, {31}}; 
for (int i=0; i<4; i++)
{
    for(int j=0; j<4; j++)
    {
        a[i+1][j+1] = a_temp[i][j];
    }
    b[i+1][1] = b_temp[i][0];
}
gaussj(a, 4, b, 1); 
for(int i=1; i<5; i++)
    printf("%g ", b[i][1]);

float max = 0;
for(int i=1; i<5; i++)
{
    for(int j=1; j<5; j++)
        if(max < a[i][j])
            max = a[i][j];
}
printf("\n%g\n", max*10*16);
free_matrix(a, 1, 4, 1, 4);
free_matrix(b, 1, 4, 1, 1);

}
