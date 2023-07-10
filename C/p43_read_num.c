#include <stdio.h>
#include <stdlib.h>
#include "FileHandling.h"

struct RealNumber{
	float num;
	struct RealNumber* nextNum;
};

struct RealNumber* readNode(FILE* ifptr);

int main(){
	struct RealNumber* first = NULL;
	struct RealNumber* last = first;
	float num;

	FILE* ifptr = fopen("realNumbers.csv","r");
	last = readNode(ifptr);
	int n = 1;
	while(last != NULL){
		last -> nextNum = readNode(ifptr);
		//printf("%f ", last -> num);
		last = last -> nextNum;
		n++;
	}
	fclose(ifptr);
	
	printf("first node = %f\n\n\n", first -> num);
	struct RealNumber* node = first;
	if(node != NULL){
		printf("%f", node -> num);
		node = node -> nextNum;
	}
	while(node != NULL){
		printf(", %f", node -> num);
		node = node -> nextNum;
	}
	return 0;
}

struct RealNumber* readNode(FILE* ifptr){
	if(ifptr == NULL || feof(ifptr)){
		return NULL;
	}
	//printf("%ld \n\n", ftell(ifptr));
	struct RealNumber* helper = malloc(sizeof(struct RealNumber));
	char* num;
	//fscanf(ifptr, "%f",&num);
	num = nextWordCsv(ifptr);
	helper -> num = atof(num);
	printf("%f ", helper -> num);
	helper -> nextNum = NULL;
	return helper;
}
