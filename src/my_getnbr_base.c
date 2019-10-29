/*
** EPITECH PROJECT, 2019
** my_getnbr_base
** File description:
** Reads a number with the given base.
*/

struct  proc_state {
    int     sign;
    int     val;
    int     found_digit;
};

struct  base_def {
    int             size;
    char const*     digits;
};

static int      index_of(char const *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (i);
    return (-1);
}

static int      process_char(struct proc_state *s, char c, struct base_def *b)
{
    int     digit;

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

int     my_getnbr_base(char const *str, char const *base)
{
    struct proc_state   state;
    struct base_def     b;

    state.sign = 1;
    state.val = 0;
    state.found_digit = 0;
    b.size = 0;
    b.digits = base;
    for (; base[b.size] != '\0'; b.size++) {}
    for (int i = 0; process_char(&state, str[i], &b); i++) {}
    return (state.val);
}
