#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileHandling.h"

int main(){
    FILE* ifptr = fopen("input.txt", "r");
    FILE* ofptr = fopen("output.txt", "w");
    if(ifptr == NULL){
        return 0;
    }
    int noOfWords = fgetNoOfWords(ifptr);
    char* str;
    for(int i = 0; i<noOfWords; i++){
        str = nextWord(ifptr);
        if(strcmp(str,"a") == 0 || strcmp(str,"an") == 0 || strcmp(str,"the") == 0){
            continue;
        }
        fprintf(ofptr, "%s %c", str, fgetPreviousChar(ifptr));
    }
    fclose(ofptr);
    fclose(ifptr);
}