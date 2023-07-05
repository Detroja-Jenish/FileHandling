#include <stdio.h>

int main(){
	FILE* ifptr = fopen("output.txt", "w");
	int n, ll, hl;
	printf("Enter a number:- ");
	scanf("%d", &n);
	printf("Enter a low limit:- ");
	scanf("%d", &ll);
	printf("Enter a high limit:- ");
	scanf("%d", &hl);

	for(int i=ll; i<=hl; i++){
		fprintf(ifptr, "%d\n", (n*i));
	}
	fclose(ifptr);
	return 0;
}
