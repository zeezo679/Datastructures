#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//question, 1, 2, 3
void displayMenu(){
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Get size\n");
    printf("4. Exit\n");
}

int func()
{
    stack myStack;
    initiateStack(&myStack);
    displayMenu();
    int userChoice = -1;
    while(userChoice != 3)
    {
        printf("Enter the operation number: ");
        scanf("%d", &userChoice);
        if(userChoice == 1)
        {
            char el;
            printf("Enter the character: ");
            scanf(" %c", &el);
            push(el, &myStack);
        }

        else if(userChoice == 2){
            if(!isStackEmpty(&myStack)) printf("Element popped : %c\n", pop(&myStack));
            else printf("Stack is empty, There is no element to pop\n");
        }
        else if(userChoice == 3) printf("Size of your stack is %d\n", getStackSize(&myStack));

        else if(userChoice == 4) break; //exit

    }
}
