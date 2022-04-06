#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iTable.h"

int iTableSize=0;

instruction * init_iTable(){
    //Allocate memory for table
    return malloc(SIZEMAX*sizeof(instruction));
}

void print_iTable(instruction * t){
    for (int i=0; i<iTableSize; i++) {
        printInstruction(t[i]);
    }
}
void printInstruction(instruction i){
        printf("iName : %s\t",i.iName);
        printf("iArg1 : %d\t",i.arg1);
        printf("iArg2 : %d\t",i.arg2);
        printf("iArg3 : %d\t",i.arg3);
        printf("\n");
}

instruction addInstruction(instruction * t, char * iName, int arg1, int arg2, int arg3){
    instruction i;
    strcpy(i.iName,iName);
    i.arg1=arg1;
    i.arg2=arg2;
    i.arg3=arg3;
    t[iTableSize]=i;
    iTableSize++;
    return i;

}