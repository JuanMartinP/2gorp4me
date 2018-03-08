CC=gcc
CFLAGS= -g -Wall -ansi -pedantic
all: p2_e2
p2_e2: element-int.o stack_element.o p2_e2.o
	$(CC) $(CFLAGS) element-point.o stack_element.o p2_e2.o -o p2_e2

#Objetos
element-point.o: element-point.c element.h stack_element.h types.h
	$(CC) $(CFLAGS) -c element-int.c

stack_element.o: stack_element.c element.h stack_element.h types.h
	$(CC) $(CFLAGS) -c stack_element.c

p2_e2.o: p2_e2.c element.h stack_element.h types.h
	$(CC) $(CFLAGS) -c p2_e2.c

#Borrar objetos
clean:
	rm -f *.o
