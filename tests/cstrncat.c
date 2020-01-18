/*
** EPITECH PROJECT, 2019
** test_my_strcat
** File description:
** Test for my_strcat
*/

#include <criterion/criterion.h>
#include "my.h"
#include "cstr.h"

Test(my_cstrncat, concats_two_strings_n)
{
    char dest[16] = "Hello";

    for (int i = 5; i < 16; i++)
        dest[i] = 0;
    my_cstrncat(dest, ", World!", 7);
    cr_assert_str_eq(dest, "Hello, World");
}
