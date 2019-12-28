build: main.o
	gcc -std=c99 -Wall -pedantic -o app.exe main.o
	
run: build
	./app.exe
	
main.o: main.c
	gcc -std=c99 -c -Wall -pedantic -o main.o main.c

clean:
	rm *.o *.exe
