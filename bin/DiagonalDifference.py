#!/bin/python

import sys

def diagonalDifference(a):
    # Complete this function
    sum = 0
    sum2 = 0
    for i in range(len(a)):
        for j in range(len(a)):
            if (i == j):
                sum += a[i][j]
    for i in range(len(a)):
        for j in range(len(a)):
            if ((i + j) == (len(a) - 1)):
                sum2 += a[i][j]
    return abs(sum - sum2)
    
if __name__ == "__main__":
    n = int(raw_input().strip())
    a = []
    for a_i in xrange(n):
        a_temp = map(int,raw_input().strip().split(' '))
        a.append(a_temp)
    result = diagonalDifference(a)
    print result
