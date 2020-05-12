/*
** EPITECH PROJECT, 2020
** teams server
** File description:
** help
*/

#include <stdio.h>

void display_help(char *nameprog)
{
    printf("USAGE: %s port\n\n", nameprog);
    printf("\tport is the port number on which the server socket listens.\n");
}