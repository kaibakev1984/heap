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
test: all
	./$(EXEC)
run: all 
	clear
	./$(EXEC)
	valgrind $(VFLAGS) ./$(EXEC)
	rm -f $(EXEC) *.o
	zip	heap.zip heap.c heap.h pruebas_heap_alumno.c mergesort.c mergesort.h
valgrind: all
	valgrind $(VFLAGS) ./$(EXEC)
gdb: all
	gdb $(GFLAGS) ./$(EXEC)
clean: *.zip
	rm -f *.zip