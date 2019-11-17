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
    char const *specifiers;
    my_fmt__cv_fn_t *fn;
};

struct my_fmt__len_mod_pair {
    char const *str;
    my_fmt__length_modifier_t mod;
};

static const struct my_fmt__len_mod_pair LEN_MOD_TABLE[8] = {
    {"hh", MY_FMT__LEN_MOD_HH},
    {"ll", MY_FMT__LEN_MOD_LL},
    {"h", MY_FMT__LEN_MOD_H},
    {"l", MY_FMT__LEN_MOD_L},
    {"z", MY_FMT__LEN_MOD_Z},
    {"j", MY_FMT__LEN_MOD_J},
    {"t", MY_FMT__LEN_MOD_T},
    {"", MY_FMT__LEN_MOD_NONE},
};

static const struct my_fmt__cv_fn_pair CONV_FUNCS_TABLE[6] = {
    {"di", &my_fmt__converter_fn_d},
    {"bouxX", &my_fmt__converter_fn_u},
    {"c", &my_fmt__converter_fn_c},
    {"Ss", &my_fmt__converter_fn_s},
    {"p", &my_fmt__converter_fn_p},
    {"%", &my_fmt__converter_fn_pc},
};

static int get_flags(my_fmt__converter_t *cv, char const **fmt)
{
    cv->flags = malloc(sizeof(my_fmt__flags_t));
    if (cv->flags == NULL)
        return (1);
    while (my_strchr("#0- +", **fmt))  {
        cv->flags->alternate |= **fmt == '#';
        cv->flags->zero |= **fmt == '0';
        cv->flags->leftpad |= **fmt == '-';
        cv->flags->space |= **fmt == ' ';
        cv->flags->plus |= **fmt == '+';
        (*fmt)++;
    }
    return (0);
}

static int get_conversion_function(my_fmt__converter_t *cv, char c)
{
    static const int sizeof_pair = sizeof(struct my_fmt__cv_fn_pair);
    static const int count = sizeof(CONV_FUNCS_TABLE) / sizeof_pair;
    char const *specifier_ptr = NULL;

    for (int i = 0; i < count; i++) {
        specifier_ptr = my_strchr(CONV_FUNCS_TABLE[i].specifiers, c);
        if (specifier_ptr) {
            cv->cv_fn = CONV_FUNCS_TABLE[i].fn;
            cv->conversion_specifier = *specifier_ptr;
            return (0);
        }
    }
    return (1);
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

static int get_len_mod(my_fmt__converter_t *cv, char const **fmt)
{
    int i = -1;
    char const *str = NULL;
    int strlen = 0;

    do {
        i++;
        str = LEN_MOD_TABLE[i].str;
        strlen = my_strlen(str);
    } while (my_strncmp(*fmt, str, strlen));
    (*fmt) += strlen;
    cv->len_mod = LEN_MOD_TABLE[i].mod;
    return (0);
}

my_fmt__converter_t *my_fmt__converter_new(char const **fmt, va_list ap)
{
    my_fmt__converter_t *cv = malloc(sizeof(my_fmt__converter_t));

    if (cv == NULL || get_flags(cv, fmt)) {
        my_fmt__converter_free(cv);
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
    if (get_len_mod(cv, fmt) || get_conversion_function(cv, *((*fmt)++))) {
        my_fmt__converter_free(cv);
        return (NULL);
    }
    return (cv);
}
