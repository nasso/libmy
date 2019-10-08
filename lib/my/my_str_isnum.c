/*
** EPITECH PROJECT, 2019
** my_str_isnum
** File description:
** Returns 1 if the given string contains only digits.
*/

static int  isdigit(char c)
{
    return c >= '0' && c <= '9';
}

int     my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!isdigit(str[i]))
            return (0);
    return (1);
}
