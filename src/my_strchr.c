/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strchr, my_strrchr and my_strchrnul
*/

#include <stddef.h>
#include "my.h"

char const *my_strchr(char const *str, char c)
{
    while (*str && *str != c)
        str++;
    return (*str == c ? str : NULL);
}

char const *my_strrchr(char const *str, char c)
{
    char const *last_occurence = NULL;

    while (*str) {
        if (*str == c)
            last_occurence = str;
        str++;
    }
    return (last_occurence);
}

char const *my_strchrnul(char const *str, char c)
{
    while (*str && *str != c)
        str++;
    return (str);
}
