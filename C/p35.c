#include <stdio.h>
#include "FileHandling.h"

int main(){
	FILE* ptr1 = fopen("input.txt", "r");
	FILE* ptr2 = fopen("input2.txt", "r");
	if(ptr1 == NULL || ptr2 == NULL){
		return 0;
	}
	FILE* ofptr = fopen("output.txt","w");
	char* data;
	while(!feof(ptr1) && !feof(ptr2)){
		data = nextLine(ptr1);
		if(data != NULL){
			fprintf(ofptr, "%s", data);
		}
		data = nextLine(ptr2);
		if(data != NULL){
			fprintf(ofptr, "%s", data);
		}
	}
	while(!feof(ptr1)){
		data = nextLine(ptr1);
		if(data != NULL){
			fprintf(ofptr, "%s", data);
		}
	}
	while(!feof(ptr2)){
		data = nextLine(ptr2);
		if(data != NULL){
			fprintf(ofptr, "%s", data);
		}
	}

	fclose(ptr1);
	fclose(ptr2);
	fclose(ofptr);
	return 0;
}

