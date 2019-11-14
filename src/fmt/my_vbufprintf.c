/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "stream/stream.h"
#include "my.h"
#include "my_fmt__converter.h"

static int do_directive(bufwriter_t *bw, char const **fmt, va_list ap)
{
    int bytes_written = 0;
    char const *directive_start = *fmt;
    my_fmt__converter_t *conv = my_fmt__converter_new(fmt, ap);

    if (conv == NULL)
        return (0);
    if (conv->cv_fn == NULL) {
        bytes_written = bufwriter_putchar(bw, '%');
        *fmt = directive_start;
    } else
        bytes_written = conv->cv_fn(conv, bw, ap);
    my_fmt__converter_free(conv);
    return (bytes_written);
}

int my_vbufprintf(bufwriter_t *bw, char const *fmt, va_list ap)
{
    int bytes_written = 0;

    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            bytes_written += do_directive(bw, &fmt, ap);
        } else {
            bytes_written += bufwriter_putchar(bw, *fmt);
            fmt++;
        }
    }
    return (bytes_written);
}
