/*
** EPITECH PROJECT, 2019
** tests
** File description:
** Tests Day 4
*/

#include <criterion/criterion.h>
#include <my.h>

Test(my_str_isprintable, return_one_when_printable)
{
    char *str = "ABC123";

    cr_assert(my_str_isprintable(str));
}

Test(my_str_isprintable, return_zero_when_not_printable)
{
    char *str = "ABC\n123";

    cr_assert_not(my_str_isprintable(str));
}

Test(my_str_isprintable, return_one_when_empty)
{
    char *str = "";

    cr_assert(my_str_isprintable(str));
}
