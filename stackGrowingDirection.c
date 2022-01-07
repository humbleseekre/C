/*
The idea is to do following :
1) Make a local variable in main.
2) Write another function fun() with its own local variable.
3) Make a call to fun() from main. Compare addresses of two local variable. If address of fun()’s local variable is more than main’s local variable, then stack grows upward (i.e., addresses increase)
*/

// C program to check whether stack grows
// downward or upward.
#include<stdio.h>
  
void fun(int *main_local_addr)
{
    int fun_local;
    if (main_local_addr < &fun_local)
        printf("Stack grows upward\n");
    else
        printf("Stack grows downward\n");
}
  
int main()
{
    // fun's local variable
    int main_local;
  
    fun(&main_local);
    return 0;
}
