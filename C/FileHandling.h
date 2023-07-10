#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int fgetNoOfChars(FILE* ifptr);
char* insertNewLineAfterNoOfLine(FILE* ifptr, int n);
char* fgetWholeRecords(FILE* ifptr);
char* deleteBlankLines(FILE* ifptr);
char* fdeleteNthLine(FILE* ifptr, int n);
int   fget_no_of_all_chars_excluding_tabs_newLine(FILE* ifptr);
int   fget_no_of_char(FILE* ifptr, char c);
char* fcopyLineWithChar(FILE* ifptr, char c);
char* finsertSpaceInEachLine(FILE* ifptr, int n);
char* fduplicateNthLine(FILE* ifptr, int n);
char* fduplicateFirstWordAtEOL(FILE* ifptr);
char* nextLine(FILE* ifptr);
char* changeCase(FILE* ifptr);
char* nextWordCsv(FILE* ifptr);
char* nextWord(FILE* ifptr);
int fgetNoOfLines(FILE* ifptr);
int fgetNoOfWords(FILE* ifptr);
char fgetPreviousChar(FILE* ifptr);
char* formatLinePerWords(FILE* ifptr,int n);

int fgetNoOfChars(FILE* ifptr){
	if(ifptr == NULL){
		return 0;
	}
	if(ftell(ifptr) != 0){
		rewind(ifptr);
	}
	//int count;
	//char c;
	//for(count = 0, c = fgetc(ifptr); c != EOF; c = fgetc(ifptr), count++){
	//}
	//rewind(ifptr);
	//return count;
	fseek(ifptr, 0, SEEK_END);
	int n = ftell(ifptr) - 1;
	rewind(ifptr);
	return n;
}

char* insertNewLineAfterNoOfLine(FILE* ifptr, int n){
	if(ifptr == NULL){
		return NULL;
	}
	int noOfChars =  fgetNoOfChars(ifptr);
	char* data = malloc((noOfChars+5)*sizeof(char));
	int dataPointer = 0;
	char c;
	int count = 0;
	if(ftell(ifptr) != 0){
		rewind(ifptr);
	}
	for(c = fgetc(ifptr); c != EOF; c = fgetc(ifptr)){
		if(dataPointer >= noOfChars - 5){
			data = realloc(data, (noOfChars + 30)*sizeof(char));
			noOfChars += 30;
		}
		data[dataPointer] = c;
		dataPointer++;
		if(c == '\n'){
			count++;
		}
		if(count == n){
			count = 0;
			data[dataPointer] = '\n';
			dataPointer++;
		}
	}
	data[ dataPointer ] = '\0';
	rewind( ifptr );
	return data;
}

char* fgetWholeRecords(FILE* ifptr){
	if(ifptr == NULL){
		return NULL;
	}
	int noOfChars = fgetNoOfChars(ifptr);
	char* data = malloc((noOfChars+3)*sizeof(char));
	int dataPointer = 0;
	char c;
	if(ftell(ifptr) != 0){
		rewind(ifptr);
	}
	for(c = fgetc(ifptr); c != EOF; c = fgetc(ifptr)){
		data[ dataPointer ] = c;
		dataPointer++;
	}
	data[ dataPointer ] = '\0';
	rewind(ifptr);
	return data;
}

char* deleteBlankLines(FILE* ifptr){
	if(ifptr == NULL){
		return NULL;
	}
	char* data = malloc(fgetNoOfChars(ifptr) * sizeof(char) + 5);
	int dataPointer = 0;
	char c;
	int count = 0;
	if(ftell(ifptr) != 0){
		rewind(ifptr);
	}
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

char* fdeleteNthLine(FILE* ifptr, int n){
	if(ifptr == NULL){
		return NULL;
	}
	int noOfLines = fget_no_of_char(ifptr, '\n');
	int noOfChars = fgetNoOfChars(ifptr);
	char* data = malloc((noOfChars+1)*sizeof(char));
	char c;
	int dataPointer = 0;
	int countLine = 1;
	if(ftell(ifptr) != 0){
		rewind(ifptr);
	}
	for(c = fgetc(ifptr); c != EOF; c = fgetc(ifptr)){
		if(c == '\n'){
			countLine++;
		}
		if(countLine == n){
			continue;
		}
		data[dataPointer] = c;
		dataPointer++;
	}
	data[ dataPointer ] = '\0';
	rewind(ifptr);
	return data;
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

char* fcopyLineWithChar(FILE* ifptr, char i){
	if(ifptr == NULL){
		return NULL;
	}
	int noOfChars =  fgetNoOfChars(ifptr);
	char* data = malloc((noOfChars+1)*sizeof(char));
	int dataPointer = 0;
	char c;
	bool canCopy = false;
	bool isFirstChar = true;
	if(ftell(ifptr) != 0){
		rewind(ifptr);
	}
	for(c = fgetc(ifptr); c != EOF; c = fgetc(ifptr)){
		if(!canCopy && c == i && isFirstChar){
			canCopy = true;
		}
		if(isFirstChar){
			isFirstChar = false;
		}
		if(canCopy){
			data[dataPointer] = c;
			dataPointer++;
		}
		if(c == '\n'){
			canCopy = false;
			isFirstChar = true;
		}

	}

	data[dataPointer] = '\0';
	rewind(ifptr);
	return data;
}

char* finsertSpaceInEachLine(FILE* ifptr, int n){
	if(ifptr == NULL){
		return NULL;
	}
	int noOfChars =  fgetNoOfChars(ifptr);
	char* data = malloc((noOfChars+5)*sizeof(char));
	int dataPointer = 0;
	char c;
	int count = 0;
	bool isFirstChar = true;
	if(ftell(ifptr) != 0){
		rewind(ifptr);
	}
	for(c = fgetc(ifptr); c != EOF; c = fgetc(ifptr)){
		if(dataPointer >= noOfChars - 5){
			data = realloc(data, (noOfChars + 30)*sizeof(char));
			noOfChars += 30;
		}
		if(isFirstChar){
			for(int i=0; i<n; i++){
				data[ dataPointer ] = ' ';
				dataPointer++;
			}
			isFirstChar = false;
		}
		data[dataPointer] = c;
		dataPointer++;
		if(c == '\n'){
			isFirstChar = true;
		}
	}
	data[dataPointer] = '\0';
	rewind(ifptr);
	return data;

}

char* fduplicateNthLine(FILE* ifptr, int n){
	if(ifptr == NULL){
		return NULL;
	}
	int noOfChars =  fgetNoOfChars(ifptr) + 60;
	char* data = malloc((noOfChars)*sizeof(char));
	int dataPointer = 0;
	char c;
	int count = 1;//first line;
	int nthLinePosition;
	bool isNthLine = false;
	bool isRewind = false;
	if(ftell(ifptr) != 0){
		rewind(ifptr);
	}
	for(c = fgetc(ifptr); c != EOF; c = fgetc(ifptr)){
		if(dataPointer >= noOfChars - 10){
			data = realloc(data, (noOfChars + 30)*sizeof(char));
			noOfChars += 30;
		}
		if(count == n+1 && !isRewind){
			isRewind = true;
			fseek(ifptr, nthLinePosition,0);
			continue;
		}
		if(c == '\n'){
			count++;
			if(count == n){
				nthLinePosition = ftell(ifptr);
				isNthLine = true;
			}
		}
		data[ dataPointer ] = c;
		dataPointer++;
	}
	data[ dataPointer ] = '\0';
	rewind(ifptr);
	return data;

}

char* fduplicateFirstWordAtEOL(FILE* ifptr){
	if(ifptr == NULL){
		return NULL;
	}
	int noOfChars = fgetNoOfChars(ifptr) + 60;
	char* data = malloc(noOfChars*sizeof(char));
	int count = 0; //for first word;
	int resetLine = 0;
	int dataPointer = 0;
	int thisLine = 0;
	for(char c = fgetc(ifptr); c!=EOF; c = fgetc(ifptr)){
		if(dataPointer >= noOfChars - 10){
			noOfChars += 30;
			data = realloc(data, noOfChars*sizeof(char));
		}
		if(c == '\n'){
			thisLine = ftell(ifptr);
			data[dataPointer] = ' ';
			dataPointer++;
			fseek(ifptr, resetLine, 0);
			for(char i = fgetc(ifptr); i != ' ' && i!='\t' && i!='\n'; i = fgetc(ifptr)){
				if(dataPointer >= noOfChars - 10){
					noOfChars += 30;
					data = realloc(data, noOfChars*sizeof(char));
				}
				data[dataPointer] = i;
				dataPointer++;
			}
			resetLine = thisLine;
			fseek(ifptr, thisLine,0);
		}
		data[dataPointer] = c;
		dataPointer++;

	}
	data[dataPointer] = '\0';
	rewind(ifptr);
	return data;

}

char* nextLine(FILE* ifptr){
	if(ifptr == NULL){
		return NULL;
	}
	int noOfChars = 60;
	char* data = malloc(noOfChars*sizeof(char));
	char c;
	int dataPointer = 0;
	for(c = fgetc(ifptr); c != EOF ;c = fgetc(ifptr)){
		if(dataPointer >= noOfChars - 5){
			noOfChars += 30;
			data = realloc(data, noOfChars*sizeof(char));
		}
		data[dataPointer] = c;
		dataPointer++;
		if(c == '\n'){
			break;
		}
	}
	if( c == EOF){
		return NULL;
	}
	data[dataPointer] = '\0';
	return data;
	
}

char* changeCase(FILE* ifptr){
	if(ifptr == NULL){
		return NULL;
	}
	int noOfChars = fgetNoOfChars(ifptr)+5;
	char* data = malloc(noOfChars*sizeof(char));
	int dataPointer = 0;
	char c;
	int ascii;
	if(ftell(ifptr) != 0){
		rewind(ifptr);
	}
	for(c = fgetc(ifptr); c != EOF ;c = fgetc(ifptr)){
		ascii = (int) c;
		if(ascii >=65 && ascii <= 90){
			ascii += 32;
			c = (char) ascii;
		}else if(ascii >= 97 && ascii <= 122){
			ascii -= 32;
			c = (char) ascii;
		}
		data[ dataPointer ] = c;
		dataPointer++;
	}
	data[ dataPointer ] = '\0';
	rewind(ifptr);
	return data;
}

char* nextWordCsv(FILE* ifptr){
	if(feof(ifptr)){
		return NULL;
	}
	int noOfChars = 20;
	char* word = malloc(noOfChars*sizeof(char));
	int dataPointer = 0;
	for(char c = fgetc(ifptr); c !=EOF && ((c != ',' && c!='\n') || dataPointer == 0); c = fgetc(ifptr)){
		if(dataPointer >= noOfChars - 5){
			noOfChars += 20;
			word = realloc(word, noOfChars*sizeof(char));
		}
		if(c=='\n'){
			continue;
		}
		word[dataPointer++] = c;
	}
	word[dataPointer] = '\0';
	return word;
}

int fgetNoOfLines(FILE* ifptr){
	return fget_no_of_char(ifptr, '\n') + 1;
}

char* nextWord(FILE* ifptr){
	if(feof(ifptr)){
		return NULL;
	}
	int noOfChars = 20;
	char* word = malloc(noOfChars*sizeof(char));
	int dataPointer = 0;
	for(char c = fgetc(ifptr); c !=EOF && ((c!='\n' && c!= ' ' && c!='\t') || dataPointer == 0); c = fgetc(ifptr)){
		if(dataPointer >= noOfChars - 5){
			noOfChars += 20;
			word = realloc(word, noOfChars*sizeof(char));
		}
		if(c=='\n' || c == ' '){
			continue;
		}
		word[dataPointer++] = c;
	}
	if(dataPointer == 0){
		return NULL;
	}
	word[dataPointer] = '\0';
	return word;
}

int fgetNoOfWords(FILE* ifptr){
	if(ifptr == NULL){
		return 0;
	}
	if(ftell(ifptr) != 0){
		rewind(ifptr);
	}
	//	int count = 0;
	//	char c;
	//	char lastchar = ' ';
	//	for(c = fgetc(ifptr); c!=EOF; c = fgetc(ifptr)){
	//		if((c == ' ' || c == '\t' || c == '\n') && (lastchar != ' ' && lastchar != '\t' && lastchar != '\n')){
	//			count++;
	//		}
	//		lastchar = c;
	//	}
	//	if(c != '\n'){
	//		count++;
	//	}
	int count = 0;
	char* word;
	for(word = nextWord(ifptr); word != NULL; word = nextWord(ifptr)){
	   count++;
	}	   
	rewind(ifptr);
	return count;
}

char fgetPreviousChar(FILE* ifptr){
	if(ftell(ifptr) == 0){
		return ' ';
	}
	fseek(ifptr , -1, SEEK_CUR);
	return fgetc(ifptr);
}

char* formatLinePerWords(FILE* ifptr,int n){
	if(ifptr == NULL){
		return NULL;
	}
	int count = 0;
	char c;
	char* data = malloc(61*sizeof(char));
	int dataPointer = 0;
	if(ftell(ifptr) != 0 ){
		rewind(ifptr);
	}
	for(c = fgetc(ifptr), dataPointer = 0; c!=EOF; c = fgetc(ifptr) , dataPointer++){
		if(dataPointer == ((sizeof(*data)/sizeof(char)) - 3)){
			data = realloc(data, sizeof(*data) + (60*sizeof(char)));
		}
		count++;
		data[dataPointer] = c;
		if(count == n && c != '\n'){
			data[dataPointer + 1] = '\n';
			dataPointer++;
			count = 0;
		}else if(c == '\n'){
			count = 0;
		}
	}
	data[dataPointer] = '\0';
	rewind(ifptr);
	return data;
 }
