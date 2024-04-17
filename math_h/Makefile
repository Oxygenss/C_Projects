CC = 			gcc
FLAGS = 		-Wall -Werror -Wextra -std=c11
UNAME_S 		:= $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	TEST_CHECK_F= -lcheck -lsubunit -lm -lrt -lpthread
	OPEN_CMD = xdg-open

endif

ifeq ($(UNAME_S),Darwin)
	TEST_CHECK_F= $(shell pkg-config --cflags --libs check)
	OPEN_CMD = open
	ADD_LIB =

endif

all: clean my_math.a test

my_math.a: my_math.o
	ar rcs my_math.a my_math.o

test: clean my_math.o tests.o
	$(CC) my_math.o tests.o $(TEST_CHECK_F) -o test

gcov_report:
	$(CC) my_math.c tests.c $(TEST_CHECK_F) --coverage -o test_coverage
	./test_coverage
	lcov -c -d . --output-file test_coverage.info
	genhtml test_coverage.info --output-directory html_report
	$(OPEN_CMD) ./html_report/index.html

my_math.o:
	$(CC) $(FLAGS) -c my_math.c

tests.o: 
	$(CC) $(FLAGS) -c tests.c

clean:
	rm -rf *.o *.a *.gcno *.gcda test test_coverage test_coverage.info html_report