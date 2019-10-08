/*
** EPITECH PROJECT, 2019
** my_str_isalpha
** File description:
** Returns 1 if the given string contains only alphabetic characters.
*/

static int  isalpha(char c)
{
    int     val = 0;

    val |= c >= 'a' && c <= 'z';
    val |= c >= 'A' && c <= 'Z';
    return (val);
}

int     my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!isalpha(str[i]))
            return (0);
    return (1);
}
