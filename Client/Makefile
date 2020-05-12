##
## EPITECH PROJECT, 2020
## Alexandre Wagner - Victor Rouxel - Theo Le bonniec
## File description:
## Makefile client
##

D_SRC	=	./src/
D_INC	=	./include/

NAME	=	../myteams_cli

SRC		=	$(D_SRC)main.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -I$(D_INC)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean	:	rm -f $(OBJ) $(CFLAGS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re