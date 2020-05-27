/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "logging_client.h"
#include "client.h"

void error_unauthorized_func(void)
{
    client_error_unauthorized();
}

void error_already_exist_func(void)
{
    client_error_already_exist();
}

