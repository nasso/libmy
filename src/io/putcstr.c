/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Displays the characters of a string one-by-one.
*/

#include <unistd.h>
#include "cstr.h"
#include "my.h"

int my_putcstr(const char *str)
{
    return (write(1, str, my_cstrlen(str)));
}

int my_putcstr_err(const char *str)
{
    return (write(2, str, my_cstrlen(str)));
}
