/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** result type tests
*/

#include <string.h>
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

struct my_struct {
    i32_t a;
    const char *b;
    isize_t c;
};

static int my_struct_cmp(const struct my_struct *a, const struct my_struct *b)
{
    if (a->a != b->a || a->c != b->c)
        return (1);
    else if (a->b == b->b)
        return (0);
    return (a->b != NULL && b->b != NULL && !strcmp(a->b, b->b));
}

Test(result, scalars)
{
    RESULT(i32_t, char) ok = OK(42);
    RESULT(bool, const char*) err = ERR("something went wrong!");

    cr_assert(ok.is_ok);
    cr_assert_eq(ok.u.ok, 42);
    cr_assert_not(err.is_ok);
    cr_assert_str_eq(err.u.err, "something went wrong!");
}

Test(result, compound_types)
{
    const char *str = "baa";
    struct my_struct expect = {17, str, -5};
    struct my_struct expect2 = {0};
    RESULT(struct my_struct, void*) ok = OK(.a = 17, .b = str, .c = -5);
    RESULT(struct my_struct, void*) ok2 = OK({0});
    RESULT(struct my_struct, void*) err = ERR(NULL);
    RESULT(void*, struct my_struct) err2 = ERR(.a = 17, .b = str, .c = -5);
    RESULT(void*, struct my_struct) err3 = ERR({0});

    cr_assert(ok.is_ok);
    cr_assert(ok2.is_ok);
    cr_assert_not(err.is_ok);
    cr_assert_not(err2.is_ok);
    cr_assert_not(err3.is_ok);
    cr_assert_not(my_struct_cmp(&expect, &ok.u.ok));
    cr_assert_not(my_struct_cmp(&expect2, &ok2.u.ok));
    cr_assert_null(err.u.err);
    cr_assert_not(my_struct_cmp(&expect, &err2.u.err));
    cr_assert_not(my_struct_cmp(&expect2, &err3.u.err));
}
