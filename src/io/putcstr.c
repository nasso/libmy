/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Displays the characters of a string one-by-one.
*/

#include <unistd.h>
#include "cstr.h"
#include "io.h"

int my_putcstr(const char *str)
{
    int len = my_cstrlen(str);

    return (write(1, str, len));
}

int my_putcstr_err(const char *str)
{
    int len = my_cstrlen(str);

    return (write(2, str, len));
}
