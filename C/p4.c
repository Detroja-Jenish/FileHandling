//In C while run your programme each time by defualt you pass two paras
//1. argc = 1
//2. char* argv = your .out file name
//where argc is count of your commandline arguments
//you also can give extra arguments from commandline as ./a.out arg1 arg2 ...
//if you want your extra arguments then you just need to triverse array from 1 to argc
#include <stdio.h>

int main(int argc, char* argv[]){
	//check for that user gave source and destination file name or not
	if(argc <= 2){
		printf("%s","please give all arguments as ./a.out sourceFile destinationFile");
		return 0;
	}
	//we take our source file as first argument (at index = 1)
	FILE* ifptr = fopen(argv[1], "r");
	//we take our destination file as second argument (at index = 1)
	FILE* ofptr = fopen(argv[2], "w");

	if(ifptr == NULL){
		printf("%s%s", argv[1], " file's pointer is null");
		return 0;
	}
	char str[40];
	while(fgets(str, 40, ifptr) != NULL){
		fprintf(ofptr, "%s", str);
		printf("%s", str);
	}
	fclose(ifptr);
	fclose(ofptr);

	return 0;
}
