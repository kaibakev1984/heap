CC = gcc
CFLAGS = -g -O2 -std=c99 -Wall -Wtype-limits -pedantic -Wconversion -Wno-sign-conversion -Wbad-function-cast -Wshadow -Wpointer-arith -Wunreachable-code -Wformat=2 -Werror
VFLAGS = --leak-check=full --show-reachable=yes --track-origins=yes
GFLAGS = -tui
EXEC = pruebas
OBJFILES = heap.o main.o testing.o pruebas_heap_alumno.o mergesort.o

%.o: %.c %.h 
	$(CC) $(CFLAGS) -c $<
$(EXEC): $(OBJFILES)
	$(CC) $(CFLAGS) $(OBJFILES) -o $(EXEC)
all: $(EXEC)
run: all
	./$(EXEC)
valgrind: all
	valgrind $(VFLAGS) ./$(EXEC)
clear:
	clear
clean: $(OBJFILES)
	rm -f $(EXEC) *.o
gdb: all clear
	gdb $(GFLAGS) ./$(EXEC)
zip: heap.c pruebas_heap_alumno.c
	zip heap.zip heap.c heap.h pruebas_heap_alumno.c mergesort.c mergesort.h