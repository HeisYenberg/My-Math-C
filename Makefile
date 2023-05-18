CC = gcc -Wall -Werror -Wextra -std=c11
OS := $(shell uname)

ifeq ($(OS),Linux)
	FLAGS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
	OPEN_CMD = xdg-open
else
	FLAGS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
	OPEN_CMD = open
endif

all: clean s21_math.a test gcov_report

s21_math.a:
	$(CC) -c s21_math/s21*.c
	ar -crs s21_math/s21_math.a s21_*.o
	
test: clean s21_math.a
	$(CC) test.c s21_math/s21_math.a $(FLAGS) -o test
	./test

gcov_report: clean
	$(CC) test.c s21_math/s21*.c $(FLAGS) -o test
	./test
	lcov -t "./test" -o report.info --no-external -c -d .
	genhtml -o report report.info
	$(OPEN_CMD) ./report/index.html
	rm -rf *.gcno *gcda *.gco

clean:
	rm -rf *.o s21_math/s21_math.a test *.gcno *gcda *.gcov gcov report report.info

clang:
	clang-format -style=Google -n *.c *.h