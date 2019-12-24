app.exe: main.o list.o out.o mul.o
	gcc -std=c99 -Wall -Werror -o app.exe main.o list.o out.o mul.o
	
deb: main.o out.o
	gcc -std=c99 -Wall -Werror -g -o app.exe main.o out.o

main.o: main.c
	gcc -std=c99 -Wall -Werror -g -c -o main.o main.c
	
out.o: funcs/out.c
	gcc -std=c99 -Wall -Werror -g -c -o out.o funcs/out.c
	
mul.o: funcs/mul.c
	gcc -std=c99 -Wall -Werror -g -c -o mul.o funcs/mul.c
	
list.o: funcs/list.c
	gcc -std=c99 -Wall -Werror -g -c -o list.o funcs/list.c

clean:
	rm *.o *.exe
	
vg_clean:
	rm vgcore.*
