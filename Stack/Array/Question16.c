#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

bool isValid(char string[]){
    stack s1;
    initiateStack(&s1);
    for(int i = 0; i < strlen(string); i++){
        if(string[i] == '(' || string[i] == '[' || string[i] == '{')
            push(string[i], &s1);

        else if((string[i] == ')' && peekByVal(&s1) == '(') || (string[i] == ']' && peekByVal(&s1) == '[') || (string[i] == '}' && peekByVal(&s1) == '{')){
               if(!isStackEmpty(&s1))
                        pop(&s1);
        }
    }
    if(isStackEmpty(&s1)) return true;
    else return false;
}

void display(char el){
    printf("%c", el);
}

int main(){
    char string[] = "{()}";
    bool ans = isValid(string);
    if(ans) printf("Valid\n");
    else printf("Not Valid\n");
}
