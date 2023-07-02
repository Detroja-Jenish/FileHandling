//in this problem first we need to know no of line and store data excluding last line.
//now we know how we gwt no of lines and store the data.
#include <stdio.h>
#include <stdlib.h>

int fget_no_of_char(FILE* ifptr, char c);
char* freadNLines(FILE* ifptr,int n);

int main(){

	FILE* ifptr = fopen("input.txt", "r");
	if(ifptr == NULL){
		printf("%s", "FIle might not be opened.\n");
		return 0;
	}
	int n = fget_no_of_char(ifptr, '\n');
	char* data = freadNLines(ifptr, n-1);
	fclose(ifptr);

	FILE* ofptr = fopen("input.txt", "w");
	if(data != NULL){
		fprintf(ofptr, "%s", data);
	}
	fclose(ofptr);

	return 0;
}

int fget_no_of_char(FILE* ifptr, char c){
	if(ifptr == NULL){
		return 0;
	}
	int count = 0;
	if(ftell(ifptr) != 0){
		rewind(ifptr);
	}
	for(char i = fgetc(ifptr); i != EOF; i = fgetc(ifptr)){
		if(i == c){
			count++;
		}
	}
	rewind(ifptr);
	return count;
}

char* freadNLines(FILE* ifptr, int n){
	if(ifptr == NULL && n > -1){
		return NULL;
	}
	if(ftell(ifptr)!=0){
		rewind(ifptr);
	}
	char* data = malloc(50*sizeof(char));
	int i, dataPointer;
	char c;
	for(i=0,dataPointer = 0, c = fgetc(ifptr); i<n && c!=EOF; dataPointer++, c = fgetc(ifptr)){
		if(dataPointer == (sizeof(*data)/sizeof(char))-3){
			data = realloc(data, (sizeof(*data)/sizeof(char)) + 30*sizeof(char));
		}
		data[ dataPointer ] = c;
		if(c == '\n'){
			i++;
		}
	}
	data[ dataPointer ] = '\0';
	rewind(ifptr);
	return data;
}
