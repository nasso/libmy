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

    cr_assert_eq(my_cstr_indexof(str, 'H'), 6);
}

Test(my_cstr_indexof, does_not_contains_char)
{
    char *str = "abc def";

    cr_assert_eq(my_cstr_indexof(str, 'H'), -1);
}