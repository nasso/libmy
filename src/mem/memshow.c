/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Prints a memory dump.
*/

#include <unistd.h>
#include "my.h"

static const char PRINTABLE_CHARS_START = 32;

static isize_t putline_row(const char *str, usize_t n)
{
    isize_t written = 0;
    usize_t i = 0;

    while (i < 16 && i < n) {
        written += my_printf("%02lx", (u64_t) str[i]);
        if (i % 2)
            written += my_putchar(' ');
        i++;
    }
    while (i < 16) {
        written += write(1, "   ", 2 + i % 2);
        i++;
    }
    return (written);
}

static isize_t putline(const char *str, usize_t n)
{
    isize_t written = 0;

    for (usize_t i = 0; i < 16 && i < n; i++)
        written += my_putchar(str[i] >= PRINTABLE_CHARS_START ? str[i] : '.');
    return (written);
}

isize_t my_memshow(const void *ptr, usize_t size)
{
    const char *str = (const char*) ptr;
    isize_t written = 0;

    for (usize_t row = 0; row < size; row += 16) {
        written += my_printf("%08lx: ", (u64_t) row);
        written += putline_row(&str[row], size - row);
        written += my_putchar(' ');
        written += putline(&str[row], size - row);
        written += my_putchar('\n');
    }
    return (written);
}
