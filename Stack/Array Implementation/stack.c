#include "stack.h"


void initiateStack(stack *ps){
    ps->top = 0;
    ps->size = 0;
}

void push(stackEntry element, stack *ps){
    ps->entry[ps->top++] = element;
    ps->size++;
}

stackEntry pop(stack *ps){
    ps->size--;
    return ps->entry[--ps->top];
}

void peekByRef(stack *ps, stackEntry *pel){
    stackEntry ch = ps->entry[ps->top-1];
    *pel = ch;
}

stackEntry peekByVal(stack *ps){
   return ps->entry[ps->top - 1];
}

int getStackSize(stack *ps){
    return ps->size;
}

int isStackEmpty(stack *ps){
    return !ps->size;
}

void clearStack(stack *ps){
    ps->top = 0;
    ps->size = 0;
}

void copyStack(stack *ps1, stack *ps2){
    stack *tempStack;
    initiateStack(&tempStack);

    int stackSize1 = getStackSize(ps1);
    for(int i = 0; i < stackSize1; i++){
        char element = pop(ps1);
        push(element, &tempStack);
    }
    for(int i = 0; i < stackSize1; i++){
        char element = pop(&tempStack);
        push(element, ps2);
    }
}

void traverseStack(stack *ps, void(*pf)(fun)){
    for(int i = 0; i < getStackSize(ps); i++){
        (*pf)(ps->entry[i]);
    }
}
