/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** Implementation of strncat.
*/

#include <stddef.h>
#include "cstr.h"

char *my_cstrncat(char *dest, const char *src, size_t nb)
{
    size_t len = my_cstrlen(dest);
    size_t i = 0;

    while (src[i] != '\0' && i < nb) {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return (dest);
}
