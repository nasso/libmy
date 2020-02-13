/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** cstrindeox
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "my/cstr.h"

Test(my_cstr_indexof, contains_char)
{
    char *str = "012345H7";
    opt_i32_t result = my_cstr_indexof(str, 'H');

    cr_assert(result.is_some);
    cr_assert_eq(result.v, 6);
}

Test(my_cstr_indexof, does_not_contains_char)
{
    char *str = "abc def";
    opt_i32_t result = my_cstr_indexof(str, 'H');

    cr_assert(result.is_some);
    cr_assert_eq(result.v, -1);
}