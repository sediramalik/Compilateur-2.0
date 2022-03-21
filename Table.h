#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define SIZEMAX 1000

typedef struct {
    char varname[16];
    char type0[16];
    char type[16];
    int value;
    int depth;
    int addr;

} symbol;

int addSymbol(symbol * t,symbol s);

int deleteSymbols(symbol * t);

