#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int func4(){
    stack s1, s2;
    initiateStack(&s1);
    initiateStack(&s2);

    push('c', &s1);
    push('b', &s1);
    push('a', &s1);

    copyStack(&s1, &s2);
    printf("Size of the second stack is %d", getStackSize(&s2));
}
