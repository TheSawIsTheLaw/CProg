test.exe: app.exe test.o free.o make.o print.o del_to_sq.o add_rows.o add_cols.o comp_mat.o copy_mat.o
	gcc -std=c99 -Wall -Werror -o test.exe test.o free.o make.o print.o del_to_sq.o add_rows.o add_cols.o comp_mat.o copy_mat.o

app.exe: main.o free.o make.o print.o del_to_sq.o add_rows.o add_cols.o comp_mat.o copy_mat.o
	gcc -std=c99 -Wall -Werror -o app.exe main.o free.o make.o print.o del_to_sq.o add_rows.o add_cols.o comp_mat.o copy_mat.o

main.o: main.c
	gcc -std=c99 -c -Wall -Werror -o main.o main.c
	
free.o: funcs/free_mat.c
	gcc -std=c99 -c -Wall -Werror -o free.o funcs/free_mat.c
	
make.o: funcs/make_mat.c
	gcc -std=c99 -c -Wall -Werror -o make.o funcs/make_mat.c
	
print.o: funcs/print_mat.c
	gcc -std=c99 -c -Wall -Werror -o print.o funcs/print_mat.c
	
del_to_sq.o: funcs/del_to_sq.c
	gcc -std=c99 -c -Wall -Werror -o del_to_sq.o funcs/del_to_sq.c

add_rows.o: funcs/add_rows.c
	gcc -std=c99 -c -Wall -Werror -o add_rows.o funcs/add_rows.c
	
add_cols.o: funcs/add_cols.c
	gcc -std=c99 -c -Wall -Werror -o add_cols.o funcs/add_cols.c
	
comp_mat.o: funcs/comp_mat.c
	gcc -std=c99 -c -Wall -Werror -o comp_mat.o funcs/comp_mat.c
	
copy_mat.o: funcs/copy_mat.c
	gcc -std=c99 -c -Wall -Werror -o copy_mat.o funcs/copy_mat.c

test.o: tests/test.c
	gcc -std=c99 -c -Wall -Werror -o test.o tests/test.c
	
clean:
	rm *.o *.exe
