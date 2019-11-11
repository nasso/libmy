/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** tests - formatting
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_format, invalid_specifier)
{
    cr_assert_str_eq(my_format( "<%k>"),  "<%k>");
    cr_assert_str_eq(my_format( "<%31.5k>"),  "<%31.5k>");
    cr_assert_str_eq(my_format( "<%31.5k> %d", 42),  "<%31.5k> 42");
}

Test(my_format, simple_no_args)
{
    char *str = my_format("Hello World!");

    cr_assert_str_eq(str, "Hello World!");
}

Test(my_format, multiple)
{
    char *str = my_format("%s %s!", "Hello", "World");

    cr_assert_str_eq(str, "Hello World!");
}

Test(my_format, simple_string)
{
    char *str = my_format("%s World!", "Hello");

    cr_assert_str_eq(str, "Hello World!");
}

Test(my_format, decimal_d)
{
    cr_assert_str_eq(my_format(   "%i",  42), "42");
    cr_assert_str_eq(my_format(   "%d",  42), "42");
    cr_assert_str_eq(my_format(   "%d", -42), "-42");
    cr_assert_str_eq(my_format(  "%+d",  42), "+42");
    cr_assert_str_eq(my_format(  "%+d", -42), "-42");
    cr_assert_str_eq(my_format(  "% d",  42), " 42");
    cr_assert_str_eq(my_format(  "% d", -42), "-42");
    cr_assert_str_eq(my_format(  "%5d",  42), "   42");
    cr_assert_str_eq(my_format( "%05d",  42), "00042");
    cr_assert_str_eq(my_format( "%-5d",  42), "42   ");
    cr_assert_str_eq(my_format( "%-5d",  42), "42   ");
    cr_assert_str_eq(my_format("%+05d",  42), "+0042");
    cr_assert_str_eq(my_format("%+-5d",  42), "+42  ");
    cr_assert_str_eq(my_format("% -5d",  42), " 42  ");
}
