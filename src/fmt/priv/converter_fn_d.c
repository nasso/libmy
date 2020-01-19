/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Conversion functions for %d and %i
*/

#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "my.h"
#include "cstr.h"
#include "fmt/priv/converter.h"

static int put_digits(bufwriter_t *bw, intmax_t nb, char const *base)
{
    const int base_len = my_cstrlen(base);
    int bytes_written = 0;
    int d = nb % base_len;

    if (nb / base_len)
        bytes_written += put_digits(bw, nb / base_len, base);
    if (bw != NULL)
        bufwriter_putchar(bw, base[d < 0 ? -d : d]);
    return (bytes_written + 1);
}

static int put_sign(my_fmt__converter_t *cv, bufwriter_t *bw, intmax_t nb)
{
    if (nb < 0)
        return (bufwriter_putchar(bw, '-'));
    if (cv->flags->plus || cv->flags->space)
        return (bufwriter_putchar(bw, cv->flags->plus ? '+' : ' '));
    return (0);
}

static intmax_t get_arg(my_fmt__converter_t *cv, va_list ap)
{
    switch (cv->len_mod) {
    case MY_FMT__LEN_MOD_HH:
        return ((intmax_t) ((char) va_arg(ap, int)));
    case MY_FMT__LEN_MOD_H:
        return ((intmax_t) ((short) va_arg(ap, int)));
    default:
    case MY_FMT__LEN_MOD_NONE:
        return ((intmax_t) va_arg(ap, int));
    case MY_FMT__LEN_MOD_L:
        return ((intmax_t) va_arg(ap, long int));
    case MY_FMT__LEN_MOD_LL:
        return ((intmax_t) va_arg(ap, long long int));
    case MY_FMT__LEN_MOD_Z:
        return ((intmax_t) va_arg(ap, size_t));
    case MY_FMT__LEN_MOD_J:
        return ((intmax_t) va_arg(ap, intmax_t));
    case MY_FMT__LEN_MOD_T:
        return ((intmax_t) va_arg(ap, ptrdiff_t));
    }
}

int my_fmt__converter_fn_d(my_fmt__converter_t *cv, bufwriter_t *bw, va_list ap)
{
    int bytes_written = 0;
    int pad = 0;
    int digit_count = 0;
    char padchar = cv->precision < 0 && cv->flags->zero ? '0' : ' ';
    intmax_t nb = get_arg(cv, ap);

    if (cv->precision == 0 && nb == 0)
        return (0);
    bytes_written += put_sign(cv, bw, nb);
    digit_count = put_digits(NULL, nb, DECIMAL_BASE);
    pad = cv->field_width - bytes_written - MY_MAX(digit_count, cv->precision);
    if (!cv->flags->leftpad)
        bytes_written += put_nchr(bw, padchar, pad);
    bytes_written += put_nchr(bw, '0', cv->precision - digit_count);
    bytes_written += put_digits(bw, nb, DECIMAL_BASE);
    if (cv->flags->leftpad)
        bytes_written += put_nchr(bw, ' ', pad);
    return (bytes_written);
}