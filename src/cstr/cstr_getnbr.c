/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Parses an integer.
*/

#include "cstr.h"

int my_cstr_getnbr(const char *str)
{
    return (my_cstr_getnbr_base(str, "0123456789"));
}
