//we need to first read the data format under our codition (each line only contains 60 chars)
//then overwrite the file.
#include <stdio.h>
#include <stdlib.h>
int main(){
	FILE *ifptr = fopen("input.txt","r");
	if(ifptr == NULL){
		printf("%s", "file can not be opened");
		return 0;
	}
	int count = 0;
	char c;
	char* data = malloc(61*sizeof(char));
	int dataPointer = 0;
	for(c = fgetc(ifptr), dataPointer = 0; c!=EOF; c = fgetc(ifptr) , dataPointer++){
		if(dataPointer == ((sizeof(*data)/sizeof(char)) - 3)){
			data = realloc(data, sizeof(*data) + (60*sizeof(char)));
		}
		count++;
		data[dataPointer] = c;
		if(count == 60 && c != '\n'){
			data[dataPointer + 1] = '\n';
			dataPointer++;
			count = 0;
		}else if(c == '\n'){
			count = 0;
		}
	}
	fclose(ifptr);

	FILE* ofptr = fopen("input.txt","w");
	fprintf(ofptr,"%s",data);
	fclose(ofptr);
}
