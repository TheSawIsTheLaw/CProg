test.exe: test.o free_students.o full_structs.o kill_adults.o kill_lower_four_marks.o print_info.o sort_by_key.o
	gcc -std=c99 -Wall -Werror -o test.exe test.o free_students.o full_structs.o kill_adults.o kill_lower_four_marks.o print_info.o sort_by_key.o

app.exe: main.o free_students.o full_structs.o kill_adults.o kill_lower_four_marks.o print_info.o sort_by_key.o
	gcc -std=c99 -Wall -Werror -o app.exe main.o free_students.o full_structs.o kill_adults.o kill_lower_four_marks.o print_info.o sort_by_key.o
	
main.o: main.c
	gcc -std=c99 -c -Wall -Werror -o main.o main.c
	
free_students.o: funcs/free_students.c
	gcc -std=c99 -c -Wall -Werror -o free_students.o funcs/free_students.c
	
full_structs.o: funcs/full_structs.c
	gcc -std=c99 -c -Wall -Werror -o full_structs.o funcs/full_structs.c
	
kill_adults.o: funcs/kill_adults.c
	gcc -std=c99 -c -Wall -Werror -o kill_adults.o funcs/kill_adults.c
	
kill_lower_four_marks.o: funcs/kill_lower_four_marks.c
	gcc -std=c99 -c -Wall -Werror -o kill_lower_four_marks.o funcs/kill_lower_four_marks.c
	
print_info.o: funcs/print_info.c
	gcc -std=c99 -c -Wall -Werror -o print_info.o funcs/print_info.c
	
sort_by_key.o: funcs/sort_by_key.c
	gcc -std=c99 -c -Wall -Werror -o sort_by_key.o funcs/sort_by_key.c
	
clean:
	rm *.o *.exe
