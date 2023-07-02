//inthis we simulate stack we push character while not reach at space or new linw character

#include <stdio.h>

int main(){
    FILE* ifptr = fopen("input.txt", "r");
    if(ifptr == NULL){
        return 0;
    }
    int top = 0;
    char stack[10];
    for(char c = fgetc(ifptr); c != EOF; c = fgetc(ifptr)){
        if(c == ' ' || c == '\n'){
            while( top != 0 ){
                top--;
                printf("%c", stack[top]);
            }
            printf("%c", c);
        }else{
            stack[top] = c;
            top++;
        }
    }
    if(top!=0){
        while( top != 0 ){
            top--;
            printf("%c", stack[top]);
        }
    }
    fclose(ifptr);
}