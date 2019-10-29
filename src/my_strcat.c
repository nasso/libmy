/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Concatenates two strings.
*/

#include "my.h"

char    *my_strcat(char *dest, char const *src)
{
    int     len;
    int     i;

    len = my_strlen(dest);
    for (i = 0; src[i] != '\0'; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return (dest);
}
