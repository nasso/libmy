/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** tests - formatting
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_printf, invalid_specifier)
{
    cr_assert_str_eq(my_format( "<%k>"),  "<%k>");
    cr_assert_str_eq(my_format( "<%31.5k>"),  "<%31.5k>");
    cr_assert_str_eq(my_format( "<%31.5k> %d", 42),  "<%31.5k> 42");
}

Test(my_printf, simple_no_args)
{
    char *str = my_format("Hello World!");

    cr_assert_str_eq(str, "Hello World!");
}

Test(my_printf, multiple)
{
    char *str = my_format("%s %s!", "Hello", "World");

    cr_assert_str_eq(str, "Hello World!");
}

Test(my_printf, simple_string)
{
    char *str = my_format("%s World!", "Hello");

    cr_assert_str_eq(str, "Hello World!");
}

Test(my_printf, simple_decimal)
{
    cr_assert_str_eq(my_format( "<%d>",  42),  "<42>");
    cr_assert_str_eq(my_format( "<%d>", -42), "<-42>");
    cr_assert_str_eq(my_format("<%+d>",  42), "<+42>");
    cr_assert_str_eq(my_format("<%+d>", -42), "<-42>");
    cr_assert_str_eq(my_format("<% d>",  42), "< 42>");
    cr_assert_str_eq(my_format("<% d>", -42), "<-42>");
}
