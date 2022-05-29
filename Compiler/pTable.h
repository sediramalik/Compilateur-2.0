#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZEMAX 1000

typedef struct
{
    int num;
    char functionName[16];
    int parameter;
} parameter;

parameter *init_pTable();
void print_pTable(parameter *t);
void printParameter(parameter p);
parameter addParameter(parameter *t, char *FunName, int parameter);
int findPassedParameter(parameter *t, char *funName, int countArgs);