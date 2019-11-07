/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include "stream/stream.h"
#include "my.h"

int my__buf_printf(bufwriter_t *bw, char const *fmt, va_list ap)
{
    int bytes_written = 0;

    while (*fmt) {
        bufwriter_putchar(bw, *fmt);
        fmt++;
        bytes_written++;
    }
    return (bytes_written);
}
