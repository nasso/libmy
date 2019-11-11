/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Conversion functions for %d and %i
*/

#include <stddef.h>
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
    if (bw != NULL)
        bufwriter_putchar(bw, base[d < 0 ? -d : d]);
    return (bytes_written + 1);
}

static int put_nchr(bufwriter_t *bw, char c, int n)
{
    for (int i = 0; i < n; i++)
        bufwriter_putchar(bw, c);
    return (n);
}

int my_fmt__converter_fn_d(my_fmt__converter_t *cv, bufwriter_t *bw, va_list ap)
{
    int bytes_written = 0;
    int pad = 0;
    int nb = va_arg(ap, int);

    if (nb < 0) {
        bytes_written++;
        bufwriter_putchar(bw, '-');
    } else if (cv->flags->plus || cv->flags->space) {
        bytes_written++;
        bufwriter_putchar(bw, cv->flags->plus ? '+' : ' ');
    }
    pad = cv->field_width - bytes_written - put_digits(NULL, nb, "0123456789");
    if (!cv->flags->leftpad)
        put_nchr(bw, cv->flags->zero ? '0' : ' ', pad);
    bytes_written += put_digits(bw, nb, "0123456789");
    if (cv->flags->leftpad)
        put_nchr(bw, ' ', pad);
    return (bytes_written);
}
