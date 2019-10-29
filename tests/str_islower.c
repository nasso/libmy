/*
** EPITECH PROJECT, 2019
** tests
** File description:
** Tests Day 4
*/

#include <criterion/criterion.h>
#include <my.h>

Test(my_str_islower, return_one_when_lower)
{
    char *str = "abcdef";

    cr_assert(my_str_islower(str));
}

Test(my_str_islower, return_zero_when_not_lower)
{
    char *str = "abc def";

    cr_assert_not(my_str_islower(str));
}

Test(my_str_islower, return_one_when_empty)
{
    char *str = "";

    cr_assert(my_str_islower(str));
}
