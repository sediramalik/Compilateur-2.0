int main()
{

    int a = 10;
    int b,c,d;
    b = a;
    c = b;
    d = a;
    const int e = 100;

    if (a == 10) {
        a = a + 1;
    }
    else {
        b = b + 1;
    }
    while (b == c){
        a = b - c + d;
    }
    c = b;
}