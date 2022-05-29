#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZEMAX 1000

typedef struct
{
    char functionName[16];
    int par1;
    int par2;
    int par3;
} parameters;

parameters *init_pTable();
void print_pTable(parameters *t);
void printParameters(parameters p);
parameters addParameters(parameters *t, char *FunName, int p1, int p2, int p3);