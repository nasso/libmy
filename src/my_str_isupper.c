/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** Returns 1 if the given string contains only uppercase letters.
*/

static int  isupper(char c)
{
    return c >= 'A' && c <= 'Z';
}

int     my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!isupper(str[i]))
            return (0);
    return (1);
}
