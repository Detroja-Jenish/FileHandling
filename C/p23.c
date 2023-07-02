#include <stdio.h>
#include <stdlib.h>
#include "FileHandling.h"

int main(){
	FILE* ifptr = fopen("input.txt","r");
	if(ifptr == NULL){
		printf("%s", "file might not be oprned");
		return 0;
	}
	char* data = fduplicateNthLine(ifptr,4);
	fclose(ifptr);
	
	if(data != NULL){
		FILE* ofptr = fopen("input.txt","w");
		fprintf(ofptr, "%s", data);
		printf("%s\n", data);
		fclose(ofptr);
	}else{
		printf("retrived data is null");
	}
	
	return 0;
}
