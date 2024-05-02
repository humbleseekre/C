Certainly! A variadic function in C allows you to handle a variable number of arguments. It’s particularly useful when you want to create functions that can accept different numbers of parameters. Here’s how you can write a variadic function in C:

Syntax:
A variadic function has at least one fixed argument, followed by an ellipsis (...) as the last parameter.
The fixed argument(s) provide context for the variable arguments.
The header file <stdarg.h> provides the necessary tools for working with variadic functions.
Steps to Create a Variadic Function:
Define your function with the fixed argument(s) and the ellipsis.
Use the following macros from <stdarg.h>:
va_list: A type representing the variable argument list.
va_start(ap, argN): Initializes the va_list to access the variable arguments.
va_arg(ap, type): Retrieves the next argument of the specified type.
va_end(ap): Cleans up after using the variable arguments.
Example 1: Sum of Integers:
#include <stdarg.h>
#include <stdio.h>

int AddNumbers(int n, ...) {
    int Sum = 0;
    va_list ptr;
    va_start(ptr, n);
    for (int i = 0; i < n; i++)
        Sum += va_arg(ptr, int);
    va_end(ptr);
    return Sum;
}

int main() {
    printf("Sum of 1 + 2 = %d\n", AddNumbers(2, 1, 2));
    printf("Sum of 3 + 4 + 5 = %d\n", AddNumbers(3, 3, 4, 5));
    printf("Sum of 6 + 7 + 8 + 9 = %d\n", AddNumbers(4, 6, 7, 8, 9));
    return 0;
}
Output:
Sum of 1 + 2 = 3
Sum of 3 + 4 + 5 = 12
Sum of 6 + 7 + 8 + 9 = 30

Example 2: Finding the Largest Number:
#include <stdarg.h>
#include <stdio.h>

int LargestNumber(int n, ...) {
    va_list ptr;
    va_start(ptr, n);
    int max = va_arg(ptr, int);
    for (int i = 0; i < n - 1; i++) {
        int temp = va_arg(ptr, int);
        max = (temp > max) ? temp : max;
    }
    va_end(ptr);
    return max;
}

int main() {
    printf("Largest number: %d\n", LargestNumber(2, 1, 2));
    printf("Largest number: %d\n", LargestNumber(3, 3, 4, 5));
    printf("Largest number: %d\n", LargestNumber(4, 6, 7, 8, 9));
    return 0;
}
Output:
Largest number: 2
Largest number: 5
Largest number: 9

Remember to include <stdarg.h> and follow the conventions for accessing the variable arguments using va_arg. Variadic functions provide flexibility and allow you to handle different argument counts effectively!
