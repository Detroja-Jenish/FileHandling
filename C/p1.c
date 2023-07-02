#include <stdio.h>

int main(){
	FILE* ptr = fopen("input.txt","r");
	char str[10];
	while(fgets(str, 10, ptr) != NULL){
		printf("%s",str);
	}	
	fclose(ptr);
	return 0;
}
