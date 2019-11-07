/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Conversion utils
*/

#ifndef CONVERTER_H_
#define CONVERTER_H_

#include "stream/bufwriter.h"
#include "converter_types.h"
#include "converter_funcs.h"

static const fmt_conv_fn_pair_t CONV_FUNCS_TABLE[] = {
    {'s', &fmt_converter_fn_s},
};

static int contains(char const *str, char c)
{
    while (*str != '\0')
        if (*str == c)
            return (1);
        else
            str++;
    return (0);
}

static fmt_converter_t *fmt_converter_new(void)
{
    fmt_converter_t *cv = malloc(sizeof(fmt_converter_t));

    if (cv == NULL)
        return (NULL);
    cv->flags = malloc(sizeof(fmt_flags_t));
    if (cv == NULL) {
        free(cv);
        return (NULL);
    }
    cv->flags->alternate = 0;
    cv->flags->zero = 0;
    cv->flags->leftpad = 0;
    cv->flags->space = 0;
    cv->flags->plus = 0;
    return (cv);
}

static void fmt_converter_free(fmt_converter_t *conv)
{
    free(conv->flags);
    free(conv);
}

static void fmt_converter_get_flags(fmt_converter_t *conv, char const **fmt)
{
    while (**fmt) {
        conv->flags->alternate |= **fmt == '#';
        conv->flags->zero |= **fmt == '0';
        conv->flags->leftpad |= **fmt == '-';
        conv->flags->space |= **fmt == ' ';
        conv->flags->plus |= **fmt == '+';
        if (!contains("#0- +", **fmt))
            return;
        (*fmt)++;
    }
}

static int fmt_converter_convert(fmt_converter_t *conv, char const **fmt,
    bufwriter_t *bw, va_list ap)
{
    static int count = sizeof(CONV_FUNCS_TABLE) / sizeof(fmt_conv_fn_pair_t);

    for (int i = 0; i < count; i++) {
        if (CONV_FUNCS_TABLE[i].c == **fmt) {
            (*fmt)++;
            return (CONV_FUNCS_TABLE[i].fn(conv, bw, ap));
        }
    }
    return (0);
}

#endif /* CONVERTER_H_ */
