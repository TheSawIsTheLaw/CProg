main.o: Funcs/main.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o main.o Funcs/main.c   
	
calc_u1.o: Funcs/calc_u1.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o calc_u1.o Funcs/calc_u1.c  
	
calc_u2.o: Funcs/calc_u2.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o calc_u2.o Funcs/calc_u2.c 
	
del.o: Funcs/del.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o del.o Funcs/del.c   
	
expand.o: Funcs/expand.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o expand.o Funcs/expand.c  
	
insert.o: Funcs/insert.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o insert.o Funcs/insert.c  
	
invitation.o: Funcs/invitation.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o invitation.o Funcs/invitation.c  
	
print.o: Funcs/print.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o print.o Funcs/print.c   
	
app: main.o calc_u1.o calc_u2.o del.o expand.o insert.o invitation.o print.o
	gcc -std=c99 -Wall -Werror -pedantic -o app main.o calc_u1.o calc_u2.o del.o expand.o insert.o invitation.o print.o

test.o: Test/test.c
	gcc -std=c99 -c -Wall -Werror -pedantic -o test.o Test/test.c 
	
test: test.o calc_u1.o calc_u2.o del.o expand.o insert.o invitation.o print.o
	gcc -std=c99 -Wall -Werror -pedantic -o test test.o calc_u1.o calc_u2.o del.o insert.o print.o
	
clean:
	rm *.o *.exe