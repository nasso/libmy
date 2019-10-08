/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Displays the characters of a string one-by-one.
*/

#include <my.h>

int my_putstr(char const *str)
{
    int     len = 0;

    while (str[len] != '\0')
        len++;
    return (write(1, &str, len));
}
