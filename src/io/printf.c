/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_printf, my_fprintf
*/

#include <stdlib.h>
#include "my.h"
#include "io.h"

int my_vfprintf(int fd, char const *fmt, va_list ap)
{
    int bytes_written = 0;
    bufwriter_t *bw = filewriter_from(fd, 2048);

    if (bw == NULL)
        return (0);
    bytes_written = my_vbufprintf(bw, fmt, ap);
    bufwriter_free(bw);
    return (bytes_written);
}

int my_printf(char const *fmt, ...)
{
    va_list ap;
    int ret = 0;

    va_start(ap, fmt);
    ret = my_vfprintf(1, fmt, ap);
    va_end(ap);
    return (ret);
}

int my_fprintf(int fd, char const *fmt, ...)
{
    va_list ap;
    int ret = 0;

    va_start(ap, fmt);
    ret = my_vfprintf(fd, fmt, ap);
    va_end(ap);
    return (ret);
}
