#include <stdio.h>
#include <stdlib.h>
#include "FileHandling.h"

struct RealNumber{
	float num;
	struct RealNumber* nextNum;
};

int main(){
	struct RealNumber* first = NULL;
	struct RealNumber* last;
	int n;
	printf("Enter how many Real numbers you want to store:- ");
	scanf("%d",&n);

	float num;
	for(int i=0; i<n; i++){
		printf("Enter Real Number:- ");
		scanf("%f", &num);
		if(first == NULL){
			first = malloc(sizeof(struct RealNumber));
			first->num = num;
			last = first;
		}else{
			last->nextNum = malloc(sizeof(struct RealNumber));
			last = last->nextNum;
			last->num = num;
		}
	}
	struct RealNumber* node = first;
	FILE* ofptr = fopen("realNumbers.csv","w");
	if(node != NULL){
		fprintf(ofptr,"%f", node->num);
		node = node -> nextNum;
	}
	while(node != NULL){
		fprintf(ofptr,",%f", node->num);
		node = node->nextNum;
	}
	fclose(ofptr);
	return 0;
}
