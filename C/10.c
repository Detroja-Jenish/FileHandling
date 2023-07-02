//to write in binary mode we give "wb" as apram insteadof "W"
//and use fwrite() which takes address of data, size of data, number of data, file pointer

#include <stdio.h>

int main(){
	FILE* ofptr = fopen("output.bin","wb");
	char str[100];
	int i;
	scanf("%s",str);
	for(i=0; i<100 && str[i] != '\0'; i++){
	}
	printf("%d",i);
	fwrite(str, i*sizeof(char), 1, ofptr);
	fclose(ofptr);
	return 0;
}
