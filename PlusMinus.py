#!/bin/python

import sys

def plusMinus(arr):
    # Complete this function
    pos = neg = zer = 0
    len1 = len(arr)
    for x in range(len(arr)):
        if (arr[x] > 0):
            pos += 1
        if (arr[x] < 0):
            neg += 1
        if (arr[x] == 0):
            zer += 1
    print"%f\n%f\n%f\n" %(pos/float(len1), neg/float(len1), zer/float(len1))

if __name__ == "__main__":
    n = int(raw_input().strip())
    arr = map(int, raw_input().strip().split(' '))
    plusMinus(arr)
