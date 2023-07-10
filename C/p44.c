#include <stdio.h>
#include <stdlib.h>

struct Student{
	char name[10];
	int roll;
	int sem;
};

int main(){
	FILE* ifptr = fopen("students.bin", "rb");
	if(ifptr == NULL){
		return 0;
	}
	int noOfStudents = 5;
	struct Student* students = malloc(noOfStudents*sizeof(struct Student));

	for(int i=0; !feof(ifptr); i++){
		if(i == noOfStudents){
			noOfStudents++;
			students = realloc(students, noOfStudents*sizeof(struct Student));
		}

		fread(&students[i], sizeof(struct Student), 1, ifptr);
	}
	for(int i=0; i<noOfStudents; i++){
		printf("%s %d %d\n", students[i].name, students[i].roll, students[i].sem);
	}
	fclose(ifptr);
	return 0;
}
