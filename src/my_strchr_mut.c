/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strchr, my_strrchr and my_strchrnul
*/

#include <stddef.h>
#include "my.h"

char *my_strchr_mut(char *str, char c)
{
    while (*str && *str != c)
        str++;
    return (*str == c ? str : NULL);
}

char *my_strrchr_mut(char *str, char c)
{
    char *last_occurence = NULL;

    while (*str) {
        if (*str == c)
            last_occurence = str;
        str++;
    }
    return (last_occurence);
}

char *my_strchrnul_mut(char *str, char c)
{
    while (*str && *str != c)
        str++;
    return (str);
}
