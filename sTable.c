
#include <stdio.h>
#include <string.h>
#include "sTable.h"

int tableDepth=0;
int tableSize=0;


// int main(){

// symbol * t = initTable();
// symbol sa,sb,sc,sd;

// sa=addSymbol(t,"a","var","int");
// sb=addSymbol(t,"b","conxt","int");

// printf("Added a & b ");
// printTable(t);

// incrementDepth(); //To simulate presence of if/while

// sc=addSymbol(t,"a","var","int");
// sd=addSymbol(t,"b","conxt","int");

// printf("Added c & d ");

// printTable(t);

// deleteSymbols(t);

// printf("Deleted symbols of max depth ");

// printTable(t);

// }

symbol * initTable(){
    //Allocate memory for table
    return malloc(SIZEMAX*sizeof(symbol));
}

void printTable(symbol * t){
    for (int i=0; i<tableSize; i++) {
        printSymbol(t[i]);
    }
}

void printSymbol(symbol s){
        printf("varname : %s\t",s.varname);
        printf("type0 : %d\t",s.type0);
        printf("type : %d\t",s.type);
        printf("depth : %d\t",s.depth);
        printf("addr : %d\t",s.addr);
        printf("\n");
}

symbol addSymbol(symbol * t, char * name, int type0, int type){
    symbol s;
    s.depth=tableDepth;
    s.addr=tableSize;
    strcpy(s.varname,name);
    s.type0=type0;
    s.type=type;
    t[tableSize]=s;
    tableSize++;
    return s;
}

//We decrease the size of the table by the number of symbols to delete
//which are the symbols of depth equal to table depth (max depth)

void deleteSymbols(symbol * t){
    int cnt = 0;
    for (int i; i <tableSize; i++) {
        symbol s = t[i];
        if (s.depth == tableDepth) {
            cnt++;
        }
    }
    tableSize -= cnt;

}

void incrementDepth(){
    tableDepth++;
}

int getAddr(symbol * t,char * targetname){
    for (int i=0; i<tableSize; i++){
        if (strcmp(t[i].varname,targetname)==0)
            return i;
        else return -1;
    }
}

symbol unstack(symbol * t) {
    symbol head = t[tableSize];
    tableSize--;
    return head;
}

void addTmp(symbol * t, int depth) {
    addSymbol(t,"tmp",-1,-1);
}