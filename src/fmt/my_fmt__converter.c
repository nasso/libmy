/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Formatter
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "stream/bufwriter.h"
#include "my_fmt__converter.h"

void my_fmt__converter_free(my_fmt__converter_t *conv)
{
    free(conv->flags);
    free(conv);
}
