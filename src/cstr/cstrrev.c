/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** Reverses a string.
*/

#include "cstr.h"

static void swap_chars(char *a, char *b)
{
    char tmp = *a;

    *a = *b;
    *b = tmp;
}

char    *my_cstrrev(char *str)
{
    int len;
    int half_len;

    for (len = 0; str[len] != '\0'; len++) {}
    half_len = len / 2 + (len % 2);
    for (int i = 0; i < half_len; i++)
        swap_chars(&str[i], &str[len - i - 1]);
    return (str);
}
