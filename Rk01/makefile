app.out: main.o handler_input.o sort_matr_hand.o handler_output.o
	gcc -o app.out main.o handler_input.o sort_matr_hand.o handler_output.o

main.o: main.c handler_input.h sort_matr_hand.h handler_output.h exit_codes.h
	gcc -std=c99 -Wall -Werror -pedantic -c -g main.c -lm

handler_input.o: handler_input.c handler_input.h
	gcc -std=c99 -Wall -Werror -pedantic -c -g handler_input.c -lm

sort_matr_hand.o: sort_matr_hand.c sort_matr_hand.h
	gcc -std=c99 -Wall -Werror -pedantic -c -g sort_matr_hand.c -lm

handler_output.o: handler_output.c handler_output.h
	gcc -std=c99 -Wall -Werror -pedantic -c -g handler_output.c -lm

clean:
	rm *.o*.exe
