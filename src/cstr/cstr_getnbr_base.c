/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Reads a number with the given base.
*/

#include <stddef.h>
#include <stdbool.h>
#include "cstr.h"

struct proc_state {
    int sign;
    int val;
    bool found_digit;
};

struct base_def {
    size_t size;
    const char *digits;
};

static bool process_char(struct proc_state *s, char c, struct base_def *b)
{
    const char *digitptr = my_cstrchr(b->digits, c);

    if (!s->found_digit && (c == '-' || c == '+')) {
        s->sign = c == '-' ? -s->sign : s->sign;
        return (true);
    }
    if (digitptr != NULL) {
        s->found_digit = true;
        s->val *= b->size;
        s->val += (digitptr - b->digits) * (s->sign);
        if (s->val != 0 && (s->sign < 0) != (s->val < 0)) {
            s->val = 0;
            return (false);
        }
    }
    return (digitptr != NULL);
}

int my_cstr_getnbr_base(const char *str, const char *base)
{
    struct proc_state state = {1, 0, false};
    struct base_def b = {my_cstrlen(base), base};
    size_t i = 0;

    while (str[i] && process_char(&state, str[i], &b))
        i++;
    return (state.val);
}
