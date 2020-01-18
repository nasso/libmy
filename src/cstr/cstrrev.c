/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Reverses a string.
*/

#include <stddef.h>
#include "cstr.h"

static void swap_chars(char *a, char *b)
{
    char tmp = *a;

    *a = *b;
    *b = tmp;
}

char *my_cstrrev(char *str)
{
    size_t len = my_cstrlen(str);
    size_t half_len = len / 2 + (len % 2);

    for (size_t i = 0; i < half_len; i++)
        swap_chars(&str[i], &str[len - i - 1]);
    return (str);
}
