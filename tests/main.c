/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Some simple test binary for libmy
*/

#include <stdarg.h>
#include <stdio.h>
#include "my.h"

static void test_printf(char const *fmt, ...)
{
    va_list ap;
    va_list ap_copy;

    va_start(ap, fmt);
    va_copy(ap_copy, ap);
    printf("     printf:\t");
    vprintf(fmt, ap_copy);
    my_printf("  my_printf:\t");
    my_vfprintf(1, fmt, ap);
    va_end(ap);
    va_end(ap_copy);
}

int main(void)
{
    test_printf("Hello %.4s!!\n", "World");
    return (0);
}
