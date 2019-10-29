/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** Implementation of strncat.
*/

#include "my.h"

char    *my_strncat(char *dest, char const *src, int nb)
{
    int     len;
    int     i;

    len = my_strlen(dest);
    for (i = 0; src[i] != '\0' && i < nb; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return (dest);
}
