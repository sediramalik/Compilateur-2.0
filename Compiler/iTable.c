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

void printJMPFunctionInstruction(instruction i)
{
    printf(" %d\t", i.num);
    printf(" %s\t", i.iName);
    printf(" %d\t", i.arg1);
    printf(" %d\t", i.arg2);
    printf(" %d\t", i.arg3);
    //printf(" %s\t", i.function);
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

instruction addInstructionWithFunctionName(instruction *t, char *iName, int arg1, int arg2, int arg3, char *function)
{
    instruction i;
    i.num = iTableSize;
    strcpy(i.iName, iName);
    i.arg1 = arg1;
    i.arg2 = arg2;
    i.arg3 = arg3;
    strcpy(i.function, function);
    t[iTableSize] = i;
    iTableSize++;
    //fprintf(ASM, "%d\t %s\t %d\t %d\t %d\t %s\t", i.num, i.iName, i.arg1, i.arg2, i.arg3, i.function);
    fprintf(ASM, "%d\t %s\t %d\t %d\t %d\t %s\t", i.num, i.iName, i.arg1, i.arg2, i.arg3);
    fprintf(ASM, "\n");
    printf("Added instruction: \n");
    printJMPFunctionInstruction(i);
    print_iTable(t);
    return i;
}

instruction addInstructionWithReturn(instruction *t, char *iName, int arg1, int arg2, int arg3, char *function)
{
    instruction i;
    i.num = iTableSize;
    strcpy(i.iName, iName);
    i.arg1 = arg1;
    i.arg2 = arg2;
    i.arg3 = arg3;
    strcpy(i.ret, function);
    printf("----------------funName inside function-----------------: %s\n",i.ret);
    t[iTableSize] = i;
    iTableSize++;
    //fprintf(ASM, "%d\t %s\t %d\t %d\t %d\t %s\t", i.num, i.iName, i.arg1, i.arg2, i.arg3, i.function);
    fprintf(ASM, "%d\t %s\t %d\t %d\t %d\t %s\t", i.num, i.iName, i.arg1, i.arg2, i.arg3);
    fprintf(ASM, "\n");
    printf("Added instruction: \n");
    printJMPFunctionInstruction(i);
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
            t[i].arg2 = numAsmLines + t[i].num + 1;
            break;
        }
    }
}

// IN CASE THERE IS AN ELSE, THE JMF NEEDS TO BE PATCHED TO SKIP THE JMP INSTRUCTION CREATED BY ELSE
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

condition construct_cond(int arg1, int arg2, int arg3)
{
    condition cond;
    cond.arg1 = arg1;
    cond.arg2 = arg2;
    cond.arg3 = arg3;
    return cond;
}

condition init_cond()
{
    condition cond;
    cond.arg1 = 0;
    cond.arg2 = 0;
    cond.arg3 = 0;
    return cond;
}

findJMPLine(instruction *t, char *functionName)
{
    for (int i = 0; i < iTableSize; i++)
    {
        if (strcmp(functionName, t[i].function) == 0)
        {
            return i;
        }
    }
}

void updateCOPInstruction(instruction *t, int address, char *functionName)
{
    for (int i = 0; i < iTableSize; i++)
    {
        printf("Function name: %s\n",functionName);
        printf("Instruction:\n");
        printInstruction(t[i]);
        printf("Instruction return: %s\n",t[i].ret);
        if (strcmp(functionName, t[i].ret) == 0)
        {
            printf("////////////////////////////////////////");
            //printf("Address: %s\n",address);
            printf("////////////////////////////////////////");
            t[i].arg2 = address;
        }
    }
}

void updateJMPInstructionFunction(instruction *t, int patch, char *functionName, int argsDeclared)
{
    for (int i = 0; i < iTableSize; i++)
    {
        if (strcmp(functionName, t[i].function) == 0)
        {
            t[i].arg1 = patch - argsDeclared;
        }
    }
}