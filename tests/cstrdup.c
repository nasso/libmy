/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** strdup and strndup tests
*/

#include <criterion/criterion.h>
#include "my/cstr.h"

Test(my_cstrdup, empty_string)
{
    cr_assert_str_eq(my_cstrdup(""), "");
}

Test(my_cstrdup, non_empty_string)
{
    cr_assert_str_eq(my_cstrdup("baaa"), "baaa");
}

Test(my_cstrndup, empty_string)
{
    cr_assert_str_eq(my_cstrndup("baaa", 0), "");
}

Test(my_cstrndup, non_empty_string)
{
    cr_assert_str_eq(my_cstrndup("baaa", 2), "ba");
}
