/*
** EPITECH PROJECT, 2019
** test_my_put_nbr
** File description:
** Test for my_put_nbr
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_put_nbr, positive_numbers)
{
    redirect_all_stdout();
    my_put_nbr(123456);
    cr_assert_stdout_eq_str("123456");
}

Test(my_put_nbr, negative_numbers)
{
    redirect_all_stdout();
    my_put_nbr(-123456);
    cr_assert_stdout_eq_str("-123456");
}

Test(my_put_nbr, zero)
{
    redirect_all_stdout();
    my_put_nbr(0);
    cr_assert_stdout_eq_str("0");
}
