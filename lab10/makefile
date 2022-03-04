all: app.exe test.exe
app.exe: main.o in_hand.o correct_input.o changes.o out_hand.o
	gcc -o app.exe main.o in_hand.o changes.o out_hand.o correct_input.o

app.out: main.o in_hand.o correct_input.o changes.o out_hand.o
	gcc -o app.out main.o in_hand.o changes.o out_hand.o correct_input.o

main.o: main.c in_hand.h correct_input.h changes.h out_hand.h exit_codes.h
	gcc -std=c99 -Wall -Werror -c -pedantic main.c -lm

in_hand.o: in_hand.c in_hand.h
	gcc -std=c99 -Wall -Werror -c -pedantic in_hand.c -lm

correct_input.o: correct_input.c correct_input.h
	gcc -std=c99 -Wall -Werror -c -pedantic correct_input.c -lm

changes.o: changes.c changes.h
	gcc -std=c99 -Wall -Werror -c -pedantic changes.c -lm

out_hand.o: out_hand.c out_hand.h
	gcc -std=c99 -Wall -Werror -c -pedantic out_hand.c -lm

test.exe: test.c
	gcc -o test.exe test.c

clean:
	rm *.o*.exe
