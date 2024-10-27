#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include <string.h>

int checkColonPresence(char string[]){
    int size = strlen(string);
    for(int i = 0; i < size; i++){
        if(string[i] == ':') return i;
    }
    return -1;
}

int getLength1(int pos, char string[]){
    queue q;
    createQueue(&q);
    for(int i = 0; i < pos; i++) enqueue(string[i], &q);
    return queueSize(&q);
}

int getLength2(int pos, char string[]){
    queue q;
    createQueue(&q);
    int size = strlen(string);
    for(int i = pos+1; i < size; i++) enqueue(string[i], &q);
    return queueSize(&q);
}

int CheckDifference(int pos, char string[]){
    queue q1;
    createQueue(&q1);
    for(int i = 0; i < pos; i++) enqueue(string[i], &q1);

    queue q2;
    createQueue(&q2);
    int size = strlen(string);
    for(int i = pos+1; i < size; i++) enqueue(string[i], &q2);

    int queueSizeVal = queueSize(&q2); //you can get the size of any queue

    for(int i = 0; i < queueSizeVal; i++){
        char El1 = dequeue(&q1);
        char El2 = dequeue(&q2);
        if(El1 != El2) return -1;
    }
    return 1;
}

int isPalindrome(int pos, char string[]){
    stack s;
    initiateStack(&s);
    for(int i = 0; i < pos; i++) push(string[i], &s);

    int size = strlen(string);
    for(int i = pos+1; i < size; i++){
        if(peekByVal(&s) == string[i]){
            pop(&s);
        }
    }
    if(isStackEmpty(&s)) return 1;
    return 0;
}

#endif // FUNCTIONS_H_INCLUDED
