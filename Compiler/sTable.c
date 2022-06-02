
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
    printf("sAssigned : %d\t", s.assigned);
    printf("\n");
}

symbol addSymbol(symbol *t, char *sName, int type)
{
    symbol s;
    s.depth = sTableDepth;
    s.addr = sTableSize;
    strcpy(s.sName, sName);
    s.type = type;
    s.assigned = 0;
    t[sTableSize] = s;
    sTableSize++;
    printf("Added following symbol: \n");
    printSymbol(s);
    print_sTable(t);

    return s;
}

symbol addSymbolAssigned(symbol *t, char *sName, int type) // FOR CONSTANTS
{
    symbol s;
    s.assigned = 1;
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
    printf("Entering %s \n", condition);
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
    int ret = -1;
    int depthAux=sTableDepth;
    depthAux++;
    while ((ret == -1) && depthAux >= 0)
    {
        depthAux--;
        for (int i = 0; i < sTableSize; i++)
        {
            if (t[i].addr == target.addr) // IF THEY'RE EQUAL
                ret = t[i].addr;
        }
    }
    return ret; // NO SUCH SYMBOL FOUND IN TABLE
}

// ONLY VARIABLES OF THE SAME DEPTH CAN BE ASSIGNED TO EACH OTHER
int getAddrName(symbol *t, char *targetname)
{
    int target = -1;
    int depthAux=sTableDepth;
    depthAux++;
    while ((target == -1) && depthAux >= 0)
    {
        depthAux--;
        for (int i = 0; i < sTableSize; i++)
        {
            if ((strcmp(t[i].sName, targetname) == 0) && (t[i].depth == depthAux))
                target = i;
        }
        // NO SUCH SYMBOL FOUND IN TABLE
    }
    return target;
}

symbol getSymbolByName(symbol *t, char *targetname)
{
    int target = -1;
    int depthAux=sTableDepth;
    depthAux++;
    while ((target == -1) && depthAux >= 0)
    {
        depthAux--;
        for (int i = 0; i < sTableSize; i++)
        {
            if ((strcmp(t[i].sName, targetname) == 0) && (t[i].depth == depthAux))
                target = i;
        }
    }
    return t[target];
}

int unstack(symbol *t)
{ // FOR OPERATIONS
    sTableSize--;
    printf("Unstacked following symbol: \n");
    printSymbol(t[sTableSize]);
    print_sTable(t);
    return sTableSize;
}

void const_assigned(symbol *s)
{
    (*s).assigned = 1;
}
