#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZEMAX 1000

typedef struct {
    char sName[16];
    int type0;
    int type;
    int depth;
    int addr;

} symbol;

symbol * init_sTable();
void print_sTable(symbol * t);
void printSymbol(symbol s);
symbol addSymbol(symbol * t, char * name, int type0, int type);
void deleteSymbols(symbol * t);
void incrementDepth();
void decrementDepth();
int getAddr(symbol * t,char * targetname);
symbol unstack(symbol * t);
void addTmp(symbol * t, int depth);