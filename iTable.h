#define SIZEMAX 1000

typedef struct
{
    int num;
    char iName[16];
    int arg1;
    int arg2;
    int arg3;
    char function[16]; //FOR FUNCTION JUMPS
} instruction;

typedef struct
{
    int arg1;
    int arg2;
    int arg3;
} condition;

instruction *init_iTable();
void print_iTable(instruction *t);
void printInstruction(instruction i);
instruction addInstruction(instruction *t, char *iName, int arg1, int arg2, int arg3);
void updateJMFInstruction(instruction *t, int numAsmLines);
void updateJMPInstruction(instruction *t, int numAsmLines);
void updateJMFInstructionOne(instruction *t);
void updateJMPInstructionBackwards(instruction *t, int numAsmLines);
condition construct_cond(int arg1, int arg2, int arg3);
condition init_cond();
instruction addJMPFunctionInstruction(instruction *t, char *iName, int arg1, int arg2, int arg3, char * function);
void printJMPFunctionInstruction(instruction i);
findLine(instruction *t, char * functionName);