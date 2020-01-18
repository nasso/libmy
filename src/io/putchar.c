/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Implementation of my_putchar.
*/

#include <unistd.h>
#include "my.h"

int my_putchar(char c)
{
    return (write(1, &c, 1));
}

int my_putchar_err(char c)
{
    return (write(2, &c, 1));
}
