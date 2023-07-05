#include <stdio.h>
#include <stdlib.h>

char* nextWord(FILE* ifptr);
int main(){
	FILE* ifptr = fopen("input.txt","r");
	if(ifptr == NULL){
		return 0;
	}
	char* word;
	int wordCount = 0;
	int fourLetterWordCount = 0;

	word = nextWord(ifptr);
	while(word != NULL){

		wordCount++;
		if(word[4] == '\0' && word[3] != '\0'){
			fourLetterWordCount++;

		}
		word = nextWord(ifptr);

	}
	printf("no of words = %d\nfour letter words = %d\n", wordCount, fourLetterWordCount);
	fclose(ifptr);
}
char* nextWord(FILE* ifptr){
	int noOfChars = 50;
	char* data = malloc(noOfChars * sizeof(char));
	int dataPointer = 0;
	for(char c = fgetc(ifptr); c != EOF; c = fgetc(ifptr)){
		if(dataPointer >= noOfChars - 5){
			noOfChars += 20;
			data = realloc(data, noOfChars * sizeof(char));
		}
		if(dataPointer != 0 && (c == ' ' || c == ',' || c == '.' || c == '\n')){
			break;
		}else if(c != ' ' && c!=',' && c!='.' && c!='\n'){
			data[dataPointer] = c;
			dataPointer++;
		}
	}
	if(dataPointer == 0){
		return NULL;
	}
	data[dataPointer] = '\0';
	return data;
}
