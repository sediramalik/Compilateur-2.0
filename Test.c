int main()
{

    int a = 10;
    int b = a;
    int c = b;
    int d = a;

    if (a == 10) {
        a = a + 1;
    }
    else {
        b = b + 1;
    }
    while (b == c){
        a = b - c + d;
    }

    //PROBLEM: WHILE AFTER ELSE ALTERS THE JMP INSTRUCTION 
    //OF ELSE


}