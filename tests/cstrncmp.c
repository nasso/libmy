/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Tests Day 4
*/

#include <criterion/criterion.h>
#include <string.h>
#include "my/my.h"
#include "my/cstr.h"

Test(my_cstrncmp, return_zero_when_equal)
{
    char    *str1 = "Hello World!";
    char    *str2 = "Hello World!";
    int     expected = strncmp(str1, str2, 4);
    int     got = my_cstrncmp(str1, str2, 4);

    cr_assert_eq(got, expected);
}

Test(my_cstrncmp, return_non_zero_when_not_equal)
{
    char    *str1 = "Hello World!";
    char    *str2 = "Hello world!";
    int     expected;
    int     got;

    expected = strncmp(str1, str2, 4);
    got = my_cstrncmp(str1, str2, 4);
    cr_assert_eq(got, expected);
    expected = strncmp(str2, str1, 4);
    got = my_cstrncmp(str2, str1, 4);
    cr_assert_eq(got, expected);
}
