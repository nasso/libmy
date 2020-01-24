/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Tests Day 4
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "my/cstr.h"

Test(my_cstr_isalpha, return_one_when_alpha)
{
    char *str = "abcdef";

    cr_assert(my_cstr_isalpha(str));
}

Test(my_cstr_isalpha, return_zero_when_not_alpha)
{
    char *str = "abc def";

    cr_assert_not(my_cstr_isalpha(str));
}

Test(my_cstr_isalpha, return_one_when_empty)
{
    char *str = "";

    cr_assert(my_cstr_isalpha(str));
}
