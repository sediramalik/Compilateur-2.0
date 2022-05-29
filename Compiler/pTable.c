#include <stdio.h>
#include <string.h>
#include "pTable.h"

int pTableSize = 0;
//THIS TABLE IS USED TO STORE THE DIFFERENT ADDRESSES OF THE PASSED PARAMETERS OF EACH FUNCTION
//THIS WILL HELP WITH ASSIGNING THE VALEUS OF THE PASSED PARAMETERS TO THE VARIABLES IN () AT FUNCTION DECLARATIONS
//FOR NOW ONLY 5 PARAMETERS CAN BE PASSED 

parameters *init_pTable()
{
    // Allocate memory for table
    return malloc(SIZEMAX * sizeof(parameters));
}

void print_pTable(parameters *t)
{
    printf("Content of passed parameters table: \n");
    for (int i = 0; i < pTableSize; i++)
    {
        printParameters(t[i]);
    }
}

void printParameters(parameters p)
{
    printf("FunName : %s\t", p.functionName);
    printf("@p1 : %d\t", p.par1);
    printf("@p2 : %d\t", p.par2);
    printf("@p3 : %d\t", p.par3);
    printf("@p4 : %d\t", p.par4);
    printf("@p5 : %d\t", p.par5);
    printf("\n");
}

parameters addParameters(parameters *t, char *FunName, int p1, int p2, int p3, int p4, int p5)
{
    parameters p;
    strcpy(p.functionName,FunName);
    p.par1=p1;
    p.par2=p2;
    p.par3=p3;
    p.par4=p4;
    p.par5=p5;
    t[pTableSize] = p;
    pTableSize++;
    printf("Added following parameters: \n");
    printParameters(p);
    print_pTable(t);

    return p;
}