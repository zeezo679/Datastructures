#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>
#include "functions.h"


int main()
{
    char input[50];
    gets(input);
    int SemiColonPosition = checkColonPresence(input);

    if(SemiColonPosition == -1) printf("N\n");
    else if(SemiColonPosition != -1){
        int Length1 = getLength1(SemiColonPosition, input);
        int Length2 = getLength2(SemiColonPosition, input);

        if(Length1 > Length2)
            printf("L\n");
        else if(Length2 > Length1)
            printf("R\n");
        else if(Length1 == Length2){
            int Difference = CheckDifference(SemiColonPosition, input);
            int palindrome = isPalindrome(SemiColonPosition, input);
            if(Difference == -1 && !palindrome) printf("D\n");
            else if(Difference && !palindrome) printf("S\n");
            else if(palindrome) printf("M\n");
        }
    }
}

