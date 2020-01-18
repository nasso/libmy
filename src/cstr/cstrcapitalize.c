/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Capitalizes the first word of every word.
*/

#include <stddef.h>
#include <stdbool.h>
#include "cstr.h"

static const char LOWER_TO_UPPER = 'A' - 'a';

static bool islower(char c)
{
    return (c >= 'a' && c <= 'z');
}

static bool isalpha(char c)
{
    bool val = 0;

    val |= islower(c);
    val |= c >= 'A' && c <= 'Z';
    return (val);
}

static bool isalphanum(char c)
{
    int val = 0;

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

char *my_cstrcapitalize(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        if (isalpha(str[i]))
            str[i] = change_case(str[i], i == 0 || !isalphanum(str[i - 1]));
    return (str);
}
