tx: main.o
	gcc main.o -o tx

main.o: main.c
	gcc -c main.c

clean:
	del main.o tx.exe

run:
	make
	tx.exe main.c