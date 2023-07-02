#include <stdio.h>
#include <stdlib.h>
#include "FileHandling.h"

int main(){
	FILE* ifptr = fopen("input.txt", "r");
	if(ifptr == NULL){
		printf("%s", "file not opened properly");
		return 0;
	}
	char* data = fcopyLineWithChar(ifptr, 'b');
	fclose(ifptr);
	if(data != NULL){
		FILE* ofptr = fopen("output.txt","w");
		fprintf(ofptr, "%s", data);
		fclose(ofptr);
	}
	return 0;
}
