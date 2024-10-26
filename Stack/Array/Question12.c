#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void destroyStack(stack *ps){
    int size = getStackSize(ps);
    for(int i = 0; i < size; i++) pop(ps);
}

int main7(){
    stack stack1;
    initiateStack(&stack1);

    push('a', &stack1);
    push('b', &stack1);
    push('c', &stack1);

    printf("Stack size before destroying %d\n", getStackSize(&stack1));
    destroyStack(&stack1);
    printf("Stack size after destroying: %d", getStackSize(&stack1));

}
