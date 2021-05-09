CC = gcc
FLAGS = -Wall

output: build/main.o
	$(CC) $(FLAGS) build/main.o  -o build/output

build/main.o: src/main.c
	$(CC) $(FLAGS) src/main.c -c -o build/main.o

run:
	make clean && make && ./build/output

clean:
	rm build/*.o build/output

