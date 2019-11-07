/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** tests - printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_no_args, .init = redirect_all_stdout)
{
    my_printf(1, "Hello World!\n");
    cr_assert_stdout_eq_str("Hello World!\n");
}

Test(my_printf, simple_string, .init = redirect_all_stdout)
{
    char *str = "World";

    my_printf(1, "Hello %s!\n", str);
    cr_assert_stdout_eq_str("Hello World!\n");
}
