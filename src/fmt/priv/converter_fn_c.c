/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Conversion function for %%
*/

#include <stdarg.h>
#include "my.h"
#include "fmt/priv/converter.h"

int my_fmt__converter_fn_c(my_fmt__converter_t *cv, bufwriter_t *bw, va_list ap)
{
    int bytes_written = 0;
    unsigned char c = (unsigned char) va_arg(ap, int);

    if (cv->flags->leftpad)
        bytes_written += bufwriter_putchar(bw, c);
    for (int i = 0; i < cv->field_width - 1; i++)
        bytes_written += bufwriter_putchar(bw, ' ');
    if (!cv->flags->leftpad)
        bytes_written += bufwriter_putchar(bw, c);
    return (bytes_written);
}
