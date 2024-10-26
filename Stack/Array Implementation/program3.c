#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//using the peek() function
int func3(){
    stack stack1;
    initiateStack(&stack1);

    push('a', &stack1);
    push('b', &stack1);
    push('c', &stack1);

    char el;
    peekByRef(&stack1, &el);
    printf("%c \n", el);
    peekByRef(&stack1, &el);
    printf("%c \n", el);
    char ch = peekByVal(&stack1);
    printf("%c ", ch);
}
