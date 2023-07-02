#include <stdio.h>
#include <stdlib.h>
#include "FileHandling.h"

int main(){
	FILE* ifptr = fopen("input.txt","r");
	if(ifptr == NULL){
		printf("%s", "file not opened properly");
		return 0;
	}
	char* data = finsertSpaceInEachLine(ifptr, 2);
	fclose(ifptr);

	//rewrite same file
	if(data != NULL){
		FILE* ofptr = fopen("input.txt", "w");
		fprintf(ofptr, "%s", data);
		fclose(ofptr);
	}
	return 0;
}
