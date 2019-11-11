/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Formatter
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "stream/bufwriter.h"
#include "my_fmt__converter.h"

struct my_fmt__cv_fn_pair {
    char c;
    my_fmt__cv_fn_t *fn;
};

static const struct my_fmt__cv_fn_pair CONV_FUNCS_TABLE[] = {
    {'d', &my_fmt__converter_fn_d},
    {'i', &my_fmt__converter_fn_d},
    {'s', &my_fmt__converter_fn_s},
};

static my_fmt__flags_t *get_flags(char const **fmt)
{
    my_fmt__flags_t *flags = malloc(sizeof(my_fmt__flags_t));

    if (flags == NULL)
        return (NULL);
    while (**fmt) {
        flags->alternate |= **fmt == '#';
        flags->zero |= **fmt == '0';
        flags->leftpad |= **fmt == '-';
        flags->space |= **fmt == ' ';
        flags->plus |= **fmt == '+';
        if (my_strchr("#0- +", **fmt) == NULL)
            return (flags);
        (*fmt)++;
    }
    return (flags);
}

static my_fmt__cv_fn_t *get_conversion_function(char c)
{
    static const int sizeof_pair = sizeof(struct my_fmt__cv_fn_pair);
    static const int count = sizeof(CONV_FUNCS_TABLE) / sizeof_pair;

    for (int i = 0; i < count; i++)
        if (CONV_FUNCS_TABLE[i].c == c)
            return (CONV_FUNCS_TABLE[i].fn);
    return (NULL);
}

my_fmt__converter_t *my_fmt__converter_new(char const **fmt, int n)
{
    my_fmt__converter_t *cv = malloc(sizeof(my_fmt__converter_t));

    if (cv == NULL)
        return (NULL);
    cv->flags = get_flags(fmt);
    if (cv->flags == NULL) {
        free(cv);
        return (NULL);
    }
    cv->n = n;
    cv->cv_fn = get_conversion_function(*((*fmt)++));
    return (cv);
}
