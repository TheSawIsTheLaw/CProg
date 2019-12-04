app.exe: main.o my_snprintf.o 
	gcc -std=c99 -Wall -Werror -o app.exe main.o my_snprintf.o 

test.exe: test.o my_snprintf.o
	gcc -std=c99 -Wall -Werror -o test.exe test.o my_snprinf.o
	
main.o: main.c
	gcc -std=c99 -c -Wall -Werror -o main.o main.c
	
my_snprintf.o: my_snprintf.c
	gcc -std=c99 -c -Wall -Werror -o my_snprintf.o my_snprintf.c
	
test.o: tests/test.c
	gcc -std=c99 -c -Wall -Werror -o test.o tests/test.c
	
clean:
	rm *.o *.exe
