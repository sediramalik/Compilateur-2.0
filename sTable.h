#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZEMAX 1000

typedef struct {
    char sName[16];
    int type;
    int depth;
    int addr;
    int value;
} symbol;

symbol * init_sTable();
void print_sTable(symbol * t);
void printSymbol(symbol s);
symbol addSymbol(symbol * t, char * name, int type, int value);
void deleteSymbols(symbol * t);
void incrementDepth();
void decrementDepth();
int getAddr(symbol * t,symbol s);
int getAddrName(symbol * t,char * targetname);
int unstack(symbol * t);
