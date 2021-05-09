CC = gcc
FLAGS = -Wall

output: build/main.o build/dynarray.o
	$(CC) $(FLAGS) build/main.o build/dynarray.o -o build/output

build/main.o: src/main.c
	$(CC) $(FLAGS) src/main.c -c -o build/main.o

build/dynarray.o: src/dynarray.c src/dynarray.h
	$(CC) $(FLAGS) src/dynarray.c  -c -o build/dynarray.o

clean:
	rm *.o output
