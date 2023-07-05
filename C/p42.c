#include <stdio.h>
#include<stdlib.h>
#include "FileHandling.h"
void save(char* fileName, char* data);

int main(int argc, char *argv[])
{
	char srcFile[20];
	char dstFile[20];
	printf("Enter source file name : ");
	scanf("%s", srcFile);
	FILE* ifptr = fopen(srcFile,"r");
	if(ifptr == NULL){
		printf("%s file not found\n", srcFile);
		return 0;
	}
	printf("ENTER\n1 for add your name at first line\n2 for Change the file format to a double space\n3 for delete blank lines\n4 for format lines with max 60 chars\n\n");
	int n;
	char* data;
	scanf("%d", &n);
	if(n==1){
		data = fgetWholeRecords(ifptr);
		printf("%s\n", data);
		fclose(ifptr);
		printf("Enter dst file name :- ");
		scanf("%s",dstFile);
		save(dstFile, data);
	}else if(n==2){
	}else if(n==3){
		data = deleteBlankLines(ifptr);
		fclose(ifptr);
		save(srcFile, data);
	}else if(n==4){
		data = formatLinePerWords(ifptr,60);
		fclose(ifptr);
		save(srcFile, data);
	}
	return 0;
}

void save(char* fileName, char* data){
	if(data == NULL){
		return;
	}
	FILE* ptr = fopen(fileName, "w");
	fprintf(ptr,"%s",data);
	fclose(ptr);
}
