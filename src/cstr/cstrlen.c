/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Returns the number of characters found in the string passed as parameter.
*/

#include <stddef.h>
#include "my/cstr.h"

size_t my_cstrlen(const char *str)
{
    size_t len = 0;

    if (str == NULL)
        return (0);
    while (str[len] != '\0')
        len++;
    return (len);
}
