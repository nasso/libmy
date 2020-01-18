/*
** EPITECH PROJECT, 2019
** tests
** File description:
** Tests Day 4
*/

#include <criterion/criterion.h>
#include <string.h>
#include "cstr.h"

Test(my_cstrcapitalize, capitalize_string)
{
    char *str = strdup("hey, how are you? 42WORds forty-two; fifty-one");
    char *expected = "Hey, How Are You? 42words Forty-Two; Fifty-One";

    my_cstrcapitalize(str);
    cr_assert_str_eq(str, expected);
}
