#include <stdio.h>

struct Student{
	char name[10];
	int roll;
	int sem;
};

int main(){
	FILE* ofptr = fopen("students.bin", "wb");
	int n;
	printf("Enter number of Students:- ");
	scanf("%d",&n);
	struct Student students[n];
	char name[10];
	int roll, sem;

	for(int i=0; i<n; i++){
		printf("Enter name:- ");
		scanf("%s", students[i].name);
		printf("Enter rollNo:- ");
		scanf("%d", &students[i].roll);
		printf("Enter sem:- ");
		scanf("%d", &students[i].sem);
		//students[i].name = name;
		//students[i].roll = roll;
		//students[i].sem = sem;
	}
	for(int i=0; i<n; i++){
		fwrite(&students[i], sizeof(struct Student), 1, ofptr);
	}
	fclose(ofptr);
	return 0;
}
