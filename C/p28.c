
#include <stdio.h>
#include <stdlib.h>
#include "FileHandling.h"

int main(){
	FILE* ifptr = fopen("input.txt", "r");
	if(ifptr == NULL){
		return 0;
	}
	char* data = changeCase(ifptr);
	fclose(ifptr);

	if(data != NULL){
		FILE* ofptr = fopen("input.txt","w");
		fprintf(ofptr, "%s", data);
		printf("%s", data);
		fclose(ofptr);
	}
	return 0;
}
