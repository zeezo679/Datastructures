#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define MAX_SIZE 5
typedef char stackEntry;

typedef struct Stack{
    int size;
    int top;
    stackEntry entry[MAX_SIZE];
}stack;


void initiateStack(stack *);
void push(stackEntry, stack *);
stackEntry pop(stack *);
int getStackSize(stack *);
void peekByRef(stack *, stackEntry *); //get the top of stack without popping (by reference)
stackEntry peekByVal(stack *); //by value
int isStackEmpty(stack *);
void clearStack(stack *);
void copyStack(stack *, stack *);
void traverseStack(stack *, void(*pf)(fun));

#endif // STACK_H_INCLUDED
