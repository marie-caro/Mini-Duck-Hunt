##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## 1. copy the build library into lib/
## 2. copy the my.h into include
## implement the clean rule
##

SRC = 	my_putchar.c	\
	my_put_nbr.c	\
	my_putstr.c	\
	my_strcpy.c	\
	my_strcmp.c	\
	strdup.c\
	my_strlen.c\
	int_to_str.c

NAME = libmy.a

$(NAME):
	$(CC) -c $(SRC)
	ar rc $(NAME) *.o
	mkdir -p ../../include
	cp -r my.h ../../include
	cp -r $(NAME) ../libmy.a

clean:
	rm -f *.o

fclean: clean
