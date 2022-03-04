all: app.exe
app.exe: main.o size_pixels.o
	gcc -o app.exe main.o size_pixels.o

app.out: main.o size_pixels.o
	gcc -o app.out main.o size_pixels.o

main.o: main.c exit_codes.h size_pixels.h structs.h
	gcc -std=c99 -Wall -Werror -c -pedantic main.c -lm

size_pixels.o: size_pixels.c size_pixels.h exit_codes.h structs.h 
	gcc -std=c99 -Wall -Werror -c -pedantic size_pixels.c -lm

clean:
	rm *.o*.exe
