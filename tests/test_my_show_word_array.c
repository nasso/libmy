/*
** EPITECH PROJECT, 2019
** CPool_Day08_2019
** File description:
** my_show_word_array
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <my.h>

static void     redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_show_word_array, some_array)
{
    char *test_word_array[4] = {"uwu", "owo", "uwuwuuwuwuwuwuwuwuw", 0};

    redirect_all_stdout();
    my_show_word_array(test_word_array);
    cr_assert_stdout_eq_str("uwu\nowo\nuwuwuuwuwuwuwuwuwuw\n");
}
