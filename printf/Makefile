CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
AR = ar rc

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(AR) $@ $^

clean : 
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all
