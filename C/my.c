#include <stdio.h>

int main(){
	FILE* ifptr = fopen("input.txt","r+");
	printf("%ld",ftell(ifptr));
	fseek(ifptr, 12, 0);
	fprintf(ifptr, "%s", "dave\nRakshit\n");
	fclose(ifptr);
	return 0;
}
