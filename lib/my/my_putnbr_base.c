/*
** EPITECH PROJECT, 2019
** my_putnbr_base
** File description:
** Writes a number with the given base.
*/

#include "my.h"

static void strputchar(char *dest, char c)
{
    int     len = 0;

    while (dest[len])
        len++;
    dest[len] = c;
    dest[len + 1] = '\0';
}

static void put_sign(int nbr, char *dest)
{
    if (nbr < 0)
        strputchar(dest, '-');
}

static int  put_digits(long nbr, char const *base, int base_num, char *dest)
{
    int     written_chars = 0;
    int     digit;

    digit = nbr % base_num;
    nbr /= base_num;
    if (nbr)
        written_chars += put_digits(nbr, base, base_num, dest);
    strputchar(dest, base[digit]);
    return (written_chars + 1);
}

int     my_putnbr_base(int nbr, char const *base, char *dest)
{
    int     base_num = 0;
    long    bignbr;

    bignbr = (long) nbr;
    while (base[base_num])
        base_num++;
    if (base_num < 2)
        return (0);
    if (nbr == 0) {
        strputchar(dest, base[0]);
        return (1);
    }
    put_sign(nbr, dest);
    bignbr = bignbr < 0 ? -bignbr : bignbr;
    return (put_digits(bignbr, base, base_num, dest));
}
