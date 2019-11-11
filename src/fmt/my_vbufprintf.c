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
#include "converter.h"

static int do_directive(bufwriter_t *bw, char const **fmt, int n, va_list ap)
{
    int bytes_written = 0;
    my_fmt__converter_t *conv = my_fmt__converter_new(fmt);

    if (conv == NULL)
        return (0);
    bytes_written = my_fmt__converter_put(conv, bw, ap);
    my_fmt__converter_free(conv);
    return (bytes_written);
}

int my_vbufprintf(bufwriter_t *bw, char const *fmt, va_list ap)
{
    int bytes_written = 0;

    while (*fmt) {
        if (*fmt == '%') {
            fmt++;
            bytes_written += do_directive(bw, &fmt, bytes_written, ap);
        } else {
            bytes_written += bufwriter_putchar(bw, *fmt);
            fmt++;
        }
    }
    return (bytes_written);
}
