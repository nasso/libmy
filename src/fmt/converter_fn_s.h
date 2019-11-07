/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Conversion functions for %s
*/

#ifndef CONVERTER_FUNC_S_H_
#define CONVERTER_FUNC_S_H_

#include <stdarg.h>
#include "my.h"
#include "stream/bufwriter.h"
#include "converter_types.h"

static int fmt_converter_fn_s(fmt_converter_t *cv, bufwriter_t *bw, va_list ap)
{
    char *str = va_arg(ap, char*);

    return (bufwriter_write(bw, str, my_strlen(str)));
}

#endif /* CONVERTER_FUNC_STR_H_ */
