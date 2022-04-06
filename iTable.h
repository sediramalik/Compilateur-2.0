#define SIZEMAX 1000

typedef struct {
    char iName[16];
    int arg1;
    int arg2;
    int arg3;
} instruction;

instruction * init_iTable();
void print_iTable(instruction * t);
void printInstruction(instruction i);
instruction addInstruction(instruction * t, char * iName, int arg1, int arg2, int arg3);