test.exe: test.o my_snprintf.o
	gcc -std=c99 -Wall -Werror -o test.exe test.o my_snprintf.o
	
testdeb: deb_test.o deb_my_snprintf.o
	gcc -std=c99 -Wall -Werror -g -o test.exe debtest.o deb_my_snprintf.o
	
deb_my_snprintf.o: my_snprintf.c
	gcc -std=c99 -c -g -Wall -Werror -o deb_my_snprintf.o my_snprintf.c
	
deb_test.o: tests/test.c
	gcc -std=c99 -c -g -Wall -Werror -o debtest.o tests/test.c

main.o: main.c
	gcc -std=c99 -c -Wall -Werror -o main.o main.c
	
my_snprintf.o: my_snprintf.c
	gcc -std=c99 -c -Wall -Werror -o my_snprintf.o my_snprintf.c
	
test.o: tests/test.c
	gcc -std=c99 -c -Wall -Werror -o test.o tests/test.c
	
clean:
	rm *.o *.exe
