/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** strdup and strndup tests
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_strdup, empty_string)
{
    cr_assert_str_eq(my_strdup(""), "");
}

Test(my_strdup, non_empty_string)
{
    cr_assert_str_eq(my_strdup("baaa"), "baaa");
}

Test(my_strndup, empty_string)
{
    cr_assert_str_eq(my_strndup("baaa", 0), "");
}

Test(my_strndup, non_empty_string)
{
    cr_assert_str_eq(my_strndup("baaa", 2), "ba");
}
