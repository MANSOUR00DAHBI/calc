# Makefile Projecte Calculator
.PHONY: cal
CC= gcc
CFLAGS= -Wall -Wextra -std=c11
OBJ= token.o stock.o eval.o calculator.o

#Main objective
cal: $(OBJ)
	$(CC) $(CFLAGS) -o cal $(OBJ)

# Target File Building Guidelines
token.o: token.c token.h
	$(CC) $(CFLAGS) -c token.c

stock.o: stock.c token.h
	$(CC) $(CFLAGS) -c stock.c

eval.o: eval.c token.h
	$(CC) $(CFLAGS) -c eval.c

calculator.o: calculator.c token.h
	$(CC) $(CFLAGS) -c calculator.c

#Clearing temporary files
clean:
	rm -f *.o calculator
