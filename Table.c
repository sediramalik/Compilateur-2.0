
#include <stdio.h>
#include <string.h>
#include "Table.h"

int tableDepth=0;
int tableSize=0;


int main(){

//Allocate memory for table
symbol t[SIZEMAX];

symbol sa = {varname:"a", type0:"var  ", type:"int", value:5};
symbol sb = {varname:"b", type0:"const", type:"int", value:10};

symbol sc = {varname:"c", type0:"var  ", type:"int", value:15};
symbol sd = {varname:"d", type0:"const", type:"int", value:20};

addSymbol(t,sa);
addSymbol(t,sb);

printf("Added a & b ");
printTable(t);

incrementDepth(); //To simulate presence of if/while

addSymbol(t,sc);
addSymbol(t,sd);

printf("Added c & d ");

printTable(t);

deleteSymbols(t);

printf("Deleted symbols of max depth ");

printTable(t);

}

void printTable(symbol * t){
    printf("Content of table: \n");
    for (int i; i<tableSize; i++) {
        printSymbol(t[i]);
    }
}

void printSymbol(symbol s){
        printf("varname : %s\t",s.varname);
        printf("type0 : %s\t",s.type0);
        printf("type : %s\t",s.type);
        printf("value : %d\t",s.value);
        printf("depth : %d\t",s.depth);
        printf("addr : %d\t",s.addr);
        printf("\n");
}

int addSymbol(symbol * t, symbol s){
    s.depth=tableDepth;
    s.addr=tableSize;
    t[tableSize]=s;
    tableSize++;
}

//We decrease the size of the table by the number of symbols to delete
//which are the symbols of depth equal to table depth (max depth)

int deleteSymbols(symbol * t){
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
        if (t[i].varname==targetname){
            return i;
            break;
        }
    }
}

symbol unstack(symbol * t) {
    symbol head = t[tableSize];
    tableSize--;
    return head;
}

void addTmp(symbol * t, int depth) {
    symbol tmp = {varname:"tmp", type0:"var", type:"tmp", value:NULL};
    addSymbol(t,tmp);
    tableSize++;
}