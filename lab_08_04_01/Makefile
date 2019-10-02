test.exe: app.exe test.o calc_u1.o calc_u2.o del.o expand.o insert.o invitation.o print.o
	gcc -std=c99 -Wall -Werror -pedantic -o test.exe test.o calc_u1.o calc_u2.o del.o insert.o print.o

app.exe: main.o calc_u1.o calc_u2.o del.o expand.o insert.o invitation.o print.o
	gcc -std=c99 -Wall -Werror -pedantic -o app.exe main.o calc_u1.o calc_u2.o del.o expand.o insert.o invitation.o print.o

main.o: main.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o main.o main.c   
	
calc_u1.o: calc_u1.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o calc_u1.o calc_u1.c  
	
calc_u2.o: calc_u2.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o calc_u2.o calc_u2.c 
	
del.o: del.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o del.o del.c   
	
expand.o: expand.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o expand.o expand.c  
	
insert.o: insert.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o insert.o insert.c  
	
invitation.o: invitation.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o invitation.o invitation.c  
	
print.o: print.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o print.o print.c   

test.o: test.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o test.o test.c 
	
clean:
	rm *.o *.exe