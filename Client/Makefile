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
			$(D_SRC)strtowordarray.c \
			$(D_SRC)interpret_responce.c \
			$(D_SRC)client.c	\
			$(D_SRC)interpret_responce_error.c \
			$(D_SRC)interpret_responce_error_unknown.c \
			$(D_SRC)interpret_responce_event.c \
			$(D_SRC)interpret_responce_event2.c \
			$(D_SRC)interpret_responce_print.c \
			$(D_SRC)interpret_responce_print_channel.c \
			$(D_SRC)interpret_responce_print_team.c \
			$(D_SRC)interpret_responce_print_thread.c \
			$(D_SRC)interpret_responce_print_user.c	\
			$(D_SRC)interpret_command.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Wextra -I$(D_INC) -I$(D_LIB) -g
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
