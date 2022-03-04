all: app.exe test.exe
app.exe: main.o input.o operations.o output.o 
	gcc -o app.exe main.o input.o operations.o output.o

app.out: main.o input.o operations.o output.o
	gcc -o app.out main.o input.o operations.o output.o

main.o: main.c structs.h exit_codes.h input.h operations.h output.h
	gcc -std=c99 -Wall -Werror -c -pedantic main.c -lm

input.o: input.c input.h structs.h exit_codes.h output.h
	gcc -std=c99 -Wall -Werror -c -pedantic input.c -lm

operations.o: operations.c operations.h structs.h output.h input.h exit_codes.h
	gcc -std=c99 -Wall -Werror -c -pedantic operations.c -lm

output.o: output.c output.h structs.h
	gcc -std=c99 -Wall -Werror -c -pedantic output.c -lm

test.exe: test.c
	gcc -o test.exe test.c

clean:
	rm *.o*.exe
