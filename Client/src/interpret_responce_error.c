/*
** EPITECH PROJECT, 2020
** my_teams client
** File description:
** interpertation of code responce byserver
*/

#include <string.h>
#include "../../libs/myteams/logging_client.h"
#include "../include/client.h"

void error_unauthorized_func(void)
{
    client_error_unauthorized();
}

void error_already_exist_func(void)
{
    client_error_already_exist();
}

