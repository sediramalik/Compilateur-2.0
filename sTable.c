
#include <stdio.h>
#include <string.h>
#include "sTable.h"

int sTableDepth=0;
int sTableSize=0;


// int main(){
// symbol * t = initTable();
// symbol sa,sb,sc,sd;
// sa=addSymbol(t,"a","var","int");
// sb=addSymbol(t,"b","conxt","int");
// printf("Added a & b ");
// print_sTable(t);
// incrementDepth(); //To simulate presence of if/while
// sc=addSymbol(t,"a","var","int");
// sd=addSymbol(t,"b","conxt","int");
// printf("Added c & d ");
// print_sTable(t);
// deleteSymbols(t);
// printf("Deleted symbols of max depth ");
// print_sTable(t);
// }

symbol * init_sTable(){
    //Allocate memory for table
    return malloc(SIZEMAX*sizeof(symbol));
}

void print_sTable(symbol * t){
    for (int i=0; i<sTableSize; i++) {
        printSymbol(t[i]);
    }
}

void printSymbol(symbol s){
        printf("sName : %s\t",s.sName);
        printf("sAddr : %d\t",s.addr);
        printf("sType : %d\t",s.type);
        printf("sValue : %d\t",s.value);
        printf("sDepth : %d\t",s.depth);
        printf("\n");
}

symbol addSymbol(symbol * t, char * sName, int type, int value){
    symbol s;
    s.depth=sTableDepth;
    s.addr=sTableSize;
    strcpy(s.sName,sName);
    s.type=type;
    s.value=value;
    t[sTableSize]=s;
    sTableSize++;
    return s;
}

//We decrease the size of the table by the number of symbols to delete
//which are the symbols of depth equal to table depth (max depth)

void deleteSymbols(symbol * t){
    int cnt = 0;
    for (int i; i <sTableSize; i++) {
        symbol s = t[i];
        if (s.depth == sTableDepth) {
            cnt++;
        }
    }
    sTableSize -= cnt;

}

void incrementDepth(){
    sTableDepth++;
}

void decrementDepth(){
    sTableDepth--;
}

int getAddr(symbol * t,symbol target){
    for (int i=0; i<sTableSize; i++){
        if (t[i].addr==target.addr)//IF THEY'RE EQUAL
            return t[i].addr;
    }
        return -1; //NO SUCH SYMBOL FOUND IN TABLE
}

int getAddrName(symbol * t,char * targetname){
    for (int i=0; i<sTableSize; i++){
        if (strcmp(t[i].sName,targetname)==0) //IF THEY'RE EQUAL
            return i;
    }
        return -1; //NO SUCH SYMBOL FOUND IN TABLE
}

int unstack(symbol * t) { //FOR OPERATIONS
    sTableSize--;
    return sTableSize;
}

