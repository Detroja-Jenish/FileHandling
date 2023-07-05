#include <stdio.h>

int main(){
	FILE* ifptr = fopen("input.txt","r");
	if(ifptr == NULL){
		return 0;
	}
	FILE* ofptr = fopen("ASC_SET","w");
	for(char c = fgetc(ifptr); c!=EOF; c = fgetc(ifptr)){
		fprintf(ofptr, "%d ", (int) c);
	}
	fclose(ifptr);
	fclose(ofptr);
	//reread file number by nuber and convert back to char
	ofptr = fopen("ASC_SET","r");
	if(ofptr == NULL){
		return 0;
	}
	int ascii;
	while(!feof(ifptr) && fscanf(ofptr, "%d", &ascii)){
		if((ascii>=48 && ascii<=57) || (ascii>=64 && ascii<=90)){
			printf("%c\n", (char) ascii);
		}
	}
	fclose(ofptr);
	return 0;
}
