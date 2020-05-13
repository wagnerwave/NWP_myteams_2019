/*
** EPITECH PROJECT, 2020
** teams server
** File description:
** struct of cmd client
*/

#include <unistd.h>
#include "server.h"
#include "logging_server.h"

const cmd_t cmd[] = {
    {"/help", NULL, {&help}, "show help"},
    {NULL, NULL, NULL, NULL}
};