/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** test_my_putnbr_base
*/

#include <criterion/criterion.h>
#include "my.h"

Test(my_putnbr_base, positive_numbers)
{
    char dest[128];

    for (int i = 0; i < 128; i++)
        dest[i] = 0;
    my_putnbr_base(123456, "0123456789", dest);
    cr_assert_str_eq(dest, "123456");
}
