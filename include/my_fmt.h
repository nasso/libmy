/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Formatting helpers
*/

#ifndef MY_FMT_H
#define MY_FMT_H

#include <stdarg.h>
#include "stream/bufwriter.h"

int my__vbufprintf(bufwriter_t*, char const*, va_list);
int my_vfprintf(int fd, char const*, va_list);
int my_fprintf(int fd, char const*, ...);
int my_printf(char const*, ...);

#endif /* MY_FMT_H */
