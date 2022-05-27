
#include <stdio.h>
#include <string.h>
#include "sTable.h"

int sTableDepth = 0;
int sTableSize = 0;

symbol *init_sTable()
{
    // Allocate memory for table
    return malloc(SIZEMAX * sizeof(symbol));
}

void print_sTable(symbol *t)
{
    printf("Content of symbol table: \n");
    for (int i = 0; i < sTableSize; i++)
    {
        printSymbol(t[i]);
    }
}

void printSymbol(symbol s)
{
    printf("sName : %s\t", s.sName);
    printf("sAddr : %d\t", s.addr);
    printf("sType : %d\t", s.type);
    printf("sDepth : %d\t", s.depth);
    printf("\n");
}

symbol addSymbol(symbol *t, char *sName, int type)
{
    symbol s;
    s.depth = sTableDepth;
    s.addr = sTableSize;
    strcpy(s.sName, sName);
    s.type = type;
    t[sTableSize] = s;
    sTableSize++;
    printf("Added following symbol: \n");
    printSymbol(s);
    print_sTable(t);
    return s;
}

// We decrease the size of the table by the number of symbols to delete
// which are the symbols of depth equal to table depth (max depth)

void deleteSymbols(symbol *t)
{
    printf("Deleting symbols of depth %d\n", sTableDepth);
    int cnt = 0;
    for (int i = 0; i < sTableSize; i++)
    {
        symbol s = t[i];
        if (s.depth == sTableDepth)
        {
            cnt++;
        }
    }
    print_sTable(t);
    sTableSize -= cnt;
}

void incrementDepth(char *condition)
{
    printf("Entering %s condition\n", condition);
    sTableDepth++;
    printf("Imcrementing depth. Depth is now %d\n", sTableDepth);
}

void decrementDepth(char *condition)
{
    printf("Exiting %s condition\n", condition);
    sTableDepth--;
    printf("Decrementing depth. Depth is now %d\n", sTableDepth);
}

int getAddr(symbol *t, symbol target)
{
    for (int i = 0; i < sTableSize; i++)
    {
        if (t[i].addr == target.addr) // IF THEY'RE EQUAL
            return t[i].addr;
    }
    return -1; // NO SUCH SYMBOL FOUND IN TABLE
}

int getAddrName(symbol *t, char *targetname)
{
    for (int i = 0; i < sTableSize; i++)
    {
        if (strcmp(t[i].sName, targetname) == 0) // IF THEY'RE EQUAL
            return i;
    }
    return -1; // NO SUCH SYMBOL FOUND IN TABLE
}

symbol getSymbolByName(symbol *t, char *targetname)
{
for (int i = 0; i < sTableSize; i++)
    {
    if (strcmp(t[i].sName, targetname) == 0) // IF THEY'RE EQUAL
        return t[i];
    }
}

int unstack(symbol *t)
{ // FOR OPERATIONS
    sTableSize--;
    printf("Unstacked following symbol: \n");
    printSymbol(t[sTableSize]);
    print_sTable(t);
    return sTableSize;
}
