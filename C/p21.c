#include <stdio.h>
#include <stdlib.h>
#include "FileHandling.h"

int main(){
	FILE* ifptr = fopen("input.txt","r");
	if(ifptr == NULL){
		printf("%s", "file not opened properly");
		return 0;
	}
	char* data = fdeleteNthLine(ifptr, 6);
	fclose(ifptr);

	//rewrite same file
	FILE* ofptr = fopen("input.txt", "w");
	if(data != NULL){
		fprintf(ofptr, "%s", data);
	}
	fclose(ofptr);
	return 0;
}
