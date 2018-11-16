all: fk.o
	gcc fk.o

fk.o: fk.c
	gcc -c fk.c

run:
	./a.out

clean:
	rm *.o
