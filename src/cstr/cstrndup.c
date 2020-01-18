/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** strndup rewrite
*/

#include <stdlib.h>
#include "my.h"
#include "cstr.h"

char *my_cstrndup(const char *str, size_t n)
{
    char *cpy = my_malloc(sizeof(char) * (n + 1));

    if (cpy == NULL)
        return (NULL);
    my_cstrncpy(cpy, str, n);
    cpy[n] = '\0';
    return (cpy);
}
