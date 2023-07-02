#include <stdio.h>
#include <string.h>

int main(){
	FILE* fptr = fopen("output.txt", "w");
	char str[40];
	scanf("%s", str);
	printf("%d", strcmp(str, "exit"));
	while(strcmp(str, "exit") != 0){
		fprintf(fptr, "%s", str);
		scanf("%s", str);
		printf("%d", strcmp(str, "exit"));
	}
	fclose(fptr);
	return 0;
}
