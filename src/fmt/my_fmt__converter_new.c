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

struct my_fmt__len_mod_pair {
    char const *str;
    my_fmt__length_modifier_t mod;
};

static const struct my_fmt__len_mod_pair LEN_MOD_TABLE[] = {
    {"hh", MY_FMT__LEN_MOD_HH},
    {"ll", MY_FMT__LEN_MOD_LL},
    {"h", MY_FMT__LEN_MOD_H},
    {"l", MY_FMT__LEN_MOD_L},
    {"z", MY_FMT__LEN_MOD_Z},
    {"j", MY_FMT__LEN_MOD_J},
    {"t", MY_FMT__LEN_MOD_T},
    {"", MY_FMT__LEN_MOD_NONE}
};

static const struct my_fmt__cv_fn_pair CONV_FUNCS_TABLE[] = {
    {'d', &my_fmt__converter_fn_d},
    {'i', &my_fmt__converter_fn_d},
    {'c', &my_fmt__converter_fn_c},
    {'s', &my_fmt__converter_fn_s},
    {'%', &my_fmt__converter_fn_pc},
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

static int read_int_opt(char const **fmt, va_list ap)
{
    int nb = 0;

    if (**fmt == '*') {
        (*fmt)++;
        nb = va_arg(ap, int);
    } else {
        while (**fmt >= '0' && **fmt <= '9') {
            nb *= 10;
            nb += **fmt - '0';
            (*fmt)++;
        }
    }
    return (nb);
}

static my_fmt__length_modifier_t get_len_mod(char const **fmt)
{
    int i = -1;
    char const *str = NULL;
    int strlen = 0;

    do {
        i++;
        str = LEN_MOD_TABLE[i].str;
        strlen = my_strlen(str);
    } while(my_strncmp(*fmt, str, strlen));
    (*fmt) += strlen;
    return (LEN_MOD_TABLE[i].mod);
}

my_fmt__converter_t *my_fmt__converter_new(char const **fmt, va_list ap)
{
    my_fmt__converter_t *cv = malloc(sizeof(my_fmt__converter_t));

    if (cv == NULL)
        return (NULL);
    cv->flags = get_flags(fmt);
    if (cv->flags == NULL) {
        free(cv);
        return (NULL);
    }
    cv->field_width = read_int_opt(fmt, ap);
    cv->flags->leftpad |= cv->field_width < 0;
    cv->field_width = cv->field_width < 0 ? -cv->field_width : cv->field_width;
    if (**fmt == '.') {
        (*fmt)++;
        cv->precision = read_int_opt(fmt, ap);
    } else
        cv->precision = -1;
    cv->len_mod = get_len_mod(fmt);
    cv->cv_fn = get_conversion_function(*((*fmt)++));
    return (cv);
}
