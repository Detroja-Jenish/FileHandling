//as we solve problem number 8.
//we know how to append one file to other file
//but here is trick part for append file to itself
//we need to read and store whole file data in variable
//we also dont know how many characters are there
//so we need to first calculate and rewind pointer at beginig and make array of char
//or make pointer of * and give them memory size with malloc funcion.
//then close file
//and reopen file in append mode and write stored data
//so, let's start

#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE* ifptr = fopen("input.txt","r");
	if(ifptr == NULL){
		printf("%s\n","file not opened");
		return 0;
	}
	int count = 0;
	char c ;
	int i;
	for(c = fgetc(ifptr); c != EOF; c = fgetc(ifptr)){
		count++;
	}
	char* data = malloc(count*sizeof(char));
	rewind(ifptr); // for place pointer to begging of file;
	for(i=0, c=fgetc(ifptr); i<count && c!= EOF; i++, c=fgetc(ifptr)){
	   data[i] = c;
	}
	fclose(ifptr);

	//we read the whole data now append in file;
	FILE* ofptr = fopen("input.txt","a");
	if(ofptr == NULL){
		printf("%s\n", "file not opened");
		return 0;
	}
	fprintf(ofptr, "%s", data);
	fclose(ofptr);
	return 0;
}
