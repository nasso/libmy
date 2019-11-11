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
#include "converter.h"

static const my_fmt__cv_fn_pair_t CONV_FUNCS_TABLE[] = {
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

my_fmt__converter_t *my_fmt__converter_new(char const **fmt)
{
    my_fmt__converter_t *cv = malloc(sizeof(my_fmt__converter_t));

    if (cv == NULL)
        return (NULL);
    cv->flags = get_flags(fmt);
    if (cv->flags == NULL) {
        free(cv);
        return (NULL);
    }
    cv->conversion_specifier = *((*fmt)++);
    return (cv);
}

void my_fmt__converter_free(my_fmt__converter_t *conv)
{
    free(conv->flags);
    free(conv);
}

int my_fmt__converter_put(my_fmt__converter_t *cv, bufwriter_t *bw, va_list ap)
{
    static int count = sizeof(CONV_FUNCS_TABLE) / sizeof(my_fmt__cv_fn_pair_t);

    for (int i = 0; i < count; i++)
        if (CONV_FUNCS_TABLE[i].c == cv->conversion_specifier)
            return (CONV_FUNCS_TABLE[i].fn(cv, bw, ap));
    return (0);
}
