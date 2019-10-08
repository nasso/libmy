/*
** EPITECH PROJECT, 2019
** test_my_strcat
** File description:
** Test for my_strcat
*/

#include <criterion/criterion.h>

char    *my_strncat(char*, char const*, int);

Test(my_strncat, concats_two_strings_n)
{
    char dest[16] = "Hello";

    for (int i = 5; i < 16; i++)
        dest[i] = 0;
    my_strncat(dest, ", World!", 7);
    cr_assert_str_eq(dest, "Hello, World");
}
