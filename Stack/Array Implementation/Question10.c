#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

char getFirstElementEntered(stack *s1){

    int n;
    char firstElement;
    printf("Enter the number of elements you want to push (Max 5): ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char el;
        printf("Enter character %d: ", i+1);
        scanf(" %c", &el);
        push(el, s1);
        if(getStackSize(s1) == 1) firstElement = peekByVal(s1);
    }
    return firstElement;
}

int main5(){
    stack s1;
    initiateStack(&s1);

    char firstElement = getFirstElementEntered(&s1);
    printf("First element is %c", firstElement);
}
