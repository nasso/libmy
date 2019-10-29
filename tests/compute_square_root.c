/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_compute_square_root test
*/

#include <criterion/criterion.h>
#include <math.h>
#include <my.h>

Test(my_compute_square_root, perfect_squares)
{
    int     got;

    for (int i = 0; i < 300; i++) {
        got = my_compute_square_root(i * i);
        cr_assert_eq(i, got, "for n = %d; expected %d, got %d", i * i, i, got);
    }
}

Test(my_compute_square_root, perfect_squares_neg)
{
    int     got;

    for (int i = 0; i < 300; i++) {
        got = my_compute_square_root(-i * i);
        cr_assert_eq(0, got, "for n = %d; expected %d, got %d", -i * i, 0, got);
    }
}

Test(my_compute_square_root, positive_values)
{
    double  actual;
    int     expected;

    for (int i = 0; i < 300; i++) {
        actual = sqrt((double) i);
        expected = actual == (int) actual ? (int) actual : 0;
        cr_assert_eq(expected, my_compute_square_root(i), "for n = %d", -i * i);
    }
}

Test(my_compute_square_root, negative_values)
{
    for (int i = -300; i < 0; i++)
        cr_assert_eq(0, my_compute_square_root(i), "for n = %d", i);
}
