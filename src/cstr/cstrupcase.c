/*
** EPITECH PROJECT, 2019
** my_strupcase
** File description:
** Makes the given string uppercase.
*/

#include "cstr.h"

static const char   LOWER_TO_UPPER_OFFSET = 'A' - 'a';

char    *my_cstrupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] += LOWER_TO_UPPER_OFFSET;
    return (str);
}
