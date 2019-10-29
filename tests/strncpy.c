/*
** EPITECH PROJECT, 2019
** tests
** File description:
** Tests Day 4
*/

#include <criterion/criterion.h>
#include <my.h>

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    char    dest[6] = {0};

    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}

Test(my_strncpy, copy_string_in_empty_array)
{
    char    my_dest[6] = {0};
    char    dest[6] = {0};

    my_strncpy(my_dest, "Hello", 6);
    strncpy(dest, "Hello", 6);
    cr_assert_str_eq(my_dest, dest);
}

Test(my_strncpy, append_zeroes)
{
    char    *expect = "abc\0\0";
    char    *dst = malloc(sizeof(char) * 6);

    for (int i = 0; i < 6; i++)
        dst[i] = 1;
    my_strncpy(dst, "abc", 6);
    for (int i = 0; i < 6; i++)
        cr_assert_eq(dst[i], expect[i]);
}
