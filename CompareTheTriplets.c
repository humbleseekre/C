/*
Alice and Bob each created one problem for HackerRank. A reviewer rates the two challenges, awarding points on a scale from  to  for three categories: problem clarity, originality, and difficulty.

We define the rating for Alice's challenge to be the triplet , and the rating for Bob's challenge to be the triplet .

Your task is to find their comparison points by comparing  with ,  with , and  with .

If , then Alice is awarded  point.
If , then Bob is awarded  point.
If , then neither person receives a point.
Comparison points is the total points a person earned.

Given  and , can you compare the two challenges and print their respective comparison points?

Input Format

The first line contains  space-separated integers, , , and , describing the respective values in triplet . 
The second line contains  space-separated integers, , , and , describing the respective values in triplet .
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* solve(int a0, int a1, int a2, int b0, int b1, int b2, int sum[], int *result_size)
{
    // Complete this function
    int a=0, b=0;
    if(a0 > b0)
    {
        a += 1;
    }
    else if(b0 > a0)
    {
        b += 1;
    }

    if(a1 > b1)
    {
        a += 1;
    }
    else if(b1 > a1)
    {
        b += 1;
    }

    if(a2 > b2)
    {
        a += 1;
    }
    else if(b2 > a2)
    {
        b += 1;
    }
    sum[0] = a;
    sum[1] = b;
    *result_size =2;
    return sum;
}

int main() {
    int a0; 
    int a1; 
    int a2; 
    scanf("%d %d %d", &a0, &a1, &a2);
    int b0; 
    int b1; 
    int b2; 
    scanf("%d %d %d", &b0, &b1, &b2);
    int result_size = 0;
    int sum[2];
    int* result = solve(a0, a1, a2, b0, b1, b2, sum, &result_size);
    for(int result_i = 0; result_i < result_size; result_i++) {
        if(result_i) {
            printf(" ");
        }
        printf("%d", result[result_i]);
    }
    puts("");  

    return 0;
}
