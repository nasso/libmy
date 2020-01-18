/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** Implementation of strncpy.
*/

#include <stddef.h>
#include "cstr.h"

char *my_cstrncpy(char *dest, const char *src, size_t n)
{
    size_t i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return (dest);
}
