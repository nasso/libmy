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
    int bytes_written = 0;
    char *str = va_arg(ap, char*);
    int n = cv->precision;

    if (n < 0)
        n = my_strlen(str);
    if (cv->flags->leftpad)
        bytes_written += bufwriter_write(bw, str, n);
    for (int i = 0; i < cv->field_width - n; i++)
        bytes_written += bufwriter_putchar(bw, ' ');
    if (!cv->flags->leftpad)
        bytes_written += bufwriter_write(bw, str, n);
    return (bytes_written);
}
