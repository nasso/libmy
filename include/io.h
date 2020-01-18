/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** IO utils
*/

#ifndef LIBMY_IO_H
#define LIBMY_IO_H

#include <stdarg.h>
#include "stream/bufwriter.h"

int my_vbufprintf(bufwriter_t*, char const*, va_list);
int my_vfprintf(int fd, char const*, va_list);
int my_fprintf(int fd, char const*, ...);
int my_printf(char const*, ...);
int my_putchar(char c);
int my_putchar_err(char c);
int my_putcstr(char const *str);
int my_putcstr_err(char const *str);

#endif /* LIBMY_IO_H */
