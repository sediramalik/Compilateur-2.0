
  
int main()
{

    int a = 10;
    int b,c,d;
    b = a;
    c = b;
    d = c;
    const int e = 100;
    const int f,g;

    if (a == 10) {
        a = a + 1;
    }
    else {
        b = b + 1;
    }
    while (b == c){
        a = b - c + d;
        print(a);
    }
    c = b;
    print(42);

    f = b;
    g = 3;
    if (f){
        print(g);
    }

}