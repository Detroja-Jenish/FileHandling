#include <stdio.h>
#include "FileHandling.h"

int main(){
	char srcFile[30];
	printf("Enter source File want to encrypt or decrypt :- ");
	scanf("%s", srcFile);

	FILE* ifptr = fopen(srcFile, "r");
	if(ifptr == NULL){
		return 0;
	}

		printf("%d\n", fgetNoOfWords(ifptr));

	int choice;
	int offset;

	printf("if want to encrypt press '1' for decrypt '0' :- ");
	scanf("%d", &choice);
	if(choice == 1){
		printf("Enter offset value to encrypt :- ");
		scanf("%d", &offset);
	}else if(choice == 0){
		printf("Enter encrypt key :- ");
		scanf("%d", &offset);
		offset = -1*offset;

	}else{
		fclose(ifptr);
		return 0;
	}
	int n = fgetNoOfChars(ifptr);
	char data[n+1];
	int i = 0;
	char encryptedChar ;
	for(char c = fgetc(ifptr); c!=EOF; c = fgetc(ifptr)){
		encryptedChar = (char) ((int) c + offset);
		data[i] = encryptedChar;
		i++;
	}
	data[i] = '\0';
	fclose(ifptr);

	char dstFile[30];
	printf("Enter destination File want to store encryptrd or decrypted msg. :- ");
	scanf("%s", dstFile);

	FILE* ofptr = fopen(dstFile,"w");
	fprintf(ofptr, "%s", data);
	fclose(ofptr);

	return 0;
}
