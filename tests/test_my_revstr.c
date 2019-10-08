/*
** EPITECH PROJECT, 2019
** tests
** File description:
** Tests Day 4
*/

#include <criterion/criterion.h>

char    *my_revstr(char*);

Test(my_revstr, reverse_string)
{
    char    *str = strdup("Hello World!");

    cr_assert_str_eq(my_revstr(str), "!dlroW olleH");
}
