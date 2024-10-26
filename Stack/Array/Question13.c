#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void copyStackUser(stack *ps1, stack *ps2){
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

int main8(){
    stack s1, s2;
    initiateStack(&s1);
    initiateStack(&s2);

    push('c', &s1);
    push('b', &s1);
    push('a', &s1);

    copyStackUser(&s1, &s2);
    printf("Size of the second stack is %d", getStackSize(&s2));

}
