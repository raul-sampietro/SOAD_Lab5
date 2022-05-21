all: program

program: program.c
	gcc -o program program.c

clean:
	rm -f *.txt
	rm -f program