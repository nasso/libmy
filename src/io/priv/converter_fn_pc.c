/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Conversion function for %%
*/

#include <stdarg.h>
#include "my.h"
#include "stream/bufwriter.h"
#include "fmt/priv/converter.h"

int my_fmt__converter_fn_pc(my_fmt__converter_t *cv, bufwriter_t *bw,
    va_list ap)
{
    (void)(cv);
    (void)(ap);
    return (bufwriter_putchar(bw, '%'));
}
