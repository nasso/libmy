/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** option tests
*/

#include <criterion/criterion.h>
#include "my/my.h"

struct my_struct {
    i32_t a;
    i32_t b;
};

Test(option, scalars)
{
    OPTION(i32_t) some_int = SOME(5);
    OPTION(i32_t) none_int = NONE;

    cr_assert(some_int.is_some);
    cr_assert_eq(some_int.v, 5);
    cr_assert_not(none_int.is_some);
}

Test(option, compound_types)
{
    OPTION(struct my_struct) some_struct = SOME(.a = 15, .b = 35 + 8);
    OPTION(struct my_struct) some_struct2 = SOME(-53, 18);
    OPTION(struct my_struct) none_struct = NONE;

    cr_assert(some_struct.is_some);
    cr_assert_eq(some_struct.v.a, 15);
    cr_assert_eq(some_struct.v.b, 35 + 8);
    cr_assert(some_struct2.is_some);
    cr_assert_eq(some_struct2.v.a, -53);
    cr_assert_eq(some_struct2.v.b, 18);
    cr_assert_not(none_struct.is_some);
}
