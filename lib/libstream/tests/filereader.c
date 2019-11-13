/*
** EPITECH PROJECT, 2019
** libstream
** File description:
** Tests for filereader
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "stream.h"

static void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

static void my_putchar(char c)
{
    write(1, &c, 1);
}

Test(filereader, empty_file, .init = redirect_all_stdout)
{
    bufreader_t *reader = filereader_open("tests/empty.txt", 2048);
    char c = 0;

    while (!reader->ended) {
        c = bufreader_getchar(reader);
        if (c != 0)
            my_putchar(c);
    }
    my_putchar('\n');
    cr_assert_stdout_eq_str("\n");
    bufreader_free(reader);
}

Test(filereader, small_file, .init = redirect_all_stdout)
{
    bufreader_t *reader = filereader_open("tests/small.txt", 2048);
    char c = 0;

    while (!reader->ended) {
        c = bufreader_getchar(reader);
        if (c != 0)
            my_putchar(c);
    }
    cr_assert_stdout_eq_str("Hello World!\nI like goats!!!\n\n");
    bufreader_free(reader);
}
