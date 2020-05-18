##
## EPITECH PROJECT, 2020
## Alexandre Wagner - Victor Rouxel - Theo Le bonniec
## File description:
## Makefile client
##

D_SRC	=	./src/
D_INC	=	./include/
D_LIB	=	./../libs/myteams/

NAME	=	../myteams_cli

SRC		=	$(D_SRC)main.c \
			$(D_SRC)getnextline.c \
			$(D_SRC)help.c \
			$(D_SRC)utils_uuid.c \
			$(D_SRC)init.c \
			$(D_SRC)client.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -I$(D_INC) -I$(D_LIB)
LDFLAGS	+=	-L$(D_LIB) -lmyteams -luuid

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean	:
			rm -rf $(OBJ)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
