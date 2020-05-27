##
## EPITECH PROJECT, 2020
## Alexandre Wagner - Victor Rouxel - Theo Le bonniec
## File description:
## Makefile serveur
##

D_SRC	=	./src/
D_INC	=	./include/
D_LIB	=	./../libs/myteams/

NAME	=	../myteams_server

SRC		=	$(D_SRC)main.c	\
			$(D_SRC)init.c \
			$(D_SRC)help.c \
			$(D_SRC)getnextline.c \
			$(D_SRC)strtowordarray.c \
			$(D_SRC)interpret.c \
			$(D_SRC)commands.c \
			$(D_SRC)users_cmd.c \
			$(D_SRC)user_cmd.c \
			$(D_SRC)connexion_cmd.c \
			$(D_SRC)tools.c \
			$(D_SRC)string_management.c \
			$(D_SRC)database_function.c \
			$(D_SRC)message_cmd.c \
			$(D_SRC)server.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -I$(D_INC) -I$(D_LIB) -g
LDFLAGS	+=	-L$(D_LIB) -lmyteams -luuid

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
