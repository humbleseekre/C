#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int diagonalDifference(int a_size_rows, int a_size_cols, int a[a_size_rows][a_size_cols]) 
{
    // Complete this function
    int sum = 0, i, j;
    int sum2 = 0;
    int result = 0;
    for (i = 0; i < a_size_rows; i++)
    {
        for (j =0; j < a_size_cols; j++)
        {
            if(i == j)
            {
                sum += a[i][j];
            }
        }
    }
    
    for (i = 0; i < a_size_rows; i++)
    {
        for (j =0; j < a_size_cols; j++)
        {
            if ( i + j == (a_size_cols - 1))
            {
                sum2 += a[i][j];
            }
        }
    }
    
    result = (sum - sum2);
    if (result < 0)
    {
        result *= -1;               
    }
    return result;
}

int main() 
{
    int n; 
    scanf("%i", &n);
    int a[n][n];
    for (int a_i = 0; a_i < n; a_i++) {
       for (int a_j = 0; a_j < n; a_j++) {
      
          scanf("%i",&a[a_i][a_j]);
       }
    }
    int result = diagonalDifference(n, n, &a);
    printf("%d\n", result);
    return 0;
}
