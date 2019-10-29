/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Test for my_compute_power_rec
*/

#include <criterion/criterion.h>
#include <math.h>
#include <my.h>

Test(my_compute_power_rec, positive_powers)
{
    int     expected;
    int     got;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            expected = (int) pow((double) i, (double) j);
            got = my_compute_power_rec(i, j);
            cr_assert_eq(expected, got, "Expected %d, got %d", expected, got);
        }
}

Test(my_compute_power_rec, negatives_return_zero)
{
    cr_assert_eq(0, my_compute_power_rec(1, -1));
    cr_assert_eq(0, my_compute_power_rec(0, -1));
    cr_assert_eq(0, my_compute_power_rec(-1, -1));
}
