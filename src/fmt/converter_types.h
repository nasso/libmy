/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Type definitions for conversions
*/

#ifndef CONVERTER_TYPES_H_
#define CONVERTER_TYPES_H_

#include <stdarg.h>
#include "stream/bufwriter.h"

typedef struct fmt_flags {
    int alternate;
    int zero;
    int leftpad;
    int space;
    int plus;
} fmt_flags_t;

typedef struct fmt_converter {
    fmt_flags_t *flags;
} fmt_converter_t;

typedef int (fmt_conv_fn_t)(fmt_converter_t*, bufwriter_t*, va_list);

typedef struct fmt_conv_fn_pair {
    char c;
    fmt_conv_fn_t *fn;
} fmt_conv_fn_pair_t;

#endif /* CONVERTER_TYPES_H_ */
