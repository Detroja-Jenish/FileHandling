//just like previous problem travers eeach and every character if and there in \n character without any char (whitespace and tabs are not considered in chars)

#include <stdio.h>
#include<stdlib.h>
int fgetNoOfChars(FILE* ifptr);
char* deleteBlankLines(FILE* ifptr);

int main(){
	FILE* ifptr = fopen("input.txt", "r");
	if(ifptr == NULL){
		return 0;
	}
	char* data = deleteBlankLines( ifptr );
	fclose(ifptr);

	if(data != NULL){
		FILE* ofptr = fopen("input.txt", "w");
		fprintf(ofptr,"%s",data);
		fclose(ofptr);
	}
	return 0;
}

int fgetNoOfChars(FILE* ifptr){
	if(ifptr == NULL){
		return 0;
	}
	if(ftell(ifptr) != 0){
		rewind(ifptr);
	}
	int count;
	char c;
	for(count = 0, c = fgetc(ifptr); c != EOF; c = fgetc(ifptr), count++){
	}
	rewind(ifptr);
	return 0;
}

char* deleteBlankLines(FILE* ifptr){
	if(ifptr == NULL){
		return NULL;
	}
	if(ftell(ifptr) != 0){
		rewind(ifptr);
	}
	char* data = malloc(fgetNoOfChars(ifptr) * sizeof(char) + 5);
	int dataPointer = 0;
	char c;
	int count = 0;
	for( c = fgetc(ifptr); c != EOF; c = fgetc(ifptr)){
		if(c != '\n' && c!='\t' && c!=' '){
			count++;
		}
		if(count > 0){
			data[ dataPointer ] = c;
			dataPointer++;
		}
		if(c == '\n'){
			count = 0;
		}
	}
	data[ dataPointer ] = '\0';
	rewind(ifptr);
	return data;

}
