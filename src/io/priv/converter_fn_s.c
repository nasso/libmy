/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Conversion functions for %s and %S
*/

#include <stddef.h>
#include <stdarg.h>
#include "my.h"
#include "cstr.h"
#include "stream/bufwriter.h"
#include "fmt/priv/converter.h"

static int put_non_printable(bufwriter_t *bw, char c)
{
    int bytes_written = 0;

    bytes_written += bw ? bufwriter_putchar(bw, '\\') : 1;
    bytes_written += bw ? bufwriter_putchar(bw, '0' + (c / 0100 % 010)) : 1;
    bytes_written += bw ? bufwriter_putchar(bw, '0' + (c / 010 % 010)) : 1;
    bytes_written += bw ? bufwriter_putchar(bw, '0' + (c / 01 % 010)) : 1;
    return (bytes_written);
}

static int put_string(bufwriter_t *bw, my_fmt__converter_t *cv, char const *str,
    int n)
{
    int bytes_written = 0;
    char cv_spec = cv->conversion_specifier;

    if (cv_spec != 'S')
        return (bw == NULL ? n : bufwriter_write(bw, str, n));
    for (int i = 0; i < n; i++) {
        if (str[i] < 32 || str[i] >= 127)
            bytes_written += put_non_printable(bw, str[i]);
        else
            bytes_written += bw == NULL ? 1 : bufwriter_putchar(bw, str[i]);
    }
    return (bytes_written);
}

int my_fmt__converter_fn_s(my_fmt__converter_t *cv, bufwriter_t *bw, va_list ap)
{
    int bytes_written = 0;
    char *str = va_arg(ap, char*);
    int n = cv->precision;
    int width = 0;

    if (n < 0)
        n = my_cstrlen(str);
    width = put_string(NULL, cv, str, n);
    if (cv->flags->leftpad)
        bytes_written += put_string(bw, cv, str, n);
    for (int i = 0; i < cv->field_width - width; i++)
        bytes_written += bufwriter_putchar(bw, ' ');
    if (!cv->flags->leftpad)
        bytes_written += put_string(bw, cv, str, n);
    return (bytes_written);
}
