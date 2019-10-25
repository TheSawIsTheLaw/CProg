test.exe: test.o free.o make.o print.o del_to_sq.o add_rows.o add_cols.o comp_mat.o copy_mat.o go_to_zero.o AC_neg.o AC_pos.o AR_neg.o AR_pos.o CM_neg.o CM_pos.o DTS_neg.o DTS_pos_sqr.o DTS_pos_rows.o DTS_pos_cols.o FM_neg.o FM_pos.o GTZ_neg.o GTZ_pos.o PM_neg.o PM_pos.o
	gcc -std=c99 -Wall -Werror -o test.exe test.o free.o make.o print.o del_to_sq.o add_rows.o add_cols.o comp_mat.o copy_mat.o go_to_zero.o AC_neg.o AC_pos.o AR_neg.o AR_pos.o CM_neg.o CM_pos.o DTS_neg.o DTS_pos_sqr.o DTS_pos_rows.o DTS_pos_cols.o FM_neg.o FM_pos.o GTZ_neg.o GTZ_pos.o PM_neg.o PM_pos.o

app.exe: main.o free.o make.o print.o del_to_sq.o add_rows.o add_cols.o comp_mat.o copy_mat.o go_to_zero.o
	gcc -std=c99 -Wall -Werror -o app.exe main.o free.o make.o print.o del_to_sq.o add_rows.o add_cols.o comp_mat.o copy_mat.o go_to_zero.o

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

go_to_zero.o: funcs/go_to_zero.c
	gcc -std=c99 -c -Wall -Werror -o go_to_zero.o funcs/go_to_zero.c

test.o: tests/test.c
	gcc -std=c99 -c -Wall -Werror -o test.o tests/test.c
	
AC_pos.o: tests/positive/AC_pos_data.c
	gcc -std=c99 -c -Wall -Werror -o AC_pos.o tests/positive/AC_pos_data.c
	
AC_neg.o: tests/negative/AC_neg_data.c
	gcc -std=c99 -c -Wall -Werror -o AC_neg.o tests/negative/AC_neg_data.c

AR_pos.o: tests/positive/AR_pos_data.c
	gcc -std=c99 -c -Wall -Werror -o AR_pos.o tests/positive/AR_pos_data.c

AR_neg.o: tests/negative/AR_neg_data.c
	gcc -std=c99 -c -Wall -Werror -o AR_neg.o tests/negative/AR_neg_data.c

CM_pos.o: tests/positive/CM_pos_data.c
	gcc -std=c99 -c -Wall -Werror -o CM_pos.o tests/positive/CM_pos_data.c
	
CM_neg.o: tests/negative/CM_neg_data.c
	gcc -std=c99 -c -Wall -Werror -o CM_neg.o tests/negative/CM_neg_data.c
	
DTS_pos_sqr.o: tests/positive/DTS_pos_sqr.c
	gcc -std=c99 -c -Wall -Werror -o DTS_pos_sqr.o tests/positive/DTS_pos_sqr.c
	
DTS_pos_rows.o: tests/positive/DTS_pos_rows.c
	gcc -std=c99 -c -Wall -Werror -o DTS_pos_rows.o tests/positive/DTS_pos_rows.c
	
DTS_pos_cols.o: tests/positive/DTS_pos_cols.c
	gcc -std=c99 -c -Wall -Werror -o DTS_pos_cols.o tests/positive/DTS_pos_cols.c

DTS_neg.o: tests/negative/DTS_neg_data.c
	gcc -std=c99 -c -Wall -Werror -o DTS_neg.o tests/negative/DTS_neg_data.c

FM_pos.o: tests/positive/FM_pos_data.c
	gcc -std=c99 -c -Wall -Werror -o FM_pos.o tests/positive/FM_pos_data.c

FM_neg.o: tests/negative/FM_neg_data.c
	gcc -std=c99 -c -Wall -Werror -o FM_neg.o tests/negative/FM_neg_data.c

GTZ_pos.o: tests/positive/GTZ_pos_data.c
	gcc -std=c99 -c -Wall -Werror -o GTZ_pos.o tests/positive/GTZ_pos_data.c

GTZ_neg.o: tests/negative/GTZ_neg_data.c
	gcc -std=c99 -c -Wall -Werror -o GTZ_neg.o tests/negative/GTZ_neg_data.c

PM_pos.o: tests/positive/PM_pos_data.c
	gcc -std=c99 -c -Wall -Werror -o PM_pos.o tests/positive/PM_pos_data.c

PM_neg.o: tests/negative/PM_neg_data.c
	gcc -std=c99 -c -Wall -Werror -o PM_neg.o tests/negative/PM_neg_data.c

clean:
	rm *.o *.exe
