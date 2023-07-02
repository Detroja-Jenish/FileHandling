//in fopen function we know r as param for read mode and w as param for write mode
//there are also different modes available one of these is "a" for append which is
//used to write in file at end of file;
#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE* ifptr = fopen("input.txt","r");
	FILE* ofptr = fopen("output.txt","a");
	if(ifptr == NULL || ofptr == NULL){
		printf("%s\n", "file not opened properly");
		return 0;
	}
	char* str = malloc(128*sizeof(char));
	while(fgets(str, 128, ifptr)!=NULL){
		fprintf(ofptr,"%s", str);
	}
	fclose(ifptr);
	fclose(ofptr);

	return 0;
}
