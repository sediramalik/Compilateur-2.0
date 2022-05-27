#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iTable.h"

int iTableSize = 0;
FILE *ASM;

instruction *init_iTable()
{
    // Allocate memory for table
    return malloc(SIZEMAX * sizeof(instruction));
}

void print_iTable(instruction *t)
{
    printf("Content of instruction table: \n");
    for (int i = 0; i < iTableSize; i++)
    {
        printInstruction(t[i]);
    }
}
void printInstruction(instruction i)
{
    printf(" %d\t", i.num);
    printf(" %s\t", i.iName);
    printf(" %d\t", i.arg1);
    printf(" %d\t", i.arg2);
    printf(" %d\t", i.arg3);
    printf("\n");
}

instruction addInstruction(instruction *t, char *iName, int arg1, int arg2, int arg3)
{
    instruction i;
    i.num = iTableSize;
    strcpy(i.iName, iName);
    i.arg1 = arg1;
    i.arg2 = arg2;
    i.arg3 = arg3;
    t[iTableSize] = i;
    iTableSize++;
    fprintf(ASM, "%d\t %s\t %d\t %d\t %d\t", i.num, i.iName, i.arg1, i.arg2, i.arg3);
    fprintf(ASM, "\n");
    printf("Added instruction: \n");
    printInstruction(i);
    print_iTable(t);
    return i;
}

// UPDATES THE MOST RECENT JMF INSTRUCTION WITH THE NUMBER OF INSTRUCTION LINES GENERATED IN THE BODY OF THE IF CONDITION
// ARG2 IS UPDATED
void updateJMFInstruction(instruction *t, int numAsmLines)
{
    for (int i = iTableSize; i > 0; i -= 1)
    {
        printInstruction(t[i]);
        if (strcmp("JMF", t[i].iName) == 0)
        {
            printf("FOUND JMF INSTRUCTION AT INDEX %d\n", t[i].num);
            printf("JUMPING %d INSTRUCTIONS\n", numAsmLines);
            t[i].arg2 = numAsmLines + t[i].num + 1 ; 
            break;
        }
    }
}

//IN CASE THERE IS AN ELSE, THE JMF NEEDS TO BE PATCHED TO SKIP THE JMP INSTRUCTION CREATED BY ELSE
void updateJMFInstructionOne(instruction *t)
{
    for (int i = iTableSize; i > 0; i -= 1)
    {
        if (strcmp("JMF", t[i].iName) == 0)
        {
            t[i].arg2++;
            break;
        }
    }
}

// ARG1 IS UPDATED
void updateJMPInstruction(instruction *t, int numAsmLines)
{
    for (int i = iTableSize; i > 0; i -= 1)
    {
        printInstruction(t[i]);
        if (strcmp("JMP", t[i].iName) == 0)
        {
            printf("FOUND JMF INSTRUCTION AT INDEX %d\n", t[i].num);
            printf("JUMPING %d INSTRUCTIONS\n", numAsmLines);
            t[i].arg1 = numAsmLines + t[i].num + 1;
            break;
        }
    }
}

void updateJMPInstructionBackwards(instruction *t, int numAsmLines)
{
    for (int i = iTableSize; i > 0; i -= 1)
    {
        printInstruction(t[i]);
        if (strcmp("JMP", t[i].iName) == 0)
        {
            printf("FOUND JMF INSTRUCTION AT INDEX %d\n", t[i].num);
            printf("JUMPING %d INSTRUCTIONS\n", numAsmLines);
            t[i].arg1 = t[i].num - numAsmLines - 1;
            break;
        }
    }
}