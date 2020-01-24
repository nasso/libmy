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

Test(my_cstrstr, find_substring)
{
    char *str = "abcdef";
    char *expected = strstr(str, "cd");
    char *got = my_cstrstr(str, "cd");

    cr_assert_eq(got, expected);
}

Test(my_cstrstr, return_null_when_not_found)
{
    char *str = "abcdef";
    char *expected = strstr(str, "Hello!");
    char *got = my_cstrstr(str, "Hello!");

    cr_assert_eq(got, expected);
}
