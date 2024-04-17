CC 				= 	gcc
CFLAGS 			= 	-Wall -Werror -Wextra -std=c11
VALGRIND_FLAGS  = 	--log-file="valgrind.txt" --tool=memcheck --leak-check=yes

UNAME_S     	= 	$(shell uname -s)

SRC_PROJECT = ${wildcard *.c}
SRC_TEST = ${wildcard tests/*.c}

OBJ_PROJECT = ${patsubst %.c,%.o,$(SRC_PROJECT)}
OBJ_TEST = ${patsubst tests/%.c,tests/%.o,$(SRC_TEST)}

ifeq ($(UNAME_S),Linux)
	TEST_CHECK_F= -lcheck -lsubunit -lm -lrt -lpthread
	OPEN_CMD = xdg-open

endif

ifeq ($(UNAME_S),Darwin)
	TEST_CHECK_F= -lcheck
	OPEN_CMD = open

endif

all: clean matrix.a test

matrix.a: $(OBJ_PROJECT)
	ar rcs matrix.a $(OBJ_PROJECT)

test: clean $(OBJ_PROJECT) $(OBJ_TEST)
	$(CC) $(OBJ_PROJECT) $(OBJ_TEST) $(TEST_CHECK_F) -o test
	./test

gcov_report: clean
	$(CC) $(CFLAGS) $(SRC_PROJECT) $(SRC_TEST) $(TEST_CHECK_F) --coverage -o test_coverage
	./test_coverage
	lcov -c -d . --output-file test_coverage.info
	genhtml test_coverage.info --output-directory html_report
	$(OPEN_CMD) ./html_report/index.html

valgrind: clean test
	valgrind $(VALGRIND_FLAGS) ./test
	grep -n "ERROR SUMMARY" valgrind.txt

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

tests/%.o: tests/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clang:
	clang-format -i *.c
	clang-format -i *.h
	clang-format -i tests/*.c
	clang-format -i tests/*.h

clang-check:
	clang-format -n *.c
	clang-format -n *.h
	clang-format -n tests/*.c
	clang-format -n tests/*.h

clean:
	rm -rf test
	rm -rf tests/*.o
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf html_report
	rm -rf valgrind.txt
	rm -rf test_coverage
