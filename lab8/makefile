all: app.exe test.exe
app.exe: main.o handler_input.o operations.o handler_output.o
	gcc -o app.exe main.o handler_input.o operations.o handler_output.o

main.o: main.c handler_input.h exit_codes.h operations.o handler_output.h
	gcc -std=c99 -Wall -Werror -pedantic -c main.c

handler_input.o: handler_input.c handler_input.h exit_codes.h
	gcc -std=c99 -Wall -Werror -pedantic -c handler_input.c

operations.o: operations.c operations.h exit_codes.h
	gcc -std=c99 -Wall -Werror -pedantic -c operations.c

handler_output.o: handler_output.c handler_output.h exit_codes.h
	gcc -std=c99 -Wall -Werror -pedantic -c handler_output.c

test.exe: test.c
	gcc -o test.exe test.c

clean:
	rm *.o*.exe

