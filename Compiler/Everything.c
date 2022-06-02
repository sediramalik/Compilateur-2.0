void main()
{
    int a = 10;
    const int b = 20;
    int c;
    c = 30;
    const int d;
    d = 40;
    int e;
    e = a + b - c * d;
    if (a){
        fun1(b);
        print(c);
    }
    if (a == b){
        int la = a;
        int lb = b;
        int lc;
        lc = la + lb;
        print(lc);
    }
    else{
        print(e);
        fun2(e, d);
    }
    while (a){
        print(c);
    }
    while (a > b + c){
        int ld = 50;
        int le;
        int lf;
        le = fun3(ld) + c;
        lf = fun4(a, b, c, d, e) - le + ld;
    }
}
void fun1(int x) { print(x); }
void fun2(int x, int y){
    y = x;
    print(x);
}
int fun3(int x){
    x = x + 1;
    return x;
}
int fun4(int a, int b, int c, int d, int e){
    const int result;
    result = a + b - c * d / e;
    return result;
}
