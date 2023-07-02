#include <stdio.h>
#include <stdlib.h>
#include "FileHandling.h"
char* insertNewLineAfterNoOfLine(FILE* ifptr, int n);
int fgetNoOfChars(FILE* ifptr);

int main(){
	FILE* ifptr = fopen("input.txt","r");
	if(ifptr == NULL){
		printf("%s", "File might not be opened");
		return 0;
	}
	char* data = insertNewLineAfterNoOfLine( ifptr, 1);
	fclose(ifptr);
	if(data != NULL){
		FILE* ofptr = fopen("input.txt","w");
		fprintf(ofptr, "%s", data);
		fclose(ofptr);
	}
	return 0;
}

