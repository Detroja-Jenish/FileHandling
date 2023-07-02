#include <stdio.h>
int main(){
	FILE* ifptr = fopen("output.bin", "rb");
	char str[100];
	fread(str, sizeof(str), 1, ifptr);
	printf("%s", str);
}
