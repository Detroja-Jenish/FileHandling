#include <stdio.h>
#include <stdlib.h>
#include "FileHandling.h"

int main(){
	FILE* ifptr = fopen("input.txt", "r");
	if(ifptr == NULL){
		return 0;
	}
	char* str;
	int count = 1;
	for(str = nextLine(ifptr); str != NULL; str = nextLine(ifptr)){
		printf("%d. %s",count, str);
		count++;
	}
	fclose(ifptr);
	return 0;
}
