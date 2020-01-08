/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** strndup rewrite
*/

#include <stdlib.h>
#include "my.h"

char *my_strndup(const char *str, int n)
{
    char *cpy = malloc(sizeof(char) * (n + 1));

    if (cpy == NULL)
        return (NULL);
    my_strncpy(cpy, str, n);
    cpy[n] = '\0';
    return (cpy);
}
