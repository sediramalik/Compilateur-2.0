GRM=Yacc.y
LEX=Lex.l
BIN=comp

CC=gcc
CFLAGS=-Wall -g

OBJ=y.tab.o lex.yy.o

all: $(BIN)

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

y.tab.c: $(GRM)
	yacc -d -t -v $<

lex.yy.c: $(LEX)
	flex $<

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

clean:
	rm $(OBJ) y.tab.c y.tab.h lex.yy.c ASM

test:   all
	./$(BIN) < test.c
	
depth:   all
	./$(BIN) < Depth.c

ifelse:   all
	./$(BIN) < IfElse.c
	
intfun:   all
	./$(BIN) < IntFun.c
	
intfunp:   all
	./$(BIN) < IntFunP.c
	
op:   all
	./$(BIN) < Op.c

var:   all
	./$(BIN) < Var.c
	
voidfun:   all
	./$(BIN) < VoidFun.c
	
while_:   all
	./$(BIN) < While.c
	
everything:   all
	./$(BIN) < Everything.c
	
interpreter:   all
	./$(BIN) < Interpreter.c
	
	
	
	
