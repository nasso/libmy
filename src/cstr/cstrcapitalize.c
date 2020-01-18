/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** Capitalizes the first word of every word.
*/

#include "cstr.h"

static const char LOWER_TO_UPPER = 'A' - 'a';

static int islower(char c)
{
    return (c >= 'a' && c <= 'z');
}

static int isalpha(char c)
{
    int     val = 0;

    val |= islower(c);
    val |= c >= 'A' && c <= 'Z';
    return (val);
}

static int isalphanum(char c)
{
    int     val = 0;

    val |= islower(c);
    val |= isalpha(c);
    val |= c >= '0' && c <= '9';
    return (val);
}

static char change_case(char c, int upper)
{
    if (islower(c))
        return (c + upper * LOWER_TO_UPPER);
    return (c - !upper * LOWER_TO_UPPER);
}

char    *my_cstrcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (isalpha(str[i]))
            str[i] = change_case(str[i], i == 0 || !isalphanum(str[i - 1]));
    return (str);
}
