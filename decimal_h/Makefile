CC	= gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -pedantic -g
GCOV_FLAGS    = -fprofile-arcs -ftest-coverage -fPIC
VALGRIND_FLAGS  = --log-file="valgrind.txt" --track-origins=yes --trace-children=yes --leak-check=full --leak-resolution=med #--track-fds=yes --show-leak-kinds=all
CHECK_FLAGS   = $(shell pkg-config --cflags --libs check)
UNAME_S     = $(shell uname -s)

LIBRARY = decimal.a
SRC_PROJECT    = $(wildcard converters/*.c arithmetics/*.c rounding/*.c comparison/*.c core/*.c binary/*.c iostream/*.c other_functions/*.c)
SRC_TEST    = $(wildcard tests/*.c)
OBJ_PROJECT    = arithmetics.o binary.o comparison.o converters.o core.o iostream.o other_functions.o
OBJ_TEST    = test_main.o


ifeq ($(UNAME_S),Linux)
	TEST_CHECK_F= -lcheck -lsubunit -lm -lrt -lpthread
	OPEN_CMD = xdg-open

endif

ifeq ($(UNAME_S),Darwin)
	TEST_CHECK_F= $(shell pkg-config --cflags --libs check)
	OPEN_CMD = open
endif



all: decimal.a 

$(LIBRARY): $(SRC_PROJECT)
	$(CC) $(CFLAGS) -c $(SRC_PROJECT)
	ar rc $(LIBRARY) $(OBJ_PROJECT)
	ranlib $(LIBRARY)

test: clean $(LIBRARY) $(OBJ_TEST)
	$(CC) $(CFLAGS) $(GCOV_FLAGS) $(OBJ_TEST) -o test $(LIBRARY) $(CHECK_FLAGS) $(TEST_CHECK_F)
	./test

gcov_report: clean $(OBJ_TEST)
	$(CC) $(CFLAGS) -o test $(OBJ_TEST) --coverage $(SRC_PROJECT) $(CHECK_FLAGS) -lm
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	$(OPEN_CMD) report/index.html

$(OBJ_TEST):
	$(CC) -c $(SRC_TEST)

clean:
	rm -rf test
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcda
	rm -rf report
	rm -rf *.gcno
	rm -rf *.info
	rm -rf valgrind.txt

rebuild: clean test

.PHONY: all clean rebuild open clang valgrind docker

valgrind: rebuild
	valgrind $(VALGRIND_FLAGS) ./test
	grep -n "ERROR SUMMARY" valgrind.txt | grep -v "0 errors"


clang:
	clang-format -i arithmetics/*
	clang-format -i comparison/*
	clang-format -i converters/*
	clang-format -i core/*
	clang-format -i tests/*
	clang-format -i binary/*
	clang-format -i iostream/*
	clang-format -i other_functions/*
	clang-format -i decimal.h

clang-check:
	clang-format -n arithmetics/*
	clang-format -n comparison/*
	clang-format -n converters/*
	clang-format -n core/*
	clang-format -n tests/*
	clang-format -n binary/*
	clang-format -n iostream/*
	clang-format -n other_functions/*
	clang-format -n decimal.h
	
