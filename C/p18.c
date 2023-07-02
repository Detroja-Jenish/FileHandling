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
	char* data = insertNewLineAfterNoOfLine( ifptr, 7);
	fclose(ifptr);
	if(data != NULL){
		FILE* ofptr = fopen("input.txt","w");
		fprintf(ofptr, "%s", data);
		fclose(ofptr);
	}
	return 0;
}

//int fgetNoOfChars(FILE* ifptr){
//	if(ifptr == NULL){
//		return 0;
//	}
//	if(ftell(ifptr) != 0){
//		rewind(ifptr);
//	}
//	int count;
//	char c;
//	for(count = 0, c = fgetc(ifptr); c != EOF; c = fgetc(ifptr), count++){
//	}
//	rewind(ifptr);
//	return 0;
//}
//
//char* insertNewLineAfterNoOfLine(FILE* ifptr, int n){
//	if(ifptr == NULL){
//		return NULL;
//	}
//	int noOfChars =  fgetNoOfChars(ifptr);
//	char* data = malloc((noOfChars+5)*sizeof(char));
//	int dataPointer = 0;
//	char c;
//	int count = 0;
//	if(ftell(ifptr) != 0){
//		rewind(ifptr);
//	}
//	for(c = fgetc(ifptr); c != EOF; c = fgetc(ifptr)){
//		if(dataPointer == noOfChars - 5){
//			data = realloc(data, (noOfChars + 30)*sizeof(char));
//			noOfChars += 30;
//		}
//		data[dataPointer] = c;
//		dataPointer++;
//		if(c == '\n'){
//			count++;
//		}
//		if(count == n){
//			count = 0;
//			data[dataPointer] = '\n';
//			dataPointer++;
//		}
//	}
//	data[ dataPointer ] = '\0';
//	rewind( ifptr );
//	return data;
//}
