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
"""
size = input()
matrix = []

# reading input
for _ in xrange(size):
    row = map(int, raw_input().split())
    matrix.append(row)

# initialize s1 for right diagonal and s2 for left diagonal
s1, s2 = 0, 0

# summing up together in just 1 loop, -ve index
# (-x) in python is actually (size - x)
for i in xrange(size):
    s1 += matrix[i][i]
    s2 += matrix[-i-1][i]

# printing absolute difference
print abs(s1 - s2)
"""
    
if __name__ == "__main__":
    n = int(raw_input().strip())
    a = []
    for a_i in xrange(n):
        a_temp = map(int,raw_input().strip().split(' '))
        a.append(a_temp)
    result = diagonalDifference(a)
    print result
