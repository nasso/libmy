/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Formatter
*/

#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdarg.h>
#include "stream/bufwriter.h"

typedef struct {
    int alternate;
    int zero;
    int leftpad;
    int space;
    int plus;
} my_fmt__flags_t;

typedef struct {
    my_fmt__flags_t *flags;
    char conversion_specifier;
} my_fmt__converter_t;

typedef int (my_fmt__cv_fn_t)(my_fmt__converter_t*, bufwriter_t*, va_list);

typedef struct {
    char c;
    my_fmt__cv_fn_t *fn;
} my_fmt__cv_fn_pair_t;

my_fmt__converter_t *my_fmt__converter_new(char const**);
void my_fmt__converter_free(my_fmt__converter_t*);
int my_fmt__converter_put(my_fmt__converter_t*, bufwriter_t*, va_list);
int my_fmt__converter_fn_s(my_fmt__converter_t*, bufwriter_t*, va_list);
int my_fmt__converter_fn_d(my_fmt__converter_t*, bufwriter_t*, va_list);

#endif /* CONVERTER_H */
