/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strchr, my_strrchr and my_strchrnul
*/

#include <stddef.h>
#include "my.h"

char *my_cstrchr_mut(char *str, char c)
{
    while (*str && *str != c)
        str++;
    return (*str == c ? str : NULL);
}

char *my_cstrrchr_mut(char *str, char c)
{
    char *last_occurence = NULL;

    while (*str) {
        if (*str == c)
            last_occurence = str;
        str++;
    }
    return (last_occurence);
}

char *my_cstrchrnul_mut(char *str, char c)
{
    while (*str && *str != c)
        str++;
    return (str);
}
