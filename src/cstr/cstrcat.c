/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Concatenates two strings.
*/

#include <stddef.h>
#include "cstr.h"

char *my_cstrcat(char *dest, const char *src)
{
    size_t len = my_cstrlen(dest);
    size_t i = 0;

    while (src[i] != '\0') {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}
