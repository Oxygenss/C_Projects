TARGET   = 	s21_cat
CC       =	gcc
FLAGS    = 	-Wall -Werror -Wextra -std=c11

$(TARGET) : main.o parse.o reader.o
	$(CC) main.o parse.o reader.o -o $(TARGET)

main.o : main.c
	$(CC) $(FLAGS) -c main.c

reader.o : reader.c
	$(CC) $(FLAGS) -c reader.c

parse.o : parse.c
	$(CC) $(FLAGS) -c parse.c

clean :
	rm -rf $(TARGET) *.o