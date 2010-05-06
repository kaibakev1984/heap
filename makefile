CC = gcc
CFLAGS = -g -std=c99 -Wall -Wconversion -Wno-sign-conversion -Werror
VFLAGS = --leak-check=full --show-reachable=yes --track-origins=yes
GFLAGS = -tui
EXEC = pruebas
OBJFILES = heap.o main.o testing.o pruebas_heap_alumno.o

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