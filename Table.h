#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZEMAX 1000

typedef struct {
    char varname[16];
    char type0[16];
    char type[16];
    int depth;
    int addr;

} symbol;

symbol * initTable();
void printTable(symbol * t);
void printSymbol(symbol s);
symbol addSymbol(symbol * t, char * name, char * type0, char * type);
void deleteSymbols(symbol * t);
void incrementDepth();
int getAddr(symbol * t,char * targetname);
symbol unstack(symbol * t);
void addTmp(symbol * t, int depth);