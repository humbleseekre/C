/*
A queue is an abstract data type that maintains the order in which elements were added to it, allowing the oldest elements to be removed from the front and new elements to be added to the rear. This is called a First-In-First-Out (FIFO) data structure because the first element added to the queue (i.e., the one that has been waiting the longest) is always the first one to be removed.

A basic queue has the following operations:

Enqueue: add a new element to the end of the queue.
Dequeue: remove the element from the front of the queue and return it.
In this challenge, you must first implement a queue using two stacks. Then process  queries, where each query is one of the following  types:

1 x: Enqueue element  into the end of the queue.
2: Dequeue the element at the front of the queue.
3: Print the element at the front of the queue.
Input Format

The first line contains a single integer, , denoting the number of queries. 
Each line  of the  subsequent lines contains a single query in the form described in the problem statement above. All three queries start with an integer denoting the query , but only query  is followed by an additional space-separated value, , denoting the value to be enqueued.

Constraints

It is guaranteed that a valid answer always exists for each query of type .
Output Format

For each query of type , print the value of the element at the front of the queue on a new line.

Sample Input

10
1 42
2
1 14
3
1 28
3
1 60
1 78
2
2
Sample Output

14
14
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct s_listnode
{
    int element;
    struct s_listnode *pnext;
};

struct s_listnode *queue_buffer = NULL;
struct s_listnode *prear = NULL;

void enqueue(int elem)
{
    struct s_listnode *new_node = (struct s_listnode*)malloc(sizeof(struct s_listnode));
    new_node->element = elem;
    new_node->pnext = NULL;
    if(prear)
    {
        prear->pnext = new_node;
    }
    else
    {
        queue_buffer = new_node;
    }
    prear= new_node;
}

int dequeue(void)
{
    if(queue_buffer)
    {
        struct s_listnode *pelem = queue_buffer;
        int elem = queue_buffer->element;
        queue_buffer = pelem->pnext;
        if(pelem == prear)
        {
            prear = NULL;
        }
        free(pelem);
        return elem;
    }
    return 0;
}


int main() 
{
    /*
    1  x: Enqueue element  into the end of the queue.
    2: Dequeue the element at the front of the queue.
    3: Print the element at the front of the queue.
    */
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int numOfQueries, typeofEntry,enqElem;
    scanf("%d", &numOfQueries);
    while(numOfQueries)
    {
        scanf("%d", &typeofEntry);
        if(typeofEntry == 1)
        {
            scanf("%d", &enqElem);  
            enqueue(enqElem);
        }
        else if(typeofEntry == 2)
        {
            dequeue();    
        }
        else if(typeofEntry == 3)
        {
            printf("%d\n", (int)(queue_buffer->element));            
        }
        numOfQueries--;
    }
    
    return 0;
}
