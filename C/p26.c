#include <stdio.h>
#include <stdlib.h>
#include "FileHandling.h"

int main(){
	FILE* ifptr = fopen("input.txt", "r");
	if(ifptr == NULL){
		return 0;
	}
	char* data = fduplicateFirstWordAtEOL(ifptr);
	fclose(ifptr);

	if(data != NULL){
		FILE* ofptr = fopen("output.txt","w");
		printf("%s", data);
		fprintf(ofptr, "%s", data);
		fclose(ofptr);
	}
	return 0;
}
