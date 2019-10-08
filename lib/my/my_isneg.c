/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** Displays N if the given integer is negative, P otherwise.
*/

#include <my.h>

int     my_isneg(int n)
{
    my_putchar(n < 0 ? 'N' : 'P');
    return (0);
}
