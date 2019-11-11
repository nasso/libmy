/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Parses an integer.
*/

struct proc_state {
    int sign;
    int val;
    int found_digit;
};

static int process_char(struct proc_state *s, char c)
{
    if (c >= '0' && c <= '9') {
        s->found_digit = 1;
        s->val *= 10;
        s->val += (c - '0') * (s->sign);
        if (s->val != 0 && (s->sign < 0) != (s->val < 0)) {
            s->val = 0;
            return (0);
        }
    } else if (!s->found_digit && c == '-')
        s->sign = -s->sign;
    else
        return (!s->found_digit && c == '+');
    return (1);
}

int my_getnbr(char const *str)
{
    int i = 0;
    struct proc_state state;

    state.sign = 1;
    state.val = 0;
    state.found_digit = 0;
    while (process_char(&state, str[i]))
        i++;
    return (state.val);
}
