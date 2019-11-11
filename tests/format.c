/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** tests - formatting
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_printf, simple_no_args)
{
    char *str = my_format("Hello World!");

    cr_assert_str_eq(str, "Hello World!");
}

Test(my_printf, simple_string)
{
    char *str = my_format("%s World!", "Hello");

    cr_assert_str_eq(str, "Hello World!");
}

Test(my_printf, multiple)
{
    char *str = my_format("%s %s!", "Hello", "World");

    cr_assert_str_eq(str, "Hello World!");
}

Test(my_printf, simple_decimal)
{
    char *str = my_format("<%d>", 42);

    cr_assert_str_eq(str, "<42>");
}
