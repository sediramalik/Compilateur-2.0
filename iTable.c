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
        printf("instruction_name : %s\t",i.iName);
        printf("\n");
}

instruction addInstruction(instruction * t, char * iName, int var1, int var2, int result){
    instruction i;
    strcpy(i.iName,iName);
    i.rightVarIndex=var1;
    i.leftVarIndex=var2;
    i.result=result;
    t[iTableSize]=i;
    iTableSize++;
    return i;

}