/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** strdup rewrite
*/

#include "my.h"

char *my_strdup(const char *str)
{
    return (my_strndup(str, my_strlen(str)));
}
