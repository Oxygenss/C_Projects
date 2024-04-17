TARGET = s21_grep
CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11

$(TARGET) : main.o parse.o reader.o
	$(CC) main.o parse.o reader.o -o $(TARGET)

main.o :
	$(CC) $(FLAGS) -c main.c

reader.o :
	$(CC) $(FLAGS) -c reader.c

parse.o :
	$(CC) $(FLAGS) -c parse.c

clean :
	rm -rf $(TARGET) *.o