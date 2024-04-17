FLAGS= 			-Wall -Werror -Wextra -std=c11
CC = 			gcc
UNAME_S 		:= $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	TEST_CHECK_F= -lcheck -lsubunit -lm -lrt -lpthread
	OPEN_CMD = xdg-open

endif

ifeq ($(UNAME_S),Darwin)
	TEST_CHECK_F= $(shell pkg-config --cflags --libs check)
	OPEN_CMD = open

endif

all: clean string.a

string.a: string.o
	ar cr string.a string.o

test: clean
	$(CC) $(FLAGS) -o test test.c tests/test* string.c $(TEST_CHECK_F)
	./test

gcov_report: test
	$(CC) string.c test.c tests/test* $(TEST_CHECK_F) --coverage -o test_coverage
	./test_coverage
	lcov -c -d . --output-file test_coverage.info
	genhtml test_coverage.info --output-directory html_report
	$(OPEN_CMD) ./html_report/index.html
	
string.o:
	$(CC) $(FLAGS) -c string.c


clean:
	rm -rf *.a *.o *.out *.html *.css *.gcno *.gcov *.gcda test test_coverage test_coverage.info html_report
