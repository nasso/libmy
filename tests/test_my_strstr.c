/*
** EPITECH PROJECT, 2019
** tests
** File description:
** Tests Day 4
*/

#include <criterion/criterion.h>
#include <my.h>

Test(my_strstr, find_substring)
{
    char    *str = "abcdef";
    char    *expected = strstr(str, "cd");
    char    *got = my_strstr(str, "cd");

    cr_assert_eq(got, expected);
}

Test(my_strstr, return_null_when_not_found)
{
    char    *str = "abcdef";
    char    *expected = strstr(str, "Hello!");
    char    *got = my_strstr(str, "Hello!");

    cr_assert_eq(got, expected);
}
