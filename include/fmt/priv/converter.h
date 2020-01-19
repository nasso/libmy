/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Formatter
*/

#ifndef LIBMY_FMT_PRIV_CONVERTER_H
#define LIBMY_FMT_PRIV_CONVERTER_H

#include <stdarg.h>
#include "io/bufwriter.h"

#define BINARY_BASE "01"
#define OCTAL_BASE "01234567"
#define DECIMAL_BASE "0123456789"
#define UPPER_HEX_BASE "0123456789ABCDEF"
#define LOWER_HEX_BASE "0123456789abcdef"

typedef struct {
    int alternate;
    int zero;
    int leftpad;
    int space;
    int plus;
} my_fmt__flags_t;

typedef enum {
    MY_FMT__LEN_MOD_NONE,
    MY_FMT__LEN_MOD_HH,
    MY_FMT__LEN_MOD_H,
    MY_FMT__LEN_MOD_L,
    MY_FMT__LEN_MOD_LL,
    MY_FMT__LEN_MOD_Z,
    MY_FMT__LEN_MOD_J,
    MY_FMT__LEN_MOD_T,
    MY_FMT__LEN_MOD_PTR
} my_fmt__length_modifier_t;

typedef struct my_fmt__converter {
    my_fmt__flags_t *flags;
    int n;
    int field_width;
    int precision;
    my_fmt__length_modifier_t len_mod;
    char conversion_specifier;
    int (*cv_fn)(struct my_fmt__converter*, bufwriter_t*, va_list);
} my_fmt__converter_t;

typedef int (my_fmt__cv_fn_t)(my_fmt__converter_t*, bufwriter_t*, va_list);

static inline int put_nchr(bufwriter_t *bw, char c, int n)
{
    for (int i = 0; i < n; i++)
        bufwriter_putchar(bw, c);
    return (n);
}

my_fmt__converter_t *my_fmt__converter_new(char const**, va_list);
void my_fmt__converter_free(my_fmt__converter_t*);
my_fmt__cv_fn_t my_fmt__converter_fn_d;
my_fmt__cv_fn_t my_fmt__converter_fn_u;
my_fmt__cv_fn_t my_fmt__converter_fn_c;
my_fmt__cv_fn_t my_fmt__converter_fn_s;
my_fmt__cv_fn_t my_fmt__converter_fn_p;
my_fmt__cv_fn_t my_fmt__converter_fn_pc;

#endif /* LIBMY_FMT_PRIV_CONVERTER_H */