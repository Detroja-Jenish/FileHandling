//in this problem we have to count words which are serated by whitespace.
//so we need just to count spaces which we can count by checking each char.
//our answer will be no of space + 1;.
#include <stdio.h>

int main(){
	FILE* ifptr = fopen("input.txt","r");
	if(ifptr == NULL){
		printf("%s", "file pointer is null, maybe file not found at given loaction");
		return 0;
	}
	char c;
	int count = 1;
	do{
		c = fgetc( ifptr );
		if(c == ' '){
			count++;
		}

		if(feof(ifptr)){
			break;
		}
	}while(1);
	if(ifptr == NULL){
		printf("file can not be opened");
	}else{
		printf("total words are %d.\n",count);
		fclose(ifptr);
	}
	return 0;
}
