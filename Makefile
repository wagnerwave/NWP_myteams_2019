##
## EPITECH PROJECT, 2020
## Alexandre Wagner - Victor Rouxel - Theo Le bonniec
## File description:
## teams makefile for client and serveur
##

SERVER	=	./Serv/
CLIENT	=	./Client/

all		:
			serv
			client

serv	:
			@make -C $(SERVER)

client	:
			@make -C $(CLIENT)

clean	:
			@make clean -C $(SERVER) clean
			@make clean -C $(CLIENT) clean
			@rm -rf ./myteams_server
			@rm -rf ./myteams_cli

fclean	:
			@make fclean -C $(SERVER)
			@make fclean -C $(CLIENT)
			@rm -rf ./myteams_server
			@rm -rf ./myteams_cli

re		:
			@make re -C $(SERVER)
			@make re -C $(CLIENT)

.PHONY	:	all clean fclean re serv client