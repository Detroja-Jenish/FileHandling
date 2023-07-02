#include <stdio.h>

int main(){
	FILE* ifptr = fopen("input.txt","r");
	FILE* ofptr = fopen("output.txt", "w");

	char str[40];
	if(ifptr == NULL){
		printf("%s", "null file pointer");
	}
	while(ifptr != NULL && fgets(str, 10, ifptr) != NULL){
		fprintf(ofptr, "%s", str);
		printf("%s", str);
	}
	
	if(ifptr != NULL){
		fclose(ifptr);

	}
	fclose(ofptr);
	return 0;
}
