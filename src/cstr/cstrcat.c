/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Concatenates two strings.
*/

#include "cstr.h"

char *my_cstrcat(char *dest, const char *src)
{
    int len;
    int i;

    len = my_cstrlen(dest);
    for (i = 0; src[i] != '\0'; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return (dest);
}
