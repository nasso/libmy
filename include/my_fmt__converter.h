/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Formatter
*/

#ifndef MY_FMT__CONVERTER_H
#define MY_FMT__CONVERTER_H

#include <stdarg.h>
#include "stream/bufwriter.h"

#define DECIMAL_BASE "0123456789"

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
    MY_FMT__LEN_MOD_T
} my_fmt__length_modifier_t;

typedef struct my_fmt__converter {
    my_fmt__flags_t *flags;
    int n;
    int field_width;
    int precision;
    my_fmt__length_modifier_t len_mod;
    int (*cv_fn)(struct my_fmt__converter*, bufwriter_t*, va_list);
} my_fmt__converter_t;

typedef int (my_fmt__cv_fn_t)(my_fmt__converter_t*, bufwriter_t*, va_list);

my_fmt__converter_t *my_fmt__converter_new(char const**, va_list);
void my_fmt__converter_free(my_fmt__converter_t*);
int my_fmt__converter_fn_s(my_fmt__converter_t*, bufwriter_t*, va_list);
int my_fmt__converter_fn_d(my_fmt__converter_t*, bufwriter_t*, va_list);

#endif /* MY_FMT__CONVERTER_H */
