CC = gcc -Wall -Werror -Wextra -std=c11
OS := $(shell uname)

ifeq ($(OS),Linux)
	FLAGS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
	OPEN_CMD = xdg-open
else
	FLAGS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
	OPEN_CMD = open
endif

all: clean my_math.a test gcov_report

my_math.a:
	$(CC) -c my_math/my_math.c
	ar -crs my_math/my_math.a my_math.o
	
test: clean my_math.a
	$(CC) tests/test.c my_math/my_math.a $(FLAGS) -o test
	./test

gcov_report: clean
	$(CC) tests/test.c my_math/my_math.c $(FLAGS) -o test
	./test
	lcov -t "./test" -o report.info --no-external -c -d .
	genhtml -o report report.info
	$(OPEN_CMD) ./report/index.html
	rm -rf *.gcno *gcda *.gco

clean:
	rm -rf *.o my_math/my_math.a test *.gcno *gcda *.gcov gcov report report.info