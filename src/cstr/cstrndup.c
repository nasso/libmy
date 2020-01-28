/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** strndup rewrite
*/

#include <stdlib.h>
#include "my/my.h"
#include "my/cstr.h"

char *my_cstrndup(const char *str, size_t n)
{
    char *cpy = NULL;

    if (str == NULL)
        return (NULL);
    cpy = my_calloc(n + 1, sizeof(char));
    if (cpy == NULL)
        return (NULL);
    my_cstrncpy(cpy, str, n);
    return (cpy);
}
