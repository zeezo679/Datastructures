#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int func2(){
    stack stack1, stack2;
    initiateStack(&stack1);
    initiateStack(&stack2);

    push('a', &stack1);
    push('b', &stack1);
    push('c', &stack1);

    //printing elements from the stack and pushing it to the second stack
    for(int i = 0; i < 3; i++){
        char element = pop(&stack1);
        push(element, &stack2);
        printf("%c ", element);
    }

    //returning popped elements to stack in correct order
    for(int i = 0; i < 3; i++){
        char element = pop(&stack2);
        push(element, &stack1);
    }
}
