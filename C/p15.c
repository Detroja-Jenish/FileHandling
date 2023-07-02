//for getting average number of char per line we need total chars excluding tabs and \n and no of line

#include <stdio.h>
int fget_no_of_char(FILE* ifptr, char c);
int fget_no_of_all_chars_excluding_tabs_newLine(FILE* ifptr);
int main(){
	
	FILE* ifptr = fopen("input.txt","r");
	if(ifptr == NULL){
		printf("%s", "file might not be opened properly.");
		return 0;
	}
	int totalChars = fget_no_of_all_chars_excluding_tabs_newLine(ifptr);
	int noOfLines = fget_no_of_char(ifptr, '\n');
	int avgChars = totalChars/noOfLines;
	printf("average character per line in this file are %d.\n", avgChars);
	return 0;
}

int fget_no_of_all_chars_excluding_tabs_newLine(FILE* ifptr){
	if(ifptr == NULL){
		return 0;
	}
	int count = 0;
	if(ftell(ifptr) != 0){
		rewind(ifptr);
	}
	for(char c = fgetc(ifptr); c != EOF; c = fgetc(ifptr)){
		if(c != '\n' || c!='\t'){
			count++;
		}
	}
	rewind(ifptr);
	return count;
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
