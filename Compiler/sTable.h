#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZEMAX 1000

typedef struct
{
    char sName[16];
    int type; // 1 IS GOR VAR AND 2 FOR CONST
    int depth;
    int addr;
    int assigned; //FOR CONSTANTS TO AVOID RE-ASSIGNING THEM TO A VALUE
} symbol;

symbol *init_sTable();
void print_sTable(symbol *t);
void printSymbol(symbol s);
symbol addSymbol(symbol *t, char *name, int type);
void deleteSymbols(symbol *t);
void incrementDepth(char *condition);
void decrementDepth(char *condition);
int getAddr(symbol *t, symbol s);
int getAddrName(symbol *t, char *targetname, int sTableDepth);
int unstack(symbol *t);
symbol getSymbolByName(symbol *t, char *targetname, int sTableDepth);
void const_assigned(symbol* s);
symbol addSymbolAssigned(symbol *t, char *sName, int type);
