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

static int put_sign(my_fmt__converter_t *cv, bufwriter_t *bw, int nb)
{
    if (nb < 0)
        return (bufwriter_putchar(bw, '-'));
    if (cv->flags->plus || cv->flags->space)
        return (bufwriter_putchar(bw, cv->flags->plus ? '+' : ' '));
    return (0);
}

int my_fmt__converter_fn_d(my_fmt__converter_t *cv, bufwriter_t *bw, va_list ap)
{
    int bytes_written = 0;
    int pad = 0;
    int digit_count = 0;
    int nb = va_arg(ap, int);

    if (cv->precision == 0 && nb == 0)
        return (0);
    bytes_written += put_sign(cv, bw, nb);
    digit_count = put_digits(NULL, nb, "0123456789");
    pad = cv->field_width - bytes_written - MY_MAX(digit_count, cv->precision);
    if (!cv->flags->leftpad)
        put_nchr(bw, cv->flags->zero ? '0' : ' ', pad);
    put_nchr(bw, '0', cv->precision - digit_count);
    bytes_written += put_digits(bw, nb, "0123456789");
    if (cv->flags->leftpad)
        put_nchr(bw, ' ', pad);
    return (bytes_written);
}
