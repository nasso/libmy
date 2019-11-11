/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Conversion functions for %s
*/

#include <stdarg.h>
#include "my.h"
#include "stream/bufwriter.h"
#include "my_fmt__converter.h"

int my_fmt__converter_fn_s(my_fmt__converter_t *cv, bufwriter_t *bw, va_list ap)
{
    char *str = va_arg(ap, char*);

    return (bufwriter_write(bw, str, my_strlen(str)));
}
