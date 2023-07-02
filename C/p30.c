#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE* ifptr = fopen("Integer.txt", "w");
	int i;
	for(int j=0; j<10; j++){
		printf("Enter number:- ");
		scanf("%d",&i);
		fprintf(ifptr, "%d\n", i);
	}
	fclose(ifptr);
	ifptr = fopen("Integer.txt", "r");
	if(ifptr == NULL){
		return 0;
	}
	FILE* posptr = fopen("positivenums.txt","w");
	FILE* negptr = fopen("negativenums.txt", "w");
	for(fscanf(ifptr, "%d", &i); !feof(ifptr); fscanf(ifptr, "%d", &i)){
		if(i<0){
			fprintf(negptr,"%d ",i);
		}else{
			fprintf(posptr,"%d ",i);
		}
			
	}
	fclose(ifptr);
	fclose(posptr);
	fclose(negptr);
	return 0;
}
