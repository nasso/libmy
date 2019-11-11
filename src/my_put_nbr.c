/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** Prints the integer given as argument.
*/

#include "my.h"

static int print_int_part(int nb)
{
    int     written = 0;
    int     d = nb % 10;

    if (nb / 10)
        written += print_int_part(nb / 10);
    my_putchar('0' + (d < 0 ? -d : d));
    return (written + 1);
}

int my_put_nbr(int nb)
{
    if (!nb) {
        my_putchar('0');
        return (1);
    } else if (nb < 0)
        my_putchar('-');
    return ((nb < 0) + print_int_part(nb));
}
