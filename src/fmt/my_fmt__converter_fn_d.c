/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Conversion functions for %d and %i
*/

#include <stdarg.h>
#include "my.h"
#include "stream/bufwriter.h"
#include "my_fmt__converter.h"

static int put_digits(bufwriter_t *bw, long long int nb, char const *base)
{
    const int base_len = my_strlen(base);
    int bytes_written = 0;
    int d = nb % base_len;

    if (nb / base_len)
        bytes_written += put_digits(bw, nb / base_len, base);
    bufwriter_putchar(bw, base[d < 0 ? -d : d]);
    return (bytes_written + 1);
}

int my_fmt__converter_fn_d(my_fmt__converter_t *cv, bufwriter_t *bw, va_list ap)
{
    int bytes_written = 0;
    int nb = va_arg(ap, int);

    if (nb < 0) {
        bytes_written++;
        bufwriter_putchar(bw, '-');
    } else if (cv->flags->plus || cv->flags->space) {
        bytes_written++;
        bufwriter_putchar(bw, cv->flags->plus ? '+' : ' ');
    }
    bytes_written += put_digits(bw, nb, "0123456789");
    return (bytes_written);
}
