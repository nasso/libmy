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

typedef struct {
    int alternate;
    int zero;
    int leftpad;
    int space;
    int plus;
} my_fmt__flags_t;

typedef struct my_fmt__converter {
    my_fmt__flags_t *flags;
    int n;
    int field_width;
    int (*cv_fn)(struct my_fmt__converter*, bufwriter_t*, va_list);
} my_fmt__converter_t;

typedef int (my_fmt__cv_fn_t)(my_fmt__converter_t*, bufwriter_t*, va_list);

my_fmt__converter_t *my_fmt__converter_new(char const**, int, va_list);
void my_fmt__converter_free(my_fmt__converter_t*);
int my_fmt__converter_fn_s(my_fmt__converter_t*, bufwriter_t*, va_list);
int my_fmt__converter_fn_d(my_fmt__converter_t*, bufwriter_t*, va_list);

#endif /* MY_FMT__CONVERTER_H */
