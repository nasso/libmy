/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Tests Day 4
*/

#include <criterion/criterion.h>
#include <string.h>
#include "my/my.h"
#include "my/cstr.h"

Test(my_cstrncpy, copy_five_characters_in_empty_array)
{
    char    dest[6] = {0};

    my_cstrncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_cstrncpy, copy_string_in_empty_array)
{
    char    my_dest[6] = {0};
    char    dest[6] = {0};

    my_cstrncpy(my_dest, "Hello", 6);
    strncpy(dest, "Hello", 6);
    cr_assert_str_eq(my_dest, dest);
}

Test(my_cstrncpy, append_zeroes)
{
    char *expect = "abc\0\0";
    char dst[6];

    for (int i = 0; i < 6; i++)
        dst[i] = 1;
    my_cstrncpy(dst, "abc", 6);
    for (int i = 0; i < 6; i++)
        cr_assert_eq(dst[i], expect[i]);
}
