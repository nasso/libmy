/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Test for getnbr_base
*/

#include <criterion/criterion.h>
#include "my/cstr.h"

Test(my_cstr_getnbr_base, positive_values)
{
    cr_assert_eq(my_cstr_getnbr_base("42", "0123456789"), 42);
    cr_assert_eq(my_cstr_getnbr_base("0", "0123456789"), 0);
    cr_assert_eq(my_cstr_getnbr_base("2147483647", "0123456789"), 2147483647);
}

Test(my_cstr_getnbr_base, negative_values)
{
    cr_assert_eq(my_cstr_getnbr_base("-42", "0123456789"), -42);
    cr_assert_eq(my_cstr_getnbr_base("---42", "0123456789"), -42);
    cr_assert_eq(my_cstr_getnbr_base("---+---+-42", "0123456789"), -42);
    cr_assert_eq(my_cstr_getnbr_base("-0", "0123456789"), 0);
    cr_assert_eq(my_cstr_getnbr_base("-2147483648", "0123456789"), -2147483648);
}

Test(my_cstr_getnbr_base, junk_values)
{
    cr_assert_eq(my_cstr_getnbr_base("abc", "0123456789"), 0);
    cr_assert_eq(my_cstr_getnbr_base("42gae", "0123456789"), 42);
    cr_assert_eq(my_cstr_getnbr_base("--01s5-601gr", "0123456789"), 1);
}

Test(my_cstr_getnbr_base, other_bases)
{
    cr_assert_eq(my_cstr_getnbr_base("abc", "abc"), 5);
    cr_assert_eq(my_cstr_getnbr_base("E621", "0123456789ABCDEF"), 0xE621);
}
