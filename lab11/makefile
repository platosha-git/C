all: test.exe

test.exe: test.o my_snprintf.o
	gcc -o test.exe test.o my_snprintf.o

app.exe: main.o
	gcc -o app.exe main.o

test.o: test.c
	gcc -Werror -Wall -pedantic -std=c99 -c test.c

main.o: main.c
	gcc -Werror -Wall -pedantic -std=c99 -c main.c

my_snprintf.o: my_snprintf.c
	gcc -Werror -Wall -pedantic -std=c99 -c my_snprintf.c

clean:
	rm *.o *.exe
