//in this problem we read file character by charater
//and compare them with " ", "\n", "\t"
// we use fgetc( FILE pointer )
// for checking end of file we use feof( FILE pointer ) which returns 1 if pointer reaches at end else 0
#include <stdio.h>

int main(){
	FILE* ifptr = fopen("input.txt","r");
	if(ifptr == NULL){
		printf("%s", "file pointer is null, maybe file not found at given loaction");
		return 0;
	}
	char c;
	int totalChars = 0;
	int totalSpace = 0;
	int totalLine = 0;
	int totalTabs = 0;
	do{
		c = fgetc( ifptr );
		if(c == ' '){
			totalSpace++;
		}else if(c == '\n'){
			totalLine++;
			continue;
		}else if(c == '\t'){
			totalTabs++;
		}
		totalChars++;

		if(feof(ifptr)){
			break;
		}
	}while(1);
	printf("%s%d%s%d%s%d%s%d%s","in this file there are total ",totalChars," and among them ",totalSpace," are spaces, ", totalLine, " are  no. of Lines, and ", totalTabs , " are total tabs");
	//printf("%d%d%d%d",totalChars,totalSpace,totalLine,totalTabs);
	fclose(ifptr);
	return 0;
}
