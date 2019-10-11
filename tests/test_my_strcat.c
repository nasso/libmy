/*
** EPITECH PROJECT, 2019
** test_my_strcat
** File description:
** Test for my_strcat
*/

#include <criterion/criterion.h>
#include <my.h>

Test(my_strcat, concats_two_strings)
{
    char dest[16] = "Hello";

    for (int i = 5; i < 16; i++)
        dest[i] = 0;
    my_strcat(dest, ", World!");
    cr_assert_str_eq(dest, "Hello, World!");
}
