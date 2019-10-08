/*
** EPITECH PROJECT, 2019
** my_str_islower
** File description:
** Returns 1 if the given string contains only lowercase letters.
*/

static int  islower(char c)
{
    return c >= 'a' && c <= 'z';
}

int     my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!islower(str[i]))
            return (0);
    return (1);
}
