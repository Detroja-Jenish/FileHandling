#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <stdbool.h>
#include "FileHandling.h"

struct Inventory{
    char* name;
    char* date;
    char* supplier;
	int mrp;
	int stock;
};
void readData(FILE* ifptr, struct Inventory* manager);
int main(){
	FILE* stockFile = fopen("inventory.csv","r");
	if(stockFile == NULL){
		return 0; 
	}
    int noOfItem=fgetNoOfLines(stockFile) - 1;// first line header so drop it; 
    printf("%d\n\n\n", noOfItem);

    if(noOfItem == 0 || noOfItem == 1){
		printf("new shop just opened\n");
	}

	struct Inventory* manager = malloc((noOfItem)*sizeof(struct Inventory));

    if(noOfItem > 1){
	    for(int i = 0; i<noOfItem && !feof(stockFile); i++){
	    	readData(stockFile, (manager + i));
            printf("%s %s %s %d %d\n\n", (manager + i)->name, (manager + i)->date, (manager + i)->supplier, (manager + i)->mrp, (manager + i)->stock);
	    }
    }

    for(int i = 0; i<noOfItem; i++){
            printf("%d:-) %s %s %s %d %d\n", i , (manager + i)->name, (manager + i)->date, (manager + i)->supplier, (manager + i)->mrp, (manager + i)->stock);
	}
    fclose(stockFile);

    bool isShopOpen = false;
    char choice[20];
    char item[20];
    char supplierName[30];
    int mrp;
    int quntatity;
    char date[12];
    printf("\ndo you want to open shop..?(Y or N) :- ");
    scanf("%s", choice);
    if(strcmp(choice, "Y") == 0){
        isShopOpen = true;
    }
    while(isShopOpen){
        printf("\nare you customer or supplier...?  :- ");
        scanf("%s", choice);
        if(strcmp(choice, "customer") == 0){
            printf("\nwhat do you want? ");
            scanf("%s" , item);
            int id=0;
            while(id<noOfItem && strcmp((manager + id)->name ,item) !=0){
                id++;
            }
            if(id < noOfItem && strcmp((manager + id)->name ,item) == 0){
                printf(" %s %s %s %d %d\n" , manager->name, manager->date, manager->supplier, manager->mrp, manager->stock);
                if((manager + id)->stock > 0){
                    printf("\nthere is %d %s availabel how much you want :- ",(manager + id)->stock, item );
                    scanf("%d", &quntatity);
                    while(quntatity > (manager + id)->stock){
                        printf("\nsorry, but cureently there is not enough stock reneter quatatity :- ");
                        scanf("%d", &quntatity);
                    }
                    printf("\nyour bill is %d\n", ((manager + id)->mrp*quntatity));
                    printf("\nhere is your %s's please collect it \nthank you for visiting us\n\n", item);
                    (manager + id)->stock -= quntatity;
                }else{
                    printf("\nsorry, currently this item out of stock.\n");
                }
            }
            
        }else if(strcmp(choice, "supplier") == 0){
            printf("\nenter your comapny's name :- ");
            scanf("%s",supplierName);
            printf("\nhey! boss this is salesman from %s comapny. do we need anything to order('Y' or 'N') :-", supplierName);
            scanf("%s", choice);
            if(strcmp(choice,"Y")==0){
                printf("\nenter item name:- ");
                scanf("%s", item);
                int id=0;
                while(id<noOfItem && (strcmp((manager+id)->supplier, supplierName)!=0 && strcmp((manager+id)->name, item)!=0)){
                    id++;
                }
                if(id<noOfItem && (strcmp((manager+id)->supplier, supplierName)==0 && strcmp((manager+id)->name, item)==0)){
                    printf("\nhow much we need to order :- ");
                    scanf("%d", &quntatity);
                    printf("\nnew stock added\n");
                    (manager->stock) += quntatity;
                }else{
                    printf("\nEnter mrp of this product:- ");
                    scanf("%d", &mrp);
                    printf("\nEnter date:- ");
                    scanf("%s", date);
                    printf("\nhow much we need to order first time :- ");
                    scanf("%d", &quntatity);
                    manager = realloc(manager, (noOfItem+1)*sizeof(struct Inventory));
                    noOfItem++;
                    (manager + noOfItem - 1)->name = item;
                    (manager + noOfItem - 1)->date = date;
                    (manager + noOfItem - 1)->supplier = supplierName;
                    (manager + noOfItem - 1)->stock = quntatity;
                    (manager + noOfItem - 1)->mrp = mrp;
                }

            }else{
                printf("\nnothing to order now...");
            }
        }

        printf("\ndo you want to close the shop?(Y or N) :- ");
        scanf("%s", choice);
        if(strcmp(choice, "Y") == 0){
            isShopOpen = false;
        }
    }

    printf("closing stock\n\n\n");
    for(int i = 0; i<noOfItem; i++){
            printf("%d:-) %s %s %s %d %d\n", i , (manager + i)->name, (manager + i)->date, (manager + i)->supplier, (manager + i)->mrp, (manager + i)->stock);
	}

    stockFile = fopen("inventory.csv", "w");
    fprintf(stockFile, "%s","item name, date, supplier, mrp, stock\n");
    for(int i = 0; i<noOfItem-1; i++){
        fprintf(stockFile, "%s,%s,%s,%d,%d\n",(manager + i)->name, (manager + i)->date, (manager + i)->supplier, (manager + i)->mrp, (manager + i)->stock);
    }
    fprintf(stockFile, "%s,%s,%s,%d,%d",(manager + noOfItem-1)->name, (manager + noOfItem-1)->date, (manager + noOfItem-1)->supplier, (manager + noOfItem-1)->mrp, (manager + noOfItem-1)->stock);
    fclose(stockFile);

    return 0;
}

void readData(FILE* ifptr, struct Inventory* manager){
    if(ftell(ifptr) == 0){
        printf("%s\n",nextLine(ifptr));
    }
    manager->name = nextWordCsv(ifptr);
    manager->date = nextWordCsv(ifptr);
    manager->supplier = nextWordCsv(ifptr);
	fscanf(ifptr,"%d", &(manager->mrp));
    fseek(ifptr, 1, SEEK_CUR);
    fscanf(ifptr,"%d", &(manager->stock));

}

void resetStockPointer(struct Inventory* manager){
    
}
