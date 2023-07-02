//in this problem we first write students data in output.txt file.
//I prefer csv format for this problem so we go with that
//for read data in csv file we first read data line by line and additionally we use
//new function strtok()
//by this we can get tokens which are ended by either ','(we can spacify deferent strings also) or '\n';
//it only gives first token
//for getting next token we should use loop while token is not Null
#include <stdio.h>
#include <string.h>

int main(){
	FILE *ofptr = fopen("output.csv","w");
	char name[20];
	int rollno, age;
	fprintf(ofptr,"%s", "name, rollNo, age\n");
	for(int i=0; i<2; i++){
		printf("%s","Enter name:- ");
		scanf("%s", name);
		printf("%s","Enter rollno:- ");
		scanf("%d", &rollno);
		printf("%s","Enter age:- ");
		scanf("%d", &age);

		fprintf(ofptr, "%s,%d,%d\n", name, rollno, age);
	}	
	fclose(ofptr);

	FILE *ifptr = fopen("output.txt", "r");
	if(ifptr == NULL){
		printf("%s","file not opened properly in read mode.");
		return 0;
	}
	char line[100];
	char *token;
	fgets(line, 100, ifptr);
	printf("%s\n", line);
	while(fgets(line, 100, ifptr) != NULL){
		token = strtok(line,",");
		if(token != NULL){
			printf("name = %s\n", token);
		}
		if(token != NULL){
			token = strtok(NULL, ",");
			printf("rollNo = %s\n", token);
		}
		if(token != NULL){
			token = strtok(NULL, ",");
			printf("age = %s\n\n", token);
		}
	}	
	fclose(ifptr);
	return 0;
}

