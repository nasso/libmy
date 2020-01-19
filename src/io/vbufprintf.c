/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "my.h"
#include "io.h"
#include "fmt/priv/converter.h"

static int do_directive(bufwriter_t *bw, char const **fmt, va_list ap)
{
    int bytes_written = 0;
    char const *directive_start = *fmt;
    my_fmt__converter_t *conv = my_fmt__converter_new(fmt, ap);

    if (conv == NULL) {
        bytes_written = bufwriter_putchar(bw, '%');
        *fmt = directive_start;
    } else {
        bytes_written = conv->cv_fn(conv, bw, ap);
        my_fmt__converter_free(conv);
    }
    return (bytes_written);
}

static void flush_if(bufwriter_t *bw, int condition)
{
    if (condition)
        bufwriter_flush(bw);
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
            flush_if(bw, *fmt == '\n');
            fmt++;
        }
    }
    return (bytes_written);
}
