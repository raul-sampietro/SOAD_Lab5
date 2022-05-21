all: encryption_test

encryption_test: encryption_test.c
	gcc -o encryption_test encryption_test.c

clean:
	rm -f *.txt
	rm -f encryption_test