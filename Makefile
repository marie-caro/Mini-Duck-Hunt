##
## EPITECH PROJECT, 2023
## MUL_my_hunter_
## File description:
## Makefile
##

##

SRC =	src/my_hunter.c \
		src/mouse.c\
		src/duck.c\
		src/window.c\
		src/help.c\
		src/ctor.c\
		src/ctor_start.c\
		src/ctor_pause.c\
		src/ctor_mouse.c\
		src/ctor_menu.c\
		src/main.c\
		src/mouse2.c\
		src/ctor_door.c\

OBJ = $(SRC:.c=.o)

NAME =	libmy.a

SNAME =	my_hunter

LDFLAGS = -L lib/my/ -lmy

CPPFLAGS = -I include/

CFLAGS = -Wall -Werror -Wextra

CSFMLFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	$(NAME) $(SNAME)

$(NAME):
	$(MAKE) -C lib/my/

$(SNAME): $(OBJ)
	$(CC) -g3 -o $(SNAME) $(SRC) $(LDFLAGS) -I./include  $(CSFMLFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C lib/my/
	$(RM) lib/libmy.a lib/my/libmy.a
	clear

re: fclean all

.PHONY:	all clean fclean re
