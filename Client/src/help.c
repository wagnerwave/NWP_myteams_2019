/*
** EPITECH PROJECT, 2020
** teams client
** File description:
** help for client
*/

#include <stdlib.h>

void display_help(char *nameprog)
{
    printf("USAGE: %s ip port\n\t", nameprog);
    printf("ip\tis the server ip address on which the server socket listens");
    printf("\n\tport\tis the port number on which the server socket listens.");
    printf("\n");
}