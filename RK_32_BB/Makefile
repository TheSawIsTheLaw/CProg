build: main.o
	gcc -std=c99 -Wall -Werror -pedantic -o app.exe main.o
	
run: build
	./app.exe in.txt
	
main.o: main.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o main.o main.c

clean:
	rm *.o *.exe
