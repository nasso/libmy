/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Conversion function for %%
*/

#include <stdarg.h>
#include "my.h"
#include "stream/bufwriter.h"
#include "my_fmt__converter.h"

int my_fmt__converter_fn_pc(my_fmt__converter_t *cv, bufwriter_t *bw,
    va_list ap)
{
    MY_UNUSED(cv);
    MY_UNUSED(ap);
    return (bufwriter_putchar(bw, '%'));
}
