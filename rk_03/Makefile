build: main.o del_ununiq.o find_two_mas.o full_mas.o full_struct.o lex_sort.o
	gcc -std=c99 -pedantic -g -o app.exe main.o del_ununiq.o find_two_mas.o full_mas.o full_struct.o lex_sort.o
	
run: build
	./app.exe in.txt
	
main.o: main.c
	gcc -std=c99 -c -pedantic -g -o main.o main.c
	
del_ununiq.o: del_ununiq.c
	gcc -std=c99 -c -pedantic -g -o del_ununiq.o del_ununiq.c
	
find_two_mas.o: find_two_mas.c
	gcc -std=c99 -c -pedantic -g -o find_two_mas.o find_two_mas.c
	
full_mas.o: full_mas.c
	gcc -std=c99 -c -pedantic -g -o full_mas.o full_mas.c
		
full_struct.o: full_struct.c
	gcc -std=c99 -c -pedantic -g -o full_struct.o full_struct.c

lex_sort.o: lex_sort.c
	gcc -std=c99 -c -pedantic -g -o lex_sort.o lex_sort.c

clean:
	rm *.o *.exe