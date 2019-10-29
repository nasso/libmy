/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** Displays the characters of a string one-by-one.
*/

#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
    int len = my_strlen(str);

    return (write(1, str, len));
}

int my_putstr_err(char const *str)
{
    int len = my_strlen(str);

    return (write(2, str, len));
}
