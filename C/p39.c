#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FileHandling.h"

int main(){
    FILE* ifptr = fopen("input.txt", "r");
    if(ifptr == NULL){
        return 0;
    }
    int noOfWords = fgetNoOfWords(ifptr);
    char** words = malloc(noOfWords*100*sizeof(char));
    char* str;
    str = nextWord(ifptr);
    for(int i=0;i<noOfWords; i++){
        if(str == NULL){
            break;
        }
        words[i] = str;
        str = nextWord(ifptr);
    }

    for(int i = 0; i<noOfWords-1; i++){
        for(int j = 0; j<noOfWords - i - 1; j++){
            if(strcmp(words[j],words[j+1]) > 0){
                str = words[j+1];
                words[j+1] = words[j];
                words[j] = str;
            }
        }
    }
    for(int i=0; i<noOfWords; i++){
        printf("%s\n", words[i]);
    }

    fclose(ifptr);
    return 0;
}