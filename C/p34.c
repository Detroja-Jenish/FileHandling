#include <stdio.h>

int main(){
	FILE* ifptr = fopen("input.txt","r");
	if(ifptr == NULL){
		return 0;
	}
	printf("%ld\n", ftell(ifptr));
	fseek(ifptr, 0, SEEK_END);
	int noOfChars = ftell(ifptr) - 1;
	printf("%d\n", noOfChars);
	fclose(ifptr);
	return 0;
}
