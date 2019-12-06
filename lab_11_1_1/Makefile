test.exe: test.o my_snprintf.o negative_d_buf_null.o negative_d_format_null.o negative_d_size.o positive_d_negative_num.o positive_d_normal.o positive_d_positive_num.o positive_d_text.o positive_d_zero.o
	gcc -std=c99 -Wall -Werror -o test.exe test.o my_snprintf.o negative_d_buf_null.o negative_d_format_null.o negative_d_size.o positive_d_negative_num.o positive_d_normal.o positive_d_positive_num.o positive_d_text.o positive_d_zero.o
	
testdeb: deb_test.o deb_my_snprintf.o
	gcc -std=c99 -Wall -Werror -g -o test.exe debtest.o deb_my_snprintf.o
	
deb_my_snprintf.o: my_snprintf.c
	gcc -std=c99 -c -g -Wall -Werror -o deb_my_snprintf.o my_snprintf.c
	
deb_test.o: tests/test.c
	gcc -std=c99 -c -g -Wall -Werror -o debtest.o tests/test.c

main.o: main.c
	gcc -std=c99 -c -Wall -Werror -o main.o main.c
	
my_snprintf.o: my_snprintf.c
	gcc -std=c99 -c -Wall -Werror -o my_snprintf.o my_snprintf.c
	
test.o: tests/test.c
	gcc -std=c99 -c -Wall -Werror -o test.o tests/test.c
	
negative_d_buf_null.o: tests/tests/negative_d_buf_null.c
	gcc -std=c99 -c -Wall -Werror -o negative_d_buf_null.o tests/tests/negative_d_buf_null.c
	
negative_d_format_null.o: tests/tests/negative_d_format_null.c
	gcc -std=c99 -c -Wall -Werror -o negative_d_format_null.o tests/tests/negative_d_format_null.c
	
negative_d_size.o: tests/tests/negative_d_size.c
	gcc -std=c99 -c -Wall -Werror -o negative_d_size.o tests/tests/negative_d_size.c
	
positive_d_negative_num.o: tests/tests/positive_d_negative_num.c
	gcc -std=c99 -c -Wall -Werror -o positive_d_negative_num.o tests/tests/positive_d_negative_num.c
	
positive_d_normal.o: tests/tests/positive_d_normal.c
	gcc -std=c99 -c -Wall -Werror -o positive_d_normal.o tests/tests/positive_d_normal.c
	
positive_d_positive_num.o: tests/tests/positive_d_positive_num.c
	gcc -std=c99 -c -Wall -Werror -o positive_d_positive_num.o tests/tests/positive_d_positive_num.c
	
positive_d_text.o: tests/tests/positive_d_text.c
	gcc -std=c99 -c -Wall -Werror -o positive_d_text.o tests/tests/positive_d_text.c
	
positive_d_zero.o: tests/tests/positive_d_zero.c
	gcc -std=c99 -c -Wall -Werror -o positive_d_zero.o tests/tests/positive_d_zero.c
	
clean:
	rm *.o *.exe
