build: main.o
	gcc -std=c99 -pedantic -g -o app.exe main.o
	
run: build
	./app.exe in.txt
	
main.o: main.c
	gcc -std=c99 -c -pedantic -g -o main.o main.c

clean:
	rm *.o *.exe