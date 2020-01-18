/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** Reads a number with the given base.
*/

#include "cstr.h"

struct proc_state {
    int sign;
    int val;
    int found_digit;
};

struct base_def {
    int size;
    const char *digits;
};

static int index_of(const char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (i);
    return (-1);
}

static int process_char(struct proc_state *s, char c, struct base_def *b)
{
    int digit;

    if (!s->found_digit && (c == '-' || c == '+')) {
        s->sign = c == '-' ? -s->sign : s->sign;
        return (1);
    }
    digit = index_of(b->digits, c);
    if (digit >= 0) {
        s->found_digit = 1;
        s->val *= b->size;
        s->val += digit * (s->sign);
        if (s->val != 0 && (s->sign < 0) != (s->val < 0)) {
            s->val = 0;
            return (0);
        }
    }
    return (digit >= 0);
}

int my_getnbr_base(const char *str, const char *base)
{
    struct proc_state state;
    struct base_def b;

    state.sign = 1;
    state.val = 0;
    state.found_digit = 0;
    b.size = 0;
    b.digits = base;
    while (base[b.size] != '\0')
        b.size++;
    for (int i = 0; process_char(&state, str[i], &b); i++) {}
    return (state.val);
}
