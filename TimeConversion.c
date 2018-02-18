/*
Given a time in -hour AM/PM format, convert it to military (-hour) time.

Note: Midnight is  on a -hour clock, and  on a -hour clock. Noon is  on a -hour clock, and  on a -hour clock.

Input Format

A single string containing a time in -hour clock format (i.e.:  or ), where  and .

Output Format

Convert and print the given time in -hour format, where .

*/
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* timeConversion(char* s) 
{
    // Complete this function
    int h1 = (int)s[1] - '0'; //7
    int h2 = (int)s[0] - '0'; //0
    int hh = (h2 * 10 + h1 % 10); //7

    hh = hh % 12;
    if ( s[8] == 'P')
    {
        hh += 12; // hh = 19
    }
    s[8] = '\0';
    s[0] = (hh / 10) + '0' ;
    s[1] = (hh % 10) + '0' ;
    return s;    
}

int main() {
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s", s);
        int result_size;
char* result = timeConversion(s);
    printf("%s\n", result);
    return 0;
}
