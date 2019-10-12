/*
** EPITECH PROJECT, 2019
** my_putchar
** File description:
** Implementation of my_putchar.
*/

#include <unistd.h>

void     my_putchar(char c)
{
    write(1, &c, 1);
}

void    my_putchar_err(char c)
{
    write(2, &c, 1);
}
