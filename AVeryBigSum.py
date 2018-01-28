#!/bin/python

import sys

def aVeryBigSum(n, ar):
    # Complete this function
    #5
    #1000000001 1000000002 1000000003 1000000004 1000000005
    sum = 0
    for count in range(n):
        sum += ar[count]
    return sum

n = int(raw_input().strip())
ar = map(long, raw_input().strip().split(' '))
result = aVeryBigSum(n, ar)
print(result)
