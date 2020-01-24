/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Test for my_strcat
*/

#include <criterion/criterion.h>
#include "my/my.h"
#include "my/cstr.h"

Test(my_cstrcat, concats_two_strings)
{
    char dest[16] = "Hello";

    for (int i = 5; i < 16; i++)
        dest[i] = 0;
    my_cstrcat(dest, ", World!");
    cr_assert_str_eq(dest, "Hello, World!");
}
