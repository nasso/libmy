/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** memshow test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static const char *EXPECTED_OUTPUT =
    "00000000: 4865 6c6c 6f20 576f 726c 6421 2054 6869  Hello World! Thi\n"
    "00000010: 7320 6973 2061 2074 6573 7421 00         s is a test!.\n";

Test(my_memshow, string_dump, .init = cr_redirect_stdout, .timeout = 1.0)
{
    my_memshow("Hello World! This is a test!", 29);
    cr_assert_stdout_eq_str(EXPECTED_OUTPUT);
}
