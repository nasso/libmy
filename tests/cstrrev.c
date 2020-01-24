/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Tests Day 4
*/

#include <criterion/criterion.h>
#include <string.h>
#include "my/cstr.h"

Test(my_cstrrev, reverse_string)
{
    char *str = strdup("Hello World!");

    cr_assert_str_eq(my_cstrrev(str), "!dlroW olleH");
}
