#include <stdio.h>
#include <string.h>
#include "pTable.h"

int pTableSize = 0;
// THIS TABLE IS USED TO STORE THE DIFFERENT ADDRESSES OF THE PASSED PARAMETERS OF EACH FUNCTION
// THIS WILL HELP WITH ASSIGNING THE VALEUS OF THE PASSED PARAMETERS TO THE VARIABLES IN () AT FUNCTION DECLARATIONS

parameter *init_pTable()
{
    // Allocate memory for table
    return malloc(SIZEMAX * sizeof(parameter));
}

void print_pTable(parameter *t)
{
    printf("Content of passed parameters table: \n");
    for (int i = 0; i < pTableSize; i++)
    {
        printParameter(t[i]);
    }
}

void printParameter(parameter p)
{
    printf(" %d\t", p.num);
    printf(" %s\t", p.functionName);
    printf(" %d\t", p.parameter);
    printf("\n");
}

parameter addParameter(parameter *t, char *FunName, int par)
{
    parameter p;
    p.num = pTableSize;
    strcpy(p.functionName, FunName);
    p.parameter = par;
    t[pTableSize] = p;
    pTableSize++;
    printf("Added following parameter: \n");
    printParameter(p);
    print_pTable(t);

    return p;
}

int findPassedParameter(parameter *t, char *funName, int countArgs)
{
    int count = 0;
    for (int i = 0; i < pTableSize; i++)
    {
        if (strcmp(funName, t[i].functionName) == 0)
        {
            if (countArgs == count)
            {
                return t[i].parameter;
            }
            count++;
        }
    }
}