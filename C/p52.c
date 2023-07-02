#include<stdio.h>
#include <stdlib.h>
#include "FileHandling.h"

struct Employee{
	int empNo;
	int dpt;
	float payRate;
	char Exempt;
	int hourWorked;
	float basePay;
	float totalPay;
};
void readData(FILE* ptr, struct Employee* emps);
void saveRegister(struct Employee* emps,int n, char* str);
void clacSalary(struct Employee* emp);
int main(){
	FILE* empFile = fopen("employeeData.csv","r");
	if(empFile == NULL){
		return 0; 
	}
	int n=fget_no_of_char(empFile, '\n');
	struct Employee* emps = malloc(n*sizeof(struct Employee));
	for(int i = 0; i<n && !feof(empFile); i++){
		readData(empFile, emps);
		emps++;
	}
	emps = emps - n;
	for(int i = 0; i<n; i++){
		clacSalary(emps);
		emps++;
	}
	emps = emps - n;
	saveRegister(emps,n , "payrollRegister.csv");
	return 0;
}

void readData(FILE* ptr, struct Employee* emps){
	fscanf(ptr,"%d %d %f %c %d", &(emps->empNo), &(emps->dpt), &(emps->payRate), &(emps->Exempt), &(emps->hourWorked));
}

void clacSalary(struct Employee* emp){
	if(emp->Exempt == 'N' || emp->hourWorked <= 40){
		emp->basePay = emp->hourWorked*emp->payRate;
		emp->totalPay = emp->basePay;
		return;
	}
	emp->basePay = 40 * emp->payRate;
	emp->totalPay = emp->basePay + ((emp->hourWorked - 40)/2)*emp->payRate;

}

void saveRegister(struct Employee* emps,int n, char* str){
	FILE* ptr = fopen(str, "w");
	fprintf(ptr, "empNo, department, pay rate, exempt, hour worked, base pay, total pay\n");
	for(int i=0; i<n ; i++){
		fprintf(ptr, "%d, %d, %f, %c, %d, %f, %f\n", emps->empNo, emps->dpt, emps->payRate, emps->Exempt, emps->hourWorked, emps->basePay, emps->totalPay);
		emps++;
	}
	fclose(ptr);
}
