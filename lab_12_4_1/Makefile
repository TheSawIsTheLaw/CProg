app.exe: main.o list.o out.o mul.o div.o sqr.o
	gcc -std=c99 -Wall -Werror -o app.exe main.o list.o out.o mul.o div.o sqr.o
	
test.exe: test.o
	gcc -std=c99 -Wall -Werror -o test.exe test.o
	
test.o: tests/test.c
	gcc -std=c99 -Wall -Werror -g -c -o test.o tests/test.c

main.o: main.c
	gcc -std=c99 -Wall -Werror -g -c -o main.o main.c
	
out.o: funcs/out.c
	gcc -std=c99 -Wall -Werror -g -c -o out.o funcs/out.c
	
mul.o: funcs/mul.c
	gcc -std=c99 -Wall -Werror -g -c -o mul.o funcs/mul.c

div.o: funcs/div.c
	gcc -std=c99 -Wall -Werror -g -c -o div.o funcs/div.c
	
sqr.o: funcs/sqr.c
	gcc -std=c99 -Wall -Werror -g -c -o sqr.o funcs/sqr.c
	
list.o: funcs/list.c
	gcc -std=c99 -Wall -Werror -g -c -o list.o funcs/list.c

clean:
	rm *.o *.exe
	
vg_clean:
	rm vgcore.*
