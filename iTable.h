#define SIZEMAX 1000

typedef struct {
    char iName[16];
    int rightVarIndex;
    int leftVarIndex;
    int result;
} instruction;

instruction * init_iTable();
void print_iTable(instruction * t);
void printInstruction(instruction i);
instruction addInstruction(instruction * t, char * iName, int var1, int var2, int result);