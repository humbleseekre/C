#ifndef GENERIC_STACK_H
#def GENERIC_STACK_H

typedef unsigned char byte;

typedef struct Stack{
  int top;
  byte *storage;
  int elemSize;
  int maxElements;
} Stack;

/* Function to initialize the Stack */
void init(Stack *s, int elemSize, int maxElements);

/* Function for checking if stack is empty */
/* Returns 1 if stack is non empty, 0 if non empty */
int isEmpty(Stack* s);

/* Function for returning number of elements in the stack*/
int size(Stack *s);

/* Inserts an element at the top of the stack */
/* Returns 0 if successfull, -1 if not successful */
int push(Stack *s, void *elem);

/* Removes an element at the top of the stack */
/* Returns 0 if successful, -1 if not successful */
int pop(Stack *s);

/* Returns a pointer to the top element without removing it from the stack */
void* top(Stack *s);

/* Deallocates the memory allocated to stack*/
void destroy(Stack *s);

#endif
