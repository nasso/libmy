/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** IO utils
*/

#ifndef LIBMY_IO_H
#define LIBMY_IO_H

#include <stdarg.h>
#include "types.h"
#include "io/bufreader.h"
#include "io/filereader.h"
#include "io/bufwriter.h"
#include "io/filewriter.h"

int my_open(const char *pathname, int flags);
int my_close(int fd);
isize_t my_write(int fd, const void *buf, usize_t count);
isize_t my_read(int fd, void *buf, usize_t count);
int my_vbufprintf(bufwriter_t*, char const*, va_list);
int my_vfprintf(int fd, char const*, va_list);
int my_fprintf(int fd, char const*, ...);
int my_printf(char const*, ...);
int my_putchar(char c);
int my_putchar_err(char c);
int my_putcstr(char const *str);
int my_putcstr_err(char const *str);

#endif /* LIBMY_IO_H */
