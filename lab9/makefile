all: app.exe test.exe
app.exe: main.o handler_input.o squaring.o expansion.o multiply.o handler_output.o
	gcc -o app.exe main.o handler_input.o squaring.o expansion.o multiply.o handler_output.o

main.o: main.c handler_input.h squaring.h expansion.h exit_codes.h multiply.h
	gcc -std=c99 -Wall -Werror -pedantic -c main.c -lm

handler_input.o: handler_input.c handler_input.h
	gcc -std=c99 -Wall -Werror -pedantic -c handler_input.c -lm

squaring.o: squaring.c squaring.h
	gcc -std=c99 -Wall -Werror -pedantic -c squaring.c -lm

expansion.o: expansion.c expansion.h
	gcc -std=c99 -Wall -Werror -pedantic -c expansion.c -lm

multiply.o: multiply.c multiply.h
	gcc -std=c99 -Wall -Werror -pedantic -c multiply.c -lm

handler_output.o: handler_output.c handler_output.h
	gcc -std=c99 -Wall -Werror -pedantic -c handler_output.c -lm

test.exe: test.c
	gcc -o test.exe test.c

clean:
	rm *.o*.exe

