##
## EPITECH PROJECT, 2020
## Alexandre Wagner - Victor Rouxel - Theo Le bonniec
## File description:
## Makefile serveur
##

D_SRC	=	./src/
D_INC	=	./include/

NAME	=	../myteams_server

SRC		=	$(D_SRC)main.c	\
			$(D_SRC)init.c \
			$(D_SRC)help.c \
			$(D_SRC)getnextline.c \
			$(D_SRC)strtowordarray.c \
			$(D_SRC)interpret.c \
			$(D_SRC)commands.c \
			$(D_SRC)info_cmd.c \
			$(D_SRC)connexion_cmd.c \
			$(D_SRC)server.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -I$(D_INC)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re